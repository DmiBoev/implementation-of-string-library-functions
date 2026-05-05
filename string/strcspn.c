// strcspn - length of prohibited characters
#include "my_string.h"

my_size my_strcspn(const char* str1, const char* str2) {
  my_size i = 0;
  int found = 0;

  while (str1[i] != '\0' && !found) {
    my_size j = 0;
    while (str2[j] != '\0' && !found) {
      if (str1[i] == str2[j]) found = 1;
      j++;
    }
    if (!found) i++;
  }
  return i;
}
