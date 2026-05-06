#include "my_string.h"

void general_to_str(long double num, char* str, my_format fmt) {
  int exp = get_exp(num);

  if (!fmt.precision_set) {
    fmt.precision = 6;
  }

  if (fmt.precision == 0) {
    fmt.precision = 1;
  }

  if (exp < -4 || exp >= fmt.precision) {
    fmt.precision = fmt.precision - 1;
    fmt.precision_set = 1;
    scientific_to_str(num, str, fmt);
  } else {
    fmt.precision = fmt.precision - (exp + 1);

    if (fmt.precision < 0) {
      fmt.precision = 0;
    }

    fmt.precision_set = 1;
    float_to_str(num, str, fmt);
  }

  if (!fmt.sharp) {
    remove_trailing_zeros(str);
  }
}
