// memchr - find a byte in memory
#include "my_string.h"

void* my_memchr(const void* str, int c, my_size n) {
  const unsigned char* s = (const unsigned char*)str;
  void* target = NULL;
  for (my_size i = 0; i < n && target == NULL; i++) {
    if (s[i] == (char)c) {
      target = (void*)&s[i];
    }
  }
  return target;
}

