//float search
#include "my_string.h"

int parse_float(const char** src, long double* dest, int width) {
  skip_spaces(src);
  if (!**src) return 0;

  int res_width = (width <= 0) ? 1000 : width;
  int chars_read = 0, has_digits = 0;
  long double sign = 1.0, res = 0.0;

  if (chars_read < res_width && (**src == '-' || **src == '+')) {
    if (**src == '-') sign = -1.0;
    (*src)++;
    chars_read++;
  }

  while (chars_read < res_width && **src >= '0' && **src <= '9') {
    res = res * 10.0 + (**src - '0');
    has_digits = 1;
    (*src)++;
    chars_read++;
  }

  if (chars_read < res_width && **src == '.') {
    (*src)++;
    chars_read++;
    long double weight = 0.1;
    while (chars_read < res_width && **src >= '0' && **src <= '9') {
      res += (**src - '0') * weight;
      weight /= 10.0;
      has_digits = 1;
      (*src)++;
      chars_read++;
    }
  }

  if (has_digits && chars_read < res_width && (**src == 'e' || **src == 'E')) {
    const char* temp_src = *src;
    int temp_chars = chars_read;
    temp_src++;
    temp_chars++;

    int exp_sign = 1;
    if (temp_chars < res_width && (*temp_src == '-' || *temp_src == '+')) {
      if (*temp_src == '-') exp_sign = -1;
      temp_src++;
      temp_chars++;
    }

    if (temp_chars < res_width && *temp_src >= '0' && *temp_src <= '9') {
      long long exp_val = 0;
      while (temp_chars < res_width && *temp_src >= '0' && *temp_src <= '9') {
        exp_val = exp_val * 10 + (*temp_src - '0');
        temp_src++;
        temp_chars++;
      }

      while (exp_val > 0) {
        if (exp_sign > 0)
          res *= 10.0;
        else
          res /= 10.0;
        exp_val--;
      }
      *src = temp_src;
      chars_read = temp_chars;
    }
  }
  if (has_digits) {
    *dest = res * sign;
    return 1;
  }
  return 0;
}
