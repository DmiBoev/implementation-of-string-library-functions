//converts a string to lowercase
#include <stdlib.h>
#include "my_string.h"

void* to_lower(const char* str) {
  char* res = NULL;
  if (str) {
    my_size len = strlen(str);
    if ((res = malloc((len + 1) * sizeof(char)))) {
      for (my_size i = 0; i <= len; i++) {
        res[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
      }
    }
  }
  return (void*)res;
}
