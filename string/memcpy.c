// memcpy - copy memory
#include "my_string.h"

void* my_memcpy(void* dest, const void* src, s21_size n) {
  unsigned char* d = (unsigned char*)dest;
  const unsigned char* s = (const unsigned char*)src;
  for (s21_size i = 0; i < n; i++) d[i] = s[i];
  return dest;
}

