#include "my_string.h"
void ulong_to_str(unsigned long num, char* str) {
  
  int i = 0;
  do {
    str[i] = (char)(num % 10 + '0');
    num /= 10;
    i++;
  } while (num > 0);

  str[i] = '\0';
  s21_size left = 0;
  s21_size right = i - 1;

  while (left < right) {
    char tmp = str[left];
    str[left] = str[right];
    str[right] = tmp;
    left++;
    right--;
  }
}

