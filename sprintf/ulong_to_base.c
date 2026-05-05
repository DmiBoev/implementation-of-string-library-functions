#include "my_string.h"

void ulong_to_base(unsigned long num, char* str, int base, int uppercase) {
  char digits_lower[] = "0123456789abcdef";
  char digits_upper[] = "0123456789ABCDEF";
  char* digits = uppercase ? digits_upper : digits_lower;
  int i = 0;

  do {
    str[i] = digits[num % base];
    num /= base;
    i++;
  } while (num > 0);

  str[i] = '\0';

  my_size left = 0;
  my_size right = i - 1;

  while (left < right) {
    char tmp = str[left];
    str[left] = str[right];
    str[right] = tmp;
    left++;
    right--;
  }
}
