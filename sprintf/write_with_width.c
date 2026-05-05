#include "my_string.h"

char* write_with_width(char* str, const char* buffer, format fmt) {
  int len = (int)strlen(buffer);
  int spaces = fmt.width - len;
  char pad = ' ';

  if (spaces < 0) {
    spaces = 0;
  }

  if (fmt.zero && !fmt.minus && !fmt.precision_set) {
    pad = '0';
  }

  if (pad == '0' &&
      (buffer[0] == '-' || buffer[0] == '+' || buffer[0] == ' ')) {
    *str = buffer[0];
    str++;
    buffer++;
  }

  if (!fmt.minus) {
    while (spaces > 0) {
      *str = pad;
      str++;
      spaces--;
    }
  }

  while (*buffer != '\0') {
    *str = *buffer;
    str++;
    buffer++;
  }

  if (fmt.minus) {
    while (spaces > 0) {
      *str = ' ';
      str++;
      spaces--;
    }
  }

  return str;
}
