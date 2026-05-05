#include "my_string.h"

void exp_to_str(int exp, char* str, int uppercase) {
  int i = 0;
  str[i++] = uppercase ? 'E' : 'e';

  if (exp >= 0) {
    str[i++] = '+';
  } else {
    str[i++] = '-';
    exp = -exp;
  }

  if (exp < 10) {
    str[i++] = '0';
    str[i++] = (char)(exp + '0');
  } else {
    char temp[20];
    int j = 0;

    while (exp > 0) {
      temp[j++] = (char)(exp % 10 + '0');
      exp /= 10;
    }

    while (j > 0) {
      str[i++] = temp[--j];
    }
  }

  str[i] = '\0';
}
