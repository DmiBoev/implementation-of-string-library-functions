#include "my_string.h"

void fraction_to_str(long double frac, char* str, int precision) {
  int i = 0;

  while (i < precision) {
    frac *= 10;
    int digit = (int)frac;
    str[i] = (char)(digit + '0');
    frac -= digit;
    i++;
  }

  str[i] = '\0';
}
