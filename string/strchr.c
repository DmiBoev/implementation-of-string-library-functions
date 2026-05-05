// strchr - first occurrence of character
#include "my_string.h"

char* my_strchr(const char* str, int c) {
  my_size i;
  char* res = NULL;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == (unsigned char)c) {
      res = (char*)(str + i);
      break;
    }
  }
  if ((unsigned char)c == '\0') res = (char*)(str + i);
  return res;
}
