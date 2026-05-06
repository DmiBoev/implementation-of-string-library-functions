#include "my_string.h"

format init_format(void) {
  my_format fmt;
  fmt.minus = 0;
  fmt.plus = 0;
  fmt.space = 0;
  fmt.sharp = 0;
  fmt.zero = 0;
  fmt.width = 0;
  fmt.precision = 0;
  fmt.precision_set = 0;
  fmt.length = 0;
  fmt.spec = 0;

  return fmt;
}
