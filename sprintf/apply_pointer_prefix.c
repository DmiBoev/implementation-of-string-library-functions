#include "my_string.h"
void apply_pointer_prefix(char* buffer) {
  char temp[100];
  int i = 0;
  int j = 0;
  temp[i++] = '0';
  temp[i++] = 'x';

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
