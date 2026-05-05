//Processing a single character case (c)
int handle_char(const char** src, va_list* args, Token tok) {
  if (!**src) return 0;
  if (!tok.star) *(va_arg(*args, char*)) = **src;
  (*src)++;
  return 1;
}
