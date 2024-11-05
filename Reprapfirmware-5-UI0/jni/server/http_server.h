#pragma once

#include <stdarg.h>
#include <stdint.h>

#include <string>
#include <system/Thread.h>


namespace srv {

class HttpServer : protected Thread {
public:
  typedef void (*UploadFilenameListener)(const std::string& filename);
  typedef void (*UploadProgressListener)(uint64_t uploaded_bytes, uint64_t all_bytes);

  HttpServer();
  virtual ~HttpServer();
  virtual bool threadLoop();

  /**
   * 在新线程运行
   */
  void RunAsync(int port);
  /**
   * 在当前线程运行，会阻塞
   */
  int RunSync(int port);
  /**
   * 停止
   */
  void Stop();

  /**
   * 设置上传文件名回调
   */
  void set_upload_filename_listener(UploadFilenameListener listener);
  /**
   * 设置上传进度回调
   */
  void set_upload_progress_listener(UploadProgressListener listener);

  UploadFilenameListener upload_filename_listener();
  UploadProgressListener upload_progress_listener();

private:
  bool stop_;
  int port_;
  UploadFilenameListener upload_filename_listener_;
  UploadProgressListener upload_progress_listener_;
};

inline std::string format(const char* format, ...) {
  std::string tmp;
  va_list vl;
  va_start(vl, format);
  size_t num = vsnprintf(0, 0, format, vl);
  if (num >= tmp.capacity()) tmp.reserve(num + sizeof(char));

  tmp.resize(num);
  vsnprintf((char*)tmp.data(), tmp.capacity(), format, vl);
  va_end(vl);
  return tmp;
}

} /* namespace srv */
