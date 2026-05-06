#include "my_string.h"
void skip_spaces(const char** src) {
  while (**src && isspace(**src)) {
    (*src)++;
  }
}
