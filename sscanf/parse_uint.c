#include "my_string.h"

int parse_uint(const char** src, unsigned long long* dest, int base,
               int width) {
  if (!**src) return 0;
  int res_width = (width <= 0) ? 100000 : width;
  int sign = 1, chars_read = 0, has_digits = 0;
  unsigned long long res = 0;

  if (chars_read < res_width && (**src == '-' || **src == '+')) {
    if (**src == '-') sign = -1;
    (*src)++;
    chars_read++;
  }
  if ((base == 0 || base == 16) && (chars_read < res_width) && **src == '0') {
    has_digits = 1;
    if ((chars_read + 1 < res_width) &&
        (*(*src + 1) == 'x' || *(*src + 1) == 'X')) {
      base = 16;
      *src += 2;
      chars_read += 2;
    } else if (base == 0) {
      base = 8;
    }
  }
  if (base == 0) base = 10;

  while (chars_read < res_width) {
    int digit = get_digit(**src, base);
    if (digit == -1) break;
    res = res * base + digit;
    has_digits = 1;
    (*src)++;
    chars_read++;
  }
  if (has_digits) {
    *dest = (sign == -1) ? (unsigned long long)(-(long long)res) : res;
    return 1;
  }
  return 0;
}
