// memcmp - compare memory
#include "my_string.h"

int s21_memcmp(const void* str1, const void* str2, s21_size n) {
  const unsigned char* s1 = (const unsigned char*)str1;
  const unsigned char* s2 = (const unsigned char*)str2;
  int res = 0;
  for (s21_size i = 0; i < n && !res; i++) {
    if (s1[i] != s2[i]) {
      res = s1[i] - s2[i];
    }
  }
  return res;
}
