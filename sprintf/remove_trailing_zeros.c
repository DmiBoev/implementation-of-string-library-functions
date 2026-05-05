#include "string.h"
void remove_trailing_zeros(char* str) {
  int i = 0;
  int dot_pos = -1;
  int exp_pos = -1;

  while (str[i] != '\0') {
    if (str[i] == '.') {
      dot_pos = i;
    }
    if (str[i] == 'e' || str[i] == 'E') {
      exp_pos = i;
    }
    i++;
  }
  
  if (dot_pos != -1) {
    int end = exp_pos == -1 ? i - 1 : exp_pos - 1;

    while (end > dot_pos && str[end] == '0') {
      end--;
    }

    if (str[end] == '.') {
      end--;
    }

    if (exp_pos == -1) {
      str[end + 1] = '\0';
    } else {
      int j = exp_pos;
      int k = end + 1;

      while (str[j] != '\0') {
        str[k++] = str[j++];
      }
      str[k] = '\0';
    }
  }
}
