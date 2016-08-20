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

int main() {
  char *request = read_request();
  char *method;
  int method_len;
  int status = parse_http(request, &method, &method_len);
  printf("PARSE STATUS: %d\n", status);
  printf("METHOD: ");
  for (int i = 0; i < method_len; i++) {
    printf("%c", method[i]);
  }
  printf("\n");
  return 0;
}
