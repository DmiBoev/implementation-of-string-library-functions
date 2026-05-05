#include "my_string.h"
void propusk_simvols(const char** src) {
  while (**src && isspace(**src)) {
    (*src)++;
  }
}
