// memset - fill memory with value
#include "my_string.h"

void* my_memset(void* str, int c, my_size n) {
  unsigned char* ptr = (unsigned char*)str;
  for (s21_size i = 0; i < n; i++) ptr[i] = (unsigned char)c;
  return str;
}
