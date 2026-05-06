#include "my_string.h"
void float_to_str(long double num, char* str, my_format fmt) {
  if (!fmt.precision_set) {
    fmt.precision = 6;
  }
  int is_negative = 0;
  if (num < 0) {
    is_negative = 1;
    num = -num;
  }
  long double round = 0.5;
  int i = 0;
  while (i < fmt.precision) {
    round /= 10;
    i++;
  }

  num += round;
  unsigned long int_part = (unsigned long)num;
  long double frac_part = num - int_part;
  char int_buffer[100];
  char frac_buffer[100];
  ulong_to_str(int_part, int_buffer);
  fraction_to_str(frac_part, frac_buffer, fmt.precision);

  i = 0;
  int j = 0;
  if (is_negative) {
    str[i++] = '-';
  }

  while (int_buffer[j] != '\0') {
    str[i++] = int_buffer[j++];
  }

  if (fmt.precision > 0) {
    str[i++] = '.';

    j = 0;
    while (frac_buffer[j] != '\0') {
      str[i++] = frac_buffer[j++];
    }
  }

  str[i] = '\0';
}
