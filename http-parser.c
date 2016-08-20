#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include "trial-http.h"

static int find_space(char *buf) {
  for (int i = 0; buf[i] != EOF; i++) {
    if (isspace(buf[i])) return i;
  }
  return -1;
}

void parse_method(char **buf, char **method, int *method_len) {
  int len = find_space(*buf);
  if (len == -1) {
    printf("Error in parse_method");
    exit(1);
  }
  *method = *buf;
  *method_len = len;
  *buf += len + 1;
}

void parse_path(char **buf, char **path, int *path_len) {
  int len = find_space(*buf);
  if (len == -1) {
    printf("Error in parse_path");
    exit(1);
  }
  *path = *buf;
  ;
  *path_len = len;
  *buf += len + 1;
}

int parse_http(char *buf, char **method, int *method_len, char **path,
               int *path_len) {
  *method = NULL;
  *method_len = 0;
  *path = NULL;
  *path_len = 0;
  parse_method(&buf, method, method_len);
  parse_path(&buf, path, path_len);
  if (*buf != EOF) {
    printf("REST OF REQUEST:\n-----\n%s-----\n", buf);
  }
  return 0;
}
