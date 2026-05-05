// strncmp - compare strings up to n
#include "my_string.h"

int my_strncmp(const char* str1, const char* str2, my_size n) {
  my_size i = 0;
  int result = 0;

  while (i < n && result == 0) {
    result = (unsigned char)str1[i] - (unsigned char)str2[i];
    if (str1[i] == '\0') {
      i = n;
    } else
      i++;
  }
  return result;
}
