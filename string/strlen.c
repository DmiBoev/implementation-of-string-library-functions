// strlen - string length
#include "my_string.h"

my_size my_strlen(const char* str) {
  my_size len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}
