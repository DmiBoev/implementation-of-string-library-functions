// strncat - add line to n
#include "my_string.h"

char* my_strncat(char* dest, const char* src, my_size n) {
  my_size len_dest = my_strlen(dest);
  my_size i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[len_dest + i] = src[i];
  }
  dest[len_dest + i] = '\0';
  return dest;
}

