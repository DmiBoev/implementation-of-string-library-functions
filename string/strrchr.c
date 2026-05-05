// strrchr - the last occurrence of the character
#include "my_string.h"

char* my_strrchr(const char* str, int c) {
  char* result = NULL;
  size i = 0;
  while (str[i] != '\0') {
    if (str[i] == (char)c) result = (char*)&str[i];
    i++;
  }
  if ((char)c == '\0') result = (char*)&str[i];
  return result;
}

