#include "my_string.h"

int get_exp(long double num) {
  int exp = 0;
  if (num < 0) {
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
  return exp;
}
