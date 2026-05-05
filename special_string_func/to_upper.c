// converts the string to uppercase
#include <stdlib.h>
#include "my_string.h"

void* to_upper(const char* str) { 
  char* res = NULL;
  if (str) {
    my_size len = strlen(str);
    if ((res = malloc((len + 1) * sizeof(char)))) {
      for (s21_size i = 0; i <= len; i++) {
        res[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
      }
    }
  }
  return (void*)res;
}
