#include "http_server.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "shttpd/shttpd.h"
#include "manager/ConfigManager.h"
#include "utils/Log.h"
#include "shttpd/multipart_reader.h"
#include "os/MountMonitor.h"

namespace srv {

std::string read_file(const std::string &file) {
  std::ifstream ifs(file.c_str(), std::ios::binary | std::ios::in);
  if (!ifs.is_open()) {
    return "";
  }
  std::stringstream ss;
  ss << ifs.rdbuf();
  ifs.close();
  std::string content(ss.str());
  return content;
}

//  Content-Type: multipart/form-data; boundary=----WebKitFormBoundary4MxyDJzPWCVPEFFc
std::string get_boundary(shttpd_arg *arg) {
  int len = 0;
  const char* boundary = shttpd_get_boundary(arg, &len);
  if (boundary) {
    return std::string(boundary, len);
  }
  return "";
}

/*
 * This callback function is attached to the "/" and "/abc.html" URIs,
 * thus is acting as "index.html" file. It shows a bunch of links
 * to other URIs, and allows to change the value of program's
 * internal variable. The pointer to that variable is passed to the
 * callback function as arg->user_data.
 */
static void
show_index(struct shttpd_arg *arg)
{
//  int   *p = arg->user_data;  /* integer passed to us */
  char    wifi_name[128] = {0};
  char    wifi_password[128] = {0};
  const char  *request_method, *query_string;

  request_method = shttpd_get_env(arg, "REQUEST_METHOD");
//  request_uri = shttpd_get_env(arg, "REQUEST_URI");
  query_string = shttpd_get_env(arg, "QUERY_STRING");

  /* Change the value of integer variable */
  if (!strcmp(request_method, "POST")) {
    /* If not all data is POSTed, wait for the rest */
    if (arg->flags & SHTTPD_MORE_POST_DATA)
      return;

    shttpd_get_var("wifi_name", arg->in.buf, arg->in.len,
        wifi_name, sizeof(wifi_name));
    shttpd_get_var("wifi_password", arg->in.buf, arg->in.len,
        wifi_password, sizeof(wifi_password));
//    mTextViewSetupNamePtr->setText(wifi_name);
//    mTextViewSetupPasswordPtr->setText(wifi_password);
//    StoragePreferences::putString(PROP_WIFI_NAME, wifi_name);
//    StoragePreferences::putString(PROP_WIFI_PASSWORD, wifi_password);
  } else if (query_string != NULL) { // GET
//    (void) shttpd_get_var("name1", query_string,
//        strlen(query_string), wifi_name, sizeof(wifi_name));
  }

  shttpd_printf(arg, "%s", "HTTP/1.1 200 OK\r\n");
  shttpd_printf(arg, "%s", "Content-Type: text/html\r\n\r\n");

//  std::string html(read_file(CONFIGMANAGER->getResFilePath("index.html")));
  std::string html =
		  "<!DOCTYPE html>\r\n"
		  "<html lang=\"zh-CN\">\r\n"
		  "<head>\r\n"
		  "    <meta charset=\"UTF-8\">\r\n"
		  "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\r\n"
		  "    <title>项目基于Fly3D OS</title>\r\n"
		  "</head>\r\n"
		  "<body>\r\n"
		  "    <h1>项目基于Fly3D OS</h1>\r\n"
		  "    <p>此项目基于Fly3D OS，以下是相关链接：</p>\r\n"
		  "    <ul>\r\n"
		  "        <li><a href=\"https://shop126791347.taobao.com/index.htm\" target=\"_blank\">淘宝店铺</a></li>\r\n"
		  "        <li><a href=\"https://mellow.aliexpress.com/store/1100991286?spm=a2g0o.home.1000002.3.2e8910d03hpSga\" target=\"_blank\">速卖通店铺</a></li>\r\n"
		  "    </ul>\r\n"
		  "</body>\r\n"
		  "</html>\r\n"
;
  LOGD("html:%s",html.c_str());
  shttpd_printf(arg, "%s", html.c_str());
  if (html.empty()) {
    shttpd_printf(arg, "%s", "read file failed");
  }

  arg->flags |= SHTTPD_END_OF_OUTPUT;
}

struct state {
  size_t cl; /* Content-Length   */
  size_t nread; /* Number of bytes read */
  FILE *fp;
  size_t file_length;
  multipart_reader *reader;
  HttpServer* server;
  bool is_tf_mounted;
};

static void
on_form_data_receive(const multipart_reader* reader, const char* data, uint64_t data_length) {
//  LOGD("write form data [%s], filename = [%s] length %lld", reader->form_data_name, reader->form_data_filename, data_length);
  if (strcmp(reader->form_data_name, "uploadFile") != 0) {
    return;
  }
  if (data_length == 0) {
    return;
  }
  if (reader->user_data == NULL) {
    return;
  }

  struct state* state = (struct state*)reader->user_data;
  if (state->fp == NULL) {
    if (!state->is_tf_mounted) {
      LOGD("未插入SD卡");
      return;
    }
    state->fp = fopen(srv::format("/mnt/extsd/%s", reader->form_data_filename).c_str(), "wb");
    if (state->fp == NULL) {
      LOGE("创建文件失败");
      return;
    }
  }

  state->file_length += data_length;

  if (data_length != fwrite(data, 1, data_length, state->fp)) {
    LOGE("write form data failed");
    return;
  }
}

static void
upload_file(struct shttpd_arg *arg)
 {
  const char *s;

  const char* request_method = shttpd_get_env(arg, "REQUEST_METHOD");
  if (strcmp(request_method, "POST") != 0) {
    return;
  }

  /* If the connection was broken prematurely, cleanup */
  if ((arg->flags & SHTTPD_CONNECTION_ERROR) && arg->state) {
    struct state* state = (struct state*) arg->state;
    if (state->fp) {
      fclose(state->fp);
    }
    sync();
    multipart_reader_destroy(state->reader);
    free(state);
  } else if ((s = shttpd_get_header(arg, "Content-Length")) == NULL) {
    shttpd_printf(arg, "HTTP/1.0 411 Length Required\n\n");
    arg->flags |= SHTTPD_END_OF_OUTPUT;
  } else if (arg->state == NULL) {
    /* New request. Allocate a state structure, and open a file */
    struct state* state = (struct state*)calloc(1, sizeof(*state));
    arg->state = state;
    state->cl = strtoul(s, NULL, 10);
    state->server = (HttpServer*)arg->user_data;
    state->is_tf_mounted = MOUNTMONITOR->isMount();

    std::string boundary = get_boundary(arg);
    if (!boundary.empty()) {
      LOGD("boundary=%s", boundary.c_str());
    }
    state->reader = multipart_reader_create(boundary.c_str(), on_form_data_receive, state);

    shttpd_printf(arg, "HTTP/1.0 200 OK\n"
        "Content-Type: text/plain\n\n");
  } else {
    struct state* state = (struct state*)arg->state;

    if(0 != multipart_reader_execute(state->reader, arg->in.buf, arg->in.len)) {
      LOGE("multipart_parser failed");
    }

    state->nread += arg->in.len;

    /* Tell SHTTPD we have processed all data */
    arg->in.num_bytes = arg->in.len;

    if (state->server->upload_filename_listener()) {
      state->server->upload_filename_listener()(state->reader->form_data_filename);
    }
    if (state->server->upload_progress_listener()) {
      state->server->upload_progress_listener()(
          (state->nread > state->cl) ? state->cl : state->nread,
              state->cl);
    }

    /* Data stream finished? Close the file, and free the state */
    if (state->nread >= state->cl) {
      shttpd_printf(arg, "Written %d bytes", state->file_length);
      if (!state->is_tf_mounted) {
        shttpd_printf(arg, ", No TF card is mounted!");
      }
      LOGD("file length = %d", state->file_length);
      if (state->fp) {
        fflush(state->fp);
        fclose(state->fp);
      }
      sync();
      free(state);
      arg->flags |= SHTTPD_END_OF_OUTPUT;
    }
  }
}

/*
 * This callback function is used to show how to handle 404 error
 */
static void
show_404(struct shttpd_arg *arg)
{
  shttpd_printf(arg, "%s", "HTTP/1.1 200 OK\r\n");
  shttpd_printf(arg, "%s", "Content-Type: text/plain\r\n\r\n");
  shttpd_printf(arg, "%s", "Oops. File not found! ");
  shttpd_printf(arg, "%s", "This is a custom error handler.");
  arg->flags |= SHTTPD_END_OF_OUTPUT;
}

/*
 * Make sure we have ho zombies from CGIs
 */
static void
signal_handler(int sig_num)
{
  switch (sig_num) {
#ifndef _WIN32
  case SIGCHLD:
    while (waitpid(-1, &sig_num, WNOHANG) > 0) ;
    break;
#endif /* !_WIN32 */
  default:
    break;
  }
}

HttpServer::HttpServer() {
  stop_ = false;
  port_ = 80;
  upload_filename_listener_ = NULL;
  upload_progress_listener_ = NULL;
}

HttpServer::~HttpServer() {
}

bool HttpServer::threadLoop() {
  stop_ = false;
  RunSync(port_);
  return false;
}

void HttpServer::RunAsync(int port) {
  port_ = port;
  stop_ = false;
  run("shttpd");
}

int HttpServer::RunSync(int port) {
  struct shttpd_ctx *ctx;

#ifndef _WIN32
  signal(SIGPIPE, SIG_IGN);
  signal(SIGCHLD, &signal_handler);
#endif /* !_WIN32 */

  /*
   * Initialize SHTTPD context.
   * Start listening on ports 8080 and 8081
   */
  ctx = shttpd_init(0, NULL);
  shttpd_set_option(ctx, "ports", format("%d", port).c_str());

  /* 注册uri和它的回调函数*/
  shttpd_register_uri(ctx, "/", &show_index, NULL);
  shttpd_register_uri(ctx, "/upload", &upload_file, this);

  shttpd_handle_error(ctx, 404, show_404, NULL);

  /* Serve connections infinitely until someone kills us */
  while (!stop_) {
    shttpd_poll(ctx, 1000);
  }

  /* Probably unreached, because we will be killed by a signal */
  shttpd_fini(ctx);

  return 0;
}

void HttpServer::Stop() {
  stop_ = true;
  requestExitAndWait();
  stop_ = false;
}

void HttpServer::set_upload_filename_listener(UploadFilenameListener listener) {
  upload_filename_listener_ = listener;
}
void HttpServer::set_upload_progress_listener(UploadProgressListener listener) {
  upload_progress_listener_ = listener;
}

HttpServer::UploadFilenameListener HttpServer::upload_filename_listener() {
  return upload_filename_listener_;
}
HttpServer::UploadProgressListener HttpServer::upload_progress_listener() {
  return upload_progress_listener_;
}


} /* namespace srv */
