#include "my_string.h"
void apply_int_precision(char* buffer, my_format fmt) {
  char temp[100];
  int i = 0;
  int j = 0;
  int len = (int)my_strlen(buffer);

  if (buffer[0] == '-' || buffer[0] == '+' || buffer[0] == ' ') {
    temp[i++] = buffer[0];
    j = 1;
    len--;
  }

  if (fmt.precision_set && fmt.precision == 0 && buffer[j] == '0' &&
      buffer[j + 1] == '\0') {
    temp[i] = '\0';
  } else {
    int zeros = fmt.precision - len;

    while (zeros > 0) {
      temp[i++] = '0';
      zeros--;
    }

    while (buffer[j] != '\0') {
      temp[i++] = buffer[j++];
    }

    temp[i] = '\0';
  }

  i = 0;
  while (temp[i] != '\0') {
    buffer[i] = temp[i];
    i++;
  }
  buffer[i] = '\0';
}
