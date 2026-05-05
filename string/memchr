// memchr - find a byte in memory
#include "my_string.h"

void* s21_memchr(const void* str, int c, s21_size n) {
  const unsigned char* s = (const unsigned char*)str;
  void* target = S21_NULL;
  for (s21_size i = 0; i < n && target == S21_NULL; i++) {
    if (s[i] == (char)c) {
      target = (void*)&s[i];
    }
  }
  return target;
}

