// strpbrk - the first character from the set
#include "my_string.h"

char* my_strpbrk(const char* str1, const char* str2) {
  char* result = NULL;
  int found = 0;

  for (my_size i = 0; str1[i] != '\0' && !found; i++) {
    for (my_size j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        result = (char*)&str1[i];
        found = 1;
        break;
      }
    }
  }
  return result;
}
