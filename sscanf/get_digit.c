#include "my_string.h"
int get_digit(char c, int base) {
  int res = -1;
  if (c >= '0' && c <= '9')
    res = c - '0';
  else if (c >= 'a' && c <= 'f')
    res = c - 'a' + 10;
  else if (c >= 'A' && c <= 'F')
    res = c - 'A' + 10;
  return (res != -1 && res < base) ? res : -1;
}
