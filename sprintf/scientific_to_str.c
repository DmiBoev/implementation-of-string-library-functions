#include "my_string.h"

void scientific_to_str(long double num, char* str, format fmt) {
  if (!fmt.precision_set) {
    fmt.precision = 6;
  }

  int is_negative = 0;
  int exp = 0;

  if (num < 0) {
    is_negative = 1;
    num = -num;
  }

  if (num != 0.0) {
    while (num >= 10.0) {
      num /= 10.0;
      exp++;
    }

    while (num < 1.0) {
      num *= 10.0;
      exp--;
    }
  }

  char mantissa[200];
  char exp_buffer[30];
  format mantissa_fmt = fmt;

  mantissa_fmt.plus = 0;
  mantissa_fmt.space = 0;
  mantissa_fmt.width = 0;

  float_to_str(num, mantissa, mantissa_fmt);

  int i = 0;
  int j = 0;

  if (is_negative) {
    str[i++] = '-';
  }

  while (mantissa[j] != '\0') {
    str[i++] = mantissa[j++];
  }

  exp_to_str(exp, exp_buffer, fmt.spec == 'E' || fmt.spec == 'G');

  j = 0;
  while (exp_buffer[j] != '\0') {
    str[i++] = exp_buffer[j++];
  }

  str[i] = '\0';
}
