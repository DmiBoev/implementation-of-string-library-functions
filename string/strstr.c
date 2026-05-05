// strstr - find a substring
#include "my_string.h"

char* my_strstr(const char* haystack, const char* needle) {
  char* result = NULL;
  my_size i = 0;
  if (*needle == '\0') {
    result = (char*)haystack;
  }
  while (haystack[i] != '\0' && result == NULL) {
    my_size j = 0;
    while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
      j++;
    }
    if (needle[j] == '\0') {
      result = (char*)&haystack[i];
    }
    i++;
  }
  return result;
}
