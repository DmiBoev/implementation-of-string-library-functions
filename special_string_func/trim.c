//returns a new string in which all characters from the string are removed from the beginning and end.
#include <stdlib.h>
#include "my_string.h"

void* trim(
    const char* src,
    const char* trim_chars) { 
  char* res = NULL;
  if (src && trim_chars) {
    const char* start = src;
    const char* end = src + strlen(src) - 1;

    while (*start != '\0' && strchr(trim_chars, *start)) start++;
    while (end >= start && strchr(trim_chars, *end)) end--;

    my_size len_res = (end >= start) ? end - start + 1 : 0;
    res = malloc((len_res + 1) * sizeof(char));
    if (res) {
      memcpy(res, start, len_res);
      res[len_res] = '\0';
    }
  }
  return (void*)res;
}
