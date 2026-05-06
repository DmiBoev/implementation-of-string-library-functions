#include "my_string.h"
void apply_string_precision(char* buffer, my_format fmt) {
  if (fmt.precision_set) {
    int i = 0;
    while (buffer[i] != '\0' && i < fmt.precision) {
      i++;
    }
    buffer[i] = '\0';
  }
}
