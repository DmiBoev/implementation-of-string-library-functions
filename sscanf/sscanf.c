//parses a formatted string (like printf, only in reverse) and writes the data into variables
#include "my_string.h"
int my_sscanf(const char* src, const char* format, ...) {
  if (src == (void*)0 || *src == '\0') return -1;
  const char* start = src;
  va_list args;
  va_start(args, format);
  int count = 0, success_match = 0, break_flag = 0;

  while (*format && !break_flag) {
    if (isspace(*format)) {
      propusk_simvols(&src);
      format++;
    } else if (*format != '%') {
      if (*src == *format) {
        src++;
        format++;
      } else {
        break_flag = 1;
      }
    } else {
      Token tok = {0, 0, 0, 0};
      format++;
      parse_token_params(&format, &tok);
      if (*format) {
        handle_specifier(&src, start, &args, tok, *format, &count,
                         &success_match, &break_flag);
        if (!break_flag) format++;
      } else {
        break_flag = 1;
      }
    }
  }
  va_end(args);
  return count;
}

void handle_specifier(const char** src, const char* start, va_list* args,
                      Token tok, char spec, int* count, int* success_match,
                      int* break_flag) {
  int res = 0;
  switch (spec) {
    case 'd':
    case 'u':
    case 'i':
    case 'o':
    case 'x':
    case 'X':
    case 'p':
      res = handle_int(src, args, tok, spec);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      res = handle_float(src, args, tok);
      break;
    case 's':
      res = handle_string(src, args, tok, count, *success_match);
      break;
    case 'c':
      res = handle_char(src, args, tok);
      break;
    case 'n':
      if (!tok.star) *(va_arg(*args, int*)) = (int)(*src - start);
      break;
    case '%':
      if (**src == '%') {
        (*src)++;
        return;
      } else {
        *break_flag = 1;
      }
      return;
    default:
      *break_flag = 1;
      return;
  }
  if (res) {
    if (!tok.star) (*count)++;
    *success_match = 1;
  } else {
    *break_flag = 1;
  }
}
