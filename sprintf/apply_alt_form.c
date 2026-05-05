#include "my_string.h"
void apply_alt_form(char* buffer, format fmt, unsigned long num) {
  char temp[100];
  int i = 0;
  int j = 0;
  if (fmt.sharp && num != 0) {
    if (fmt.spec == 'o') {
      temp[i++] = '0';
    } else if (fmt.spec == 'x') {
      temp[i++] = '0';
      temp[i++] = 'x';
    } else if (fmt.spec == 'X') {
      temp[i++] = '0';
      temp[i++] = 'X';
    }
  }

  while (buffer[j] != '\0') {
    temp[i++] = buffer[j++];
  }
  temp[i] = '\0';
  i = 0;
  while (temp[i] != '\0') {
    buffer[i] = temp[i];
    i++;
  }
  buffer[i] = '\0';
}
