//returns a new string in which str is inserted into src at position index
#include <stdlib.h>
#include "my_string.h"

void* my_insert(const char* src, const char* str,
             my_size start_index) { 
  my_size src_len = (src) ? my_strlen(src) : 0;
  my_size str_len = (str) ? my_strlen(str) : 0;
  char* res = NULL;

  if (src && str && start_index <= src_len) {
    res = malloc((src_len + str_len + 1) * sizeof(char));
    if (res) {
      my_memcpy(res, src, start_index);
      my_memcpy(res + start_index, str, str_len);
      my_memcpy(res + start_index + str_len, src + start_index,
                 src_len - start_index);
      res[src_len + str_len] = '\0';
    }
  }
  return (void*)res;
}
