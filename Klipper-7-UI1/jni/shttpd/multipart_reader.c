#include "multipart_reader.h"

#include <stdlib.h>
#include <string.h>

int multipart_parser_on_boundary_begin(multipart_parser *mp) {
//  LOGD("on_boundary_begin");
  return 0;
}
int multipart_parser_on_header_field(multipart_parser* parser, const char *at, size_t length) {

  return 0;
}


#define multipart_parser_strcpy(dest, source, source_len) \
  memcpy(dest, source, (source_len < sizeof(dest)) ? source_len : (sizeof(dest) - 1));\
  dest[(source_len < sizeof(dest)) ? source_len : (sizeof(dest) - 1)] = 0;


int multipart_parser_on_header_value(multipart_parser* parser, const char *at, size_t length) {
  if (strcmp("Content-Disposition", parser->header_field) == 0) {
    multipart_reader* reader = (multipart_reader*)parser->data;
    int value_len = 0;
    int len = 0;
    const char* name = multipart_get_name(
         parser->header_value, sizeof(parser->header_value), &value_len);
    if (name != NULL) {
      multipart_parser_strcpy(reader->form_data_name, name, value_len);
    }
    const char* filename = multipart_get_filename(
         parser->header_value, sizeof(parser->header_value), &value_len);
    if (filename != NULL) {
      multipart_parser_strcpy(reader->form_data_filename, filename, value_len);
    }
  }
  return 0;
}
int multipart_parser_on_headers_complete(multipart_parser *mp) {
  return 0;
}

int multipart_parser_on_body(multipart_parser* parser, const char *at, size_t length) {
  const multipart_reader* reader = (multipart_reader*)parser->data;
  if (!reader->on_receive) {
    return 0;
  }
  reader->on_receive(reader, at, length);
  return 0;
}
int multipart_parser_on_body_parts_complete(multipart_parser *parser) {
  return 0;
}

multipart_reader* multipart_reader_create(const char* boundary, multipart_reader_callback on_receive, void* user_data) {
  multipart_reader* reader = (multipart_reader*)calloc(1, sizeof(multipart_reader));
  reader->on_receive = on_receive;
  reader->user_data = user_data;


  multipart_parser_init(&reader->parser);
  reader->parser.data = reader;
  strncpy(reader->boundary, boundary, sizeof(reader->boundary));
  multipart_parser_strcpy(reader->boundary, boundary, strlen(boundary));
  reader->parser.boundary = reader->boundary;
  reader->parser.boundary_len = strlen(reader->boundary);

  multipart_parser_settings_init(&reader->parser_settings);
  reader->parser_settings.on_boundary_begin = multipart_parser_on_boundary_begin;
  reader->parser_settings.on_header_field = multipart_parser_on_header_field;
  reader->parser_settings.on_header_value = multipart_parser_on_header_value;
  reader->parser_settings.on_headers_complete = multipart_parser_on_headers_complete;
  reader->parser_settings.on_body = multipart_parser_on_body;
  reader->parser_settings.on_body_parts_complete = multipart_parser_on_body_parts_complete;

  return reader;
}

int multipart_reader_execute(multipart_reader *reader, const void *data, uint64_t length) {
  if (reader->parser.multipart_errno != 0) {
    return reader->parser.multipart_errno;
  }
  int r = multipart_parser_execute(&reader->parser, &reader->parser_settings, data, length);
  if (r != 0) {
    reader->parser.multipart_errno = r;
  }
  return r;
}
void multipart_reader_destroy(multipart_reader *receiver) {
  if (!receiver) {
    return;
  }
  free(receiver);
}
