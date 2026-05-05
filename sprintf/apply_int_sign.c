#include "my_string.h"

void apply_int_sign(char* buffer, format fmt) {
  char temp[100];
  int i = 0;
  int j = 0;

  if (buffer[0] != '-') {
    if (fmt.plus) {
      temp[i++] = '+';
    } else if (fmt.space) {
      temp[i++] = ' ';
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
}

