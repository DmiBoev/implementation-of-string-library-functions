//strncpy-copies the specified number of characters from one string to another
#include "my_string.h"

char* my_strncpy(char* dest, const char* src, my_size n) {
  my_size i = 0;
  while (i < n && src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  while (i < n) {
    dest[i] = '\0';
    i++;
  }
  return dest;
}
