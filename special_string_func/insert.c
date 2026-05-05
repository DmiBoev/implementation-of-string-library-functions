#include <stdlib.h>
#include "my_string.h"

void* insert(const char* src, const char* str,
             my_size start_index) { 
  my_size src_len = (src) ? strlen(src) : 0;
  my_size str_len = (str) ? strlen(str) : 0;
  char* res = S21_NULL;

  if (src && str && start_index <= src_len) {
    res = malloc((src_len + str_len + 1) * sizeof(char));
    if (res) {
      memcpy(res, src, start_index);
      memcpy(res + start_index, str, str_len);
      memcpy(res + start_index + str_len, src + start_index,
                 src_len - start_index);
      res[src_len + str_len] = '\0';
    }
  }
  return (void*)res;
}
