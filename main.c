#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trial-http.h"

int BUFFER_SIZE = 5;

char *read_request() {
  int size = BUFFER_SIZE;
  char *ret = malloc(size);
  char c;
  int i = 0;
  while ((c = getchar()) != EOF) {
    ret[i++] = c;
    if (i >= size) {
      size += BUFFER_SIZE;
      char *tmp = realloc(ret, size);
      if (tmp == NULL) {
        printf("Could not realloc\n");
        exit(1);
      }
      ret = tmp;
    }
  }
  ret[i] = '\0';
  return ret;
}

const char *substr(char *buf, int len) {
  char *ret = malloc(len);
  for (int i = 0; i < len; i++) {
    ret[i] = buf[i];
  }
  return ret;
}

int main() {
  char *request = read_request();
  char *method, *path;
  int method_len, path_len;
  int status = parse_http(request, &method, &method_len, &path, &path_len);
  printf("RESULT:\n");
  printf("\tPARSE STATUS: %d\n", status);
  printf("\tMETHOD: %s\n", substr(method, method_len));
  printf("\tPATH: %s\n", substr(path, path_len));
  return 0;
}
