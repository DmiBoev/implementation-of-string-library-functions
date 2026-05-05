// strtok - split a string into tokens
#include "my_string.h"

static int delim(char c, const char* delim) {
  while (*delim != '\0') {
    if (c == *delim) {
      return 1;
    }
    delim++;
  }
  return 0;
}

char* strtok(char* str, const char* delim) {
  static char* last;
  char* token_start;
  if (str != NULL) {
    last = str;
  }
  if (last == NULL) {
    return NULL;
  }
  while (*last != '\0' && delim(*last, delim)) {
    last++;
  }
  if (*last == '\0') {
    return S21_NULL;
  }
  token_start = last;
  while (*last != '\0') {
    if (delim(*last, delim)) {
      *last = '\0';
      last++;
      return token_start;
    }
    last++;
  }
  last = NULL;
  return token_start;
}
