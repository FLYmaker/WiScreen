#pragma once

#include <stdint.h>
#include "multipart_parser.h"

#ifdef __cplusplus
extern "C" {
#endif

struct multipart_reader;
typedef struct multipart_reader multipart_reader;

typedef void (*multipart_reader_callback)(const multipart_reader* reader, const char* data, uint64_t data_length);

struct multipart_reader {
  multipart_reader_callback on_receive;
  void* user_data;
  char form_data_name[64];
  char form_data_filename[128];

  char boundary[64];
  multipart_parser parser;
  multipart_parser_settings parser_settings;
};

multipart_reader* multipart_reader_create(const char* boundary, multipart_reader_callback on_receive, void* user_data);
int multipart_reader_execute(multipart_reader *reader, const void *data, uint64_t length);
void multipart_reader_destroy(multipart_reader *reader);

#ifdef __cplusplus
}
#endif
