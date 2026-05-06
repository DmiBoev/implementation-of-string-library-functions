#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_to_upper_basic) {
  char str[] = "hello 123 world";
  char *res = (char *)to_upper(str);
  ck_assert_str_eq(res, "HELLO 123 WORLD");
  free(res);
}
END_TEST

START_TEST(test_to_upper_empty) {
  char str[] = "";
  char *res = (char *)to_upper(str);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(test_to_lower_basic) {
  char str[] = "HELLO 123 WORLD";
  char *res = (char *)to_lower(str);
  ck_assert_str_eq(res, "hello 123 world");
  free(res);
}
END_TEST

START_TEST(test_to_lower_empty) {
  char str[] = "";
  char *res = (char *)to_lower(str);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(test_insert_basic) {
  char *res = (char *)insert("Hello !", "World", 6);
  ck_assert_str_eq(res, "Hello World!");
  free(res);
}
END_TEST

START_TEST(test_insert_at_start) {
  char *res = (char *)insert("World", "Hello ", 0);
  ck_assert_str_eq(res, "Hello World");
  free(res);
}
END_TEST

START_TEST(test_insert_out_of_bounds) {
  char *res = (char *)insert("World", "Hello", 10);
  ck_assert_ptr_null(res);
}
END_TEST

START_TEST(test_insert_empty_src) {
  char *res = (char *)insert("", "Hello", 0);
  ck_assert_str_eq(res, "Hello");
  free(res);
}
END_TEST

START_TEST(test_trim_basic) {
  char *res = (char *)trim("...Hello World!!!", ".!");
  ck_assert_str_eq(res, "Hello World");
  free(res);
}
END_TEST

START_TEST(test_trim_empty_src) {
  char *res = (char *)trim("", ".!");
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(test_trim_no_trim_chars) {
  char *res = (char *)trim("  Hello  ", "");
  ck_assert_str_eq(res, "  Hello  ");
  free(res);
}
END_TEST

START_TEST(test_trim_all_match) {
  char *res = (char *)trim("!!!!", "!");
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(test_my_strlen_1) {
  ck_assert_uint_eq(my_strlen("hello"), strlen("hello"));
}
END_TEST

START_TEST(test_my_strlen_2) { ck_assert_uint_eq(my_strlen(""), strlen("")); }
END_TEST

START_TEST(test_my_strchr_1) {
  ck_assert_ptr_eq(my_strchr("hello", 'l'), strchr("hello", 'l'));
}
END_TEST

START_TEST(test_my_strchr_2) {
  ck_assert_ptr_eq(my_strchr("hello", 'z'), strchr("hello", 'z'));
}
END_TEST

START_TEST(test_my_strchr_3) {
  ck_assert_ptr_eq(my_strchr("hello", '\0'), strchr("hello", '\0'));
}
END_TEST

START_TEST(test_my_strncmp_1) {
  ck_assert_int_eq(my_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
}
END_TEST

START_TEST(test_my_strncmp_2) {
  ck_assert_int_eq(my_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
}
END_TEST

START_TEST(test_my_strncmp_3) {
  ck_assert_int_eq(my_strncmp("abc", "abc", 2), strncmp("abc", "abc", 2));
}
END_TEST

START_TEST(test_my_strncmp_4) {
  ck_assert_int_eq(my_strncmp("ab", "abc", 3), strncmp("ab", "abc", 3));
}
END_TEST

START_TEST(test_my_strncmp_5) {
  ck_assert_int_eq(my_strncmp("abc", "ab", 3), strncmp("abc", "ab", 3));
}
END_TEST

START_TEST(test_my_strncmp_6) {
  ck_assert_int_eq(my_strncmp("abc", "xyz", 0), strncmp("abc", "xyz", 0));
}
END_TEST

START_TEST(test_my_memset_1) {
  char my_str[20] = "hello world";
  char std_str[20] = "hello world";

  my_memset(my_str, 'x', 5);
  memset(std_str, 'x', 5);

  ck_assert_str_eq(my_str, std_str);
}
END_TEST

START_TEST(test_my_memset_2) {
  char my_str[20] = "hello world";
  char std_str[20] = "hello world";
  my_size n = 0;

  my_memset(my_str, '0', n);
  memset(std_str, '0', n);

  ck_assert_str_eq(my_str, std_str);
}
END_TEST

START_TEST(test_my_memset_3) {
  char my_str[20] = "";
  char std_str[20] = "";

  my_memset(my_str, 'a', 3);
  memset(std_str, 'a', 3);

  ck_assert_mem_eq(my_str, std_str, 20);
}
END_TEST

START_TEST(test_my_memcpy_1) {
  char my_dest[20] = {0};
  char std_dest[20] = {0};

  my_memcpy(my_dest, "hello", 5);
  memcpy(std_dest, "hello", 5);

  ck_assert_mem_eq(my_dest, std_dest, 20);
}
END_TEST

START_TEST(test_my_memcpy_2) {
  char my_dest[20] = "abcdef";
  char std_dest[20] = "abcdef";

  my_memcpy(my_dest, "xyz", 3);
  memcpy(std_dest, "xyz", 3);

  ck_assert_mem_eq(my_dest, std_dest, 20);
}
END_TEST

START_TEST(test_my_memcpy_3) {
  char my_dest[20] = "hello";
  char std_dest[20] = "hello";
  my_size n = 0;

  my_memcpy(my_dest, "abc", n);
  memcpy(std_dest, "abc", n);

  ck_assert_mem_eq(my_dest, std_dest, 20);
}
END_TEST

START_TEST(test_my_memcmp_1) {
  ck_assert_int_eq(my_memcmp("abc", "abc", 3), memcmp("abc", "abc", 3));
}
END_TEST

START_TEST(test_my_memcmp_2) {
  ck_assert_int_eq(my_memcmp("abc", "abd", 3), memcmp("abc", "abd", 3));
}
END_TEST

START_TEST(test_my_memcmp_3) {
  ck_assert_int_eq(my_memcmp("abc", "xyz", 0), memcmp("abc", "xyz", 0));
}
END_TEST

START_TEST(test_my_memcmp_4) {
  char a[] = {'a', 'b', '\0', 'd'};
  char b[] = {'a', 'b', '\0', 'e'};

  ck_assert_int_eq(my_memcmp(a, b, 4), memcmp(a, b, 4));
}
END_TEST

START_TEST(test_my_memchr_1) {
  char str[] = "hello";
  ck_assert_ptr_eq(my_memchr(str, 'l', 5), memchr(str, 'l', 5));
}
END_TEST

START_TEST(test_my_memchr_2) {
  char str[] = "hello";
  ck_assert_ptr_eq(my_memchr(str, 'z', 5), memchr(str, 'z', 5));
}
END_TEST

START_TEST(test_my_memchr_3) {
  char str[] = {'a', 'b', '\0', 'c'};
  ck_assert_ptr_eq(my_memchr(str, '\0', 4), memchr(str, '\0', 4));
}
END_TEST

START_TEST(test_my_memchr_4) {
  char str[] = "hello";
  my_size n = 0;
  ck_assert_ptr_eq(my_memchr(str, 'h', n), memchr(str, 'h', n));
}
END_TEST

START_TEST(test_my_strncpy_1) {
  char my_dest[20] = {0};
  char std_dest[20] = {0};

  my_strncpy(my_dest, "hello", 5);
  my_size n = 5;

  my_strncpy(my_dest, "hello", n);
  strncpy(std_dest, "hello", n);

  ck_assert_mem_eq(my_dest, std_dest, 20);
}
END_TEST

START_TEST(test_my_strncpy_2) {
  char my_dest[20] = "aaaaaaaaaa";
  char std_dest[20] = "aaaaaaaaaa";

  my_strncpy(my_dest, "hi", 5);
  strncpy(std_dest, "hi", 5);

  ck_assert_mem_eq(my_dest, std_dest, 20);
}
END_TEST

START_TEST(test_my_strncpy_3) {
  char my_dest[20] = "aaaaaaaaaa";
  char std_dest[20] = "aaaaaaaaaa";

  my_strncpy(my_dest, "hello", 2);
  my_size n = 2;

  my_strncpy(my_dest, "hello", n);
  strncpy(std_dest, "hello", n);

  ck_assert_mem_eq(my_dest, std_dest, 20);
}
END_TEST

START_TEST(test_my_strncpy_4) {
  char my_dest[20] = "hello";
  char std_dest[20] = "hello";
  my_size n = 0;

  my_strncpy(my_dest, "abc", n);
  strncpy(std_dest, "abc", n);

  ck_assert_mem_eq(my_dest, std_dest, 20);
}
END_TEST

START_TEST(test_my_strncat_1) {
  char my_dest[20] = "hello";
  char std_dest[20] = "hello";
  my_size n = 6;

  my_strncat(my_dest, " world", n);
  strncat(std_dest, " world", n);

  ck_assert_str_eq(my_dest, std_dest);
}
END_TEST

START_TEST(test_my_strncat_2) {
  char my_dest[20] = "hello";
  char std_dest[20] = "hello";

  my_strncat(my_dest, " world", 3);
  strncat(std_dest, " world", 3);

  ck_assert_str_eq(my_dest, std_dest);
}
END_TEST

START_TEST(test_my_strncat_3) {
  char my_dest[20] = "hello";
  char std_dest[20] = "hello";
  my_size n = 0;

  my_strncat(my_dest, " world", n);
  strncat(std_dest, " world", n);

  ck_assert_str_eq(my_dest, std_dest);
}
END_TEST

START_TEST(test_my_strncat_4) {
  char my_dest[20] = "";
  char std_dest[20] = "";

  my_strncat(my_dest, "abc", 2);
  strncat(std_dest, "abc", 2);

  ck_assert_str_eq(my_dest, std_dest);
}
END_TEST

START_TEST(test_my_strcspn_1) {
  ck_assert_uint_eq(my_strcspn("hello", "lo"), strcspn("hello", "lo"));
}
END_TEST

START_TEST(test_my_strcspn_2) {
  ck_assert_uint_eq(my_strcspn("hello", "xyz"), strcspn("hello", "xyz"));
}
END_TEST

START_TEST(test_my_strcspn_3) {
  ck_assert_uint_eq(my_strcspn("hello", ""), strcspn("hello", ""));
}
END_TEST

START_TEST(test_my_strcspn_4) {
  ck_assert_uint_eq(my_strcspn("", "abc"), strcspn("", "abc"));
}
END_TEST

START_TEST(test_my_strpbrk_1) {
  ck_assert_ptr_eq(my_strpbrk("hello", "lo"), strpbrk("hello", "lo"));
}
END_TEST

START_TEST(test_my_strpbrk_2) {
  ck_assert_ptr_eq(my_strpbrk("hello", "xyz"), strpbrk("hello", "xyz"));
}
END_TEST

START_TEST(test_my_strpbrk_3) {
  ck_assert_ptr_eq(my_strpbrk("", "abc"), strpbrk("", "abc"));
}
END_TEST

START_TEST(test_my_strpbrk_4) {
  ck_assert_ptr_eq(my_strpbrk("hello", ""), strpbrk("hello", ""));
}
END_TEST

START_TEST(test_my_strrchr_1) {
  ck_assert_ptr_eq(my_strrchr("hello", 'l'), strrchr("hello", 'l'));
}
END_TEST

START_TEST(test_my_strrchr_2) {
  ck_assert_ptr_eq(my_strrchr("hello", 'z'), strrchr("hello", 'z'));
}
END_TEST

START_TEST(test_my_strrchr_3) {
  ck_assert_ptr_eq(my_strrchr("hello", '\0'), strrchr("hello", '\0'));
}
END_TEST

START_TEST(test_my_strrchr_4) {
  ck_assert_ptr_eq(my_strrchr("", 'a'), strrchr("", 'a'));
}
END_TEST

START_TEST(test_my_strstr_1) {
  ck_assert_ptr_eq(my_strstr("hello world", "world"),
                   strstr("hello world", "world"));
}
END_TEST

START_TEST(test_my_strstr_2) {
  ck_assert_ptr_eq(my_strstr("hello world", "abc"),
                   strstr("hello world", "abc"));
}
END_TEST

START_TEST(test_my_strstr_3) {
  ck_assert_ptr_eq(my_strstr("hello world", ""), strstr("hello world", ""));
}
END_TEST

START_TEST(test_my_strstr_4) {
  ck_assert_ptr_eq(my_strstr("aaaaa", "aa"), strstr("aaaaa", "aa"));
}
END_TEST

START_TEST(test_my_strstr_5) {
  ck_assert_ptr_eq(my_strstr("", "abc"), strstr("", "abc"));
}
END_TEST

START_TEST(test_my_strerror_1) {
  ck_assert_str_eq(my_strerror(0), strerror(0));
}
END_TEST

START_TEST(test_my_strerror_2) {
  ck_assert_str_eq(my_strerror(1), strerror(1));
}
END_TEST

START_TEST(test_my_strerror_3) {
  ck_assert_str_eq(my_strerror(22), strerror(22));
}
END_TEST

START_TEST(test_my_strerror_4) {
  ck_assert_str_eq(my_strerror(999), strerror(999));
}
END_TEST

START_TEST(test_my_strerror_5) {
  ck_assert_str_eq(my_strerror(-1), strerror(-1));
}
END_TEST

START_TEST(test_my_strtok_1) {
  char str1[] = "hello,world,test";
  char str2[] = "hello,world,test";

  char *t1 = my_strtok(str1, ",");
  char *t2 = strtok(str2, ",");

  while (t1 && t2) {
    ck_assert_str_eq(t1, t2);
    t1 = my_strtok(NULL, ",");
    t2 = strtok(NULL, ",");
  }

  ck_assert_ptr_eq(t1, t2);
}
END_TEST

START_TEST(test_my_strtok_2) {
  char str1[] = "  hello   world  ";
  char str2[] = "  hello   world  ";

  char *t1 = my_strtok(str1, " ");
  char *t2 = strtok(str2, " ");

  while (t1 && t2) {
    ck_assert_str_eq(t1, t2);
    t1 = my_strtok(NULL, " ");
    t2 = strtok(NULL, " ");
  }

  ck_assert_ptr_eq(t1, t2);
}
END_TEST

START_TEST(test_my_strtok_3) {
  char str1[] = "";
  char str2[] = "";

  ck_assert_ptr_eq(my_strtok(str1, ","), strtok(str2, ","));
}
END_TEST

START_TEST(test_my_sprintf_percent) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "hello %% world");
  int std_res = sprintf(std_str, "hello %% world");

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_char) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "char: %c", 'A');
  int std_res = sprintf(std_str, "char: %c", 'A');

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_string) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "name: %s", "Ivan");
  int std_res = sprintf(std_str, "name: %s", "Ivan");

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num: %d", -123);
  int std_res = sprintf(std_str, "num: %d", -123);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_unsigned) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num: %u", 123456u);
  int std_res = sprintf(std_str, "num: %u", 123456u);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_width_string) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "name:%10s!", "Ivan");
  int std_res = sprintf(std_str, "name:%10s!", "Ivan");

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_minus_width_string) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "name:%-10s!", "Ivan");
  int std_res = sprintf(std_str, "name:%-10s!", "Ivan");

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_width_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%5d!", 42);
  int std_res = sprintf(std_str, "num:%5d!", 42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_plus_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%+d!", 42);
  int std_res = sprintf(std_str, "num:%+d!", 42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_space_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:% d!", 42);
  int std_res = sprintf(std_str, "num:% d!", 42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_plus_negative_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%+d!", -42);
  int std_res = sprintf(std_str, "num:%+d!", -42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_precision_string) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "str:%.3s!", "abcdef");
  int std_res = sprintf(std_str, "str:%.3s!", "abcdef");

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_precision_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%.5d!", 42);
  int std_res = sprintf(std_str, "num:%.5d!", 42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_precision_unsigned) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%.5u!", 42u);
  int std_res = sprintf(std_str, "num:%.5u!", 42u);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_precision_zero_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%.0d!", 0);
  int std_res = sprintf(std_str, "num:%.0d!", 0);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_short_int) {
  char my_str[100];
  char std_str[100];
  short num = -123;

  int my_res = my_sprintf(my_str, "num:%hd!", num);
  int std_res = sprintf(std_str, "num:%hd!", num);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_long_int) {
  char my_str[100];
  char std_str[100];
  long num = -1234567890L;

  int my_res = my_sprintf(my_str, "num:%ld!", num);
  int std_res = sprintf(std_str, "num:%ld!", num);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_short_unsigned) {
  char my_str[100];
  char std_str[100];
  unsigned short num = 65000;

  int my_res = my_sprintf(my_str, "num:%hu!", num);
  int std_res = sprintf(std_str, "num:%hu!", num);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_long_unsigned) {
  char my_str[100];
  char std_str[100];
  unsigned long num = 4000000000UL;

  int my_res = my_sprintf(my_str, "num:%lu!", num);
  int std_res = sprintf(std_str, "num:%lu!", num);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_float_default) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%f!", 12.345);
  int std_res = sprintf(std_str, "num:%f!", 12.345);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_float_precision) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%.2f!", 12.345);
  int std_res = sprintf(std_str, "num:%.2f!", 12.345);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_float_width) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%10.2f!", 12.3);
  int std_res = sprintf(std_str, "num:%10.2f!", 12.3);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_float_plus) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%+.2f!", 12.3);
  int std_res = sprintf(std_str, "num:%+.2f!", 12.3);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_float_zero_precision) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%.0f!", 12.6);
  int std_res = sprintf(std_str, "num:%.0f!", 12.6);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_float_space) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:% f!", 12.3);
  int std_res = sprintf(std_str, "num:% f!", 12.3);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_float_minus_width) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%-10.2f!", 12.3);
  int std_res = sprintf(std_str, "num:%-10.2f!", 12.3);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_negative_float) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%.3f!", -12.3456);
  int std_res = sprintf(std_str, "num:%.3f!", -12.3456);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_width_unsigned) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%10u!", 123u);
  int std_res = sprintf(std_str, "num:%10u!", 123u);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_minus_width_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%-8d!", 42);
  int std_res = sprintf(std_str, "num:%-8d!", 42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_width_precision_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%8.5d!", 42);
  int std_res = sprintf(std_str, "num:%8.5d!", 42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_width_precision_string) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "str:%8.3s!", "abcdef");
  int std_res = sprintf(std_str, "str:%8.3s!", "abcdef");

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_width_char) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "char:%5c!", 'A');
  int std_res = sprintf(std_str, "char:%5c!", 'A');

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_minus_width_char) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "char:%-5c!", 'A');
  int std_res = sprintf(std_str, "char:%-5c!", 'A');

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_precision_negative_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%.5d!", -42);
  int std_res = sprintf(std_str, "num:%.5d!", -42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_hex) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%x!", 255);
  int std_res = sprintf(std_str, "num:%x!", 255);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_HEX) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%X!", 255);
  int std_res = sprintf(std_str, "num:%X!", 255);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_octal) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%o!", 255);
  int std_res = sprintf(std_str, "num:%o!", 255);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_sharp_hex) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%#x!", 255);
  int std_res = sprintf(std_str, "num:%#x!", 255);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_sharp_HEX) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%#X!", 255);
  int std_res = sprintf(std_str, "num:%#X!", 255);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_sharp_octal) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%#o!", 255);
  int std_res = sprintf(std_str, "num:%#o!", 255);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_zero_width_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%05d!", 42);
  int std_res = sprintf(std_str, "num:%05d!", 42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_zero_width_unsigned) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%05u!", 42u);
  int std_res = sprintf(std_str, "num:%05u!", 42u);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_zero_width_hex) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%08x!", 255);
  int std_res = sprintf(std_str, "num:%08x!", 255);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_zero_ignored_with_precision) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%8.5d!", 42);
  int std_res = sprintf(std_str, "num:%8.5d!", 42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_pointer) {
  char my_str[100];
  char std_str[100];
  int value = 123;

  int my_res = my_sprintf(my_str, "ptr:%p!", &value);
  int std_res = sprintf(std_str, "ptr:%p!", &value);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_exp_default) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%e!", 123.456);
  int std_res = sprintf(std_str, "num:%e!", 123.456);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_EXP_default) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%E!", 123.456);
  int std_res = sprintf(std_str, "num:%E!", 123.456);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_exp_small) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%e!", 0.00123);
  int std_res = sprintf(std_str, "num:%e!", 0.00123);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_exp_precision) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%.2e!", 123.456);
  int std_res = sprintf(std_str, "num:%.2e!", 123.456);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_exp_negative) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%e!", -123.456);
  int std_res = sprintf(std_str, "num:%e!", -123.456);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_exp_width) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%15.2e!", 123.456);
  int std_res = sprintf(std_str, "num:%15.2e!", 123.456);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_g_default) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%g!", 123.456);
  int std_res = sprintf(std_str, "num:%g!", 123.456);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_G_default) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%G!", 1234567.0);
  int std_res = sprintf(std_str, "num:%G!", 1234567.0);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_g_small) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%g!", 0.0000123);
  int std_res = sprintf(std_str, "num:%g!", 0.0000123);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_g_precision) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%.3g!", 123.456);
  int std_res = sprintf(std_str, "num:%.3g!", 123.456);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_g_sharp) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%#.5g!", 12.3);
  int std_res = sprintf(std_str, "num:%#.5g!", 12.3);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_star_width_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%*d!", 8, 42);
  int std_res = sprintf(std_str, "num:%*d!", 8, 42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_star_precision_float) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%.*f!", 3, 12.34567);
  int std_res = sprintf(std_str, "num:%.*f!", 3, 12.34567);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_star_width_precision_float) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%*.*f!", 10, 2, 12.34567);
  int std_res = sprintf(std_str, "num:%*.*f!", 10, 2, 12.34567);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_long_double_f) {
  char my_str[100];
  char std_str[100];
  long double num = 12.345L;

  int my_res = my_sprintf(my_str, "num:%Lf!", num);
  int std_res = sprintf(std_str, "num:%Lf!", num);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_long_double_e) {
  char my_str[100];
  char std_str[100];
  long double num = 123.456L;

  int my_res = my_sprintf(my_str, "num:%Le!", num);
  int std_res = sprintf(std_str, "num:%Le!", num);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_my_sprintf_long_double_g) {
  char my_str[100];
  char std_str[100];
  long double num = 123.456L;

  int my_res = my_sprintf(my_str, "num:%Lg!", num);
  int std_res = sprintf(std_str, "num:%Lg!", num);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(test_int_sscanf) {
  int d1_orig = 0, d2_orig = 0;
  int d1_my = 0, d2_my = 0;
  const char *src = "123 -456";

  int res_orig = sscanf(src, "%d %d", &d1_orig, &d2_orig);
  int res_my = my_sscanf(src, "%d %d", &d1_my, &d2_my);

  ck_assert_int_eq(res_orig, res_my);
  ck_assert_int_eq(d1_orig, d1_my);
  ck_assert_int_eq(d2_orig, d2_my);

  int i1 = 0, i2 = 0;
  const char *src2 = "077 0x1A";
  my_sscanf(src2, "%i %i", &i1, &i2);
  ck_assert_int_eq(i1, 63);
  ck_assert_int_eq(i2, 26);
}
END_TEST

START_TEST(test_float_sscanf) {
  float f1_orig = 0, f1_my = 0;
  const char *src = "123.456";

  sscanf(src, "%f", &f1_orig);
  my_sscanf(src, "%f", &f1_my);
  ck_assert_float_eq_tol(f1_orig, f1_my, 1e-6);
}
END_TEST

START_TEST(test_str_char_sscanf) {
  char s1[100] = {0};
  char c1 = 0;
  const char *src = "  Hello";

  const char *temp_src = src;
  my_sscanf(temp_src, "%c", &c1);
  ck_assert_int_eq(c1, ' ');

  my_sscanf(src, "%s", s1);
  ck_assert_str_eq(s1, "Hello");
}
END_TEST

START_TEST(test_width_star_sscanf) {
  int a = 0;
  char s[100] = {0};
  const char *src = "123 678 ABC";
  int res = my_sscanf(src, "%d %*d %s", &a, s);

  ck_assert_int_eq(res, 2);
  ck_assert_int_eq(a, 123);
  ck_assert_str_eq(s, "ABC");
}
END_TEST

START_TEST(test_length_sscanf) {
  long long l1 = 0;
  short sh1 = 0;
  const char *src = "1234567890123 12";

  my_sscanf(src, "%lld %hd", &l1, &sh1);
  ck_assert_int_eq(sh1, 12);
}
END_TEST

START_TEST(test_sscanf_pointer_only_sscanf) {
  void *p_orig = NULL, *p_my = NULL;
  const char *src = "0x12345";
  int r1 = sscanf(src, "%p", &p_orig);
  int r2 = my_sscanf(src, "%p", &p_my);

  ck_assert_int_eq(r1, r2);
  ck_assert_ptr_eq(p_orig, p_my);
}
END_TEST

START_TEST(test_sscanf_n_only_sscanf) {
  int n_orig = 0, n_my = 0, v_orig = 0, v_my = 0;
  const char *src = "555";
  int r1 = sscanf(src, "%d%n", &v_orig, &n_orig);
  int r2 = my_sscanf(src, "%d%n", &v_my, &n_my);

  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(v_orig, v_my);
  ck_assert_int_eq(n_orig, n_my);
}
END_TEST

START_TEST(test_sscanf_empty_eof_sscanf) {
  int v;
  ck_assert_int_eq(sscanf("", "%d", &v), my_sscanf("", "%d", &v));
}
END_TEST

START_TEST(test_special_specs_sscanf) {
  int n_orig = 0, n_my = 0;
  int a_orig = 0, a_my = 0;
  const char *src_n = "12345 Hello";

  int res_orig = sscanf(src_n, "%d %n Hello", &a_orig, &n_orig);
  int res_my = my_sscanf(src_n, "%d %n Hello", &a_my, &n_my);

  ck_assert_int_eq(res_orig, res_my);
  ck_assert_int_eq(a_orig, a_my);
  ck_assert_int_eq(n_orig, n_my);
  ck_assert_int_eq(n_my, 6);

  void *p_orig = NULL, *p_my = NULL;
  const char *src_p = "0x7fff5fbff608";

  sscanf(src_p, "%p", &p_orig);
  my_sscanf(src_p, "%p", &p_my);

  ck_assert_ptr_eq(p_orig, p_my);
}
END_TEST

START_TEST(test_combined_sscanf) {
  int d_orig, d_my;
  float f_orig, f_my;
  char s_orig[20], s_my[20];
  const char *src = "42 3.14 piece_of_cake";

  int r_orig = sscanf(src, "%d %f %s", &d_orig, &f_orig, s_orig);
  int r_my = my_sscanf(src, "%d %f %s", &d_my, &f_my, s_my);

  ck_assert_int_eq(r_orig, r_my);
  ck_assert_int_eq(d_orig, d_my);
  ck_assert_float_eq_tol(f_orig, f_my, 1e-6);
  ck_assert_str_eq(s_orig, s_my);
}
END_TEST

START_TEST(test_my_sprintf_zero_negative_int) {
  char my_str[100];
  char std_str[100];

  int my_res = my_sprintf(my_str, "num:%05d!", -42);
  int std_res = sprintf(std_str, "num:%05d!", -42);

  ck_assert_str_eq(my_str, std_str);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

Suite *my_string_suite(void) {
  Suite *s = suite_create("my_string");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_my_strlen_1);
  tcase_add_test(tc, test_my_strlen_2);
  tcase_add_test(tc, test_my_strchr_1);
  tcase_add_test(tc, test_my_strchr_2);
  tcase_add_test(tc, test_my_strchr_3);
  tcase_add_test(tc, test_my_strncmp_1);
  tcase_add_test(tc, test_my_strncmp_2);
  tcase_add_test(tc, test_my_strncmp_3);
  tcase_add_test(tc, test_my_strncmp_4);
  tcase_add_test(tc, test_my_strncmp_5);
  tcase_add_test(tc, test_my_strncmp_6);
  tcase_add_test(tc, test_my_memset_1);
  tcase_add_test(tc, test_my_memset_2);
  tcase_add_test(tc, test_my_memset_3);
  tcase_add_test(tc, test_my_memcpy_1);
  tcase_add_test(tc, test_my_memcpy_2);
  tcase_add_test(tc, test_my_memcpy_3);
  tcase_add_test(tc, test_my_memcmp_1);
  tcase_add_test(tc, test_my_memcmp_2);
  tcase_add_test(tc, test_my_memcmp_3);
  tcase_add_test(tc, test_my_memcmp_4);
  tcase_add_test(tc, test_my_memchr_1);
  tcase_add_test(tc, test_my_memchr_2);
  tcase_add_test(tc, test_my_memchr_3);
  tcase_add_test(tc, test_my_memchr_4);
  tcase_add_test(tc, test_my_strncpy_1);
  tcase_add_test(tc, test_my_strncpy_2);
  tcase_add_test(tc, test_my_strncpy_3);
  tcase_add_test(tc, test_my_strncpy_4);
  tcase_add_test(tc, test_my_strncat_1);
  tcase_add_test(tc, test_my_strncat_2);
  tcase_add_test(tc, test_my_strncat_3);
  tcase_add_test(tc, test_my_strncat_4);
  tcase_add_test(tc, test_my_strcspn_1);
  tcase_add_test(tc, test_my_strcspn_2);
  tcase_add_test(tc, test_my_strcspn_3);
  tcase_add_test(tc, test_my_strcspn_4);
  tcase_add_test(tc, test_my_strpbrk_1);
  tcase_add_test(tc, test_my_strpbrk_2);
  tcase_add_test(tc, test_my_strpbrk_3);
  tcase_add_test(tc, test_my_strpbrk_4);
  tcase_add_test(tc, test_my_strrchr_1);
  tcase_add_test(tc, test_my_strrchr_2);
  tcase_add_test(tc, test_my_strrchr_3);
  tcase_add_test(tc, test_my_strrchr_4);
  tcase_add_test(tc, test_my_strstr_1);
  tcase_add_test(tc, test_my_strstr_2);
  tcase_add_test(tc, test_my_strstr_3);
  tcase_add_test(tc, test_my_strstr_4);
  tcase_add_test(tc, test_my_strstr_5);
  tcase_add_test(tc, test_my_strerror_1);
  tcase_add_test(tc, test_my_strerror_2);
  tcase_add_test(tc, test_my_strerror_3);
  tcase_add_test(tc, test_my_strerror_4);
  tcase_add_test(tc, test_my_strerror_5);
  tcase_add_test(tc, test_my_strtok_1);
  tcase_add_test(tc, test_my_strtok_2);
  tcase_add_test(tc, test_my_strtok_3);
  tcase_add_test(tc, test_my_sprintf_percent);
  tcase_add_test(tc, test_my_sprintf_char);
  tcase_add_test(tc, test_my_sprintf_string);
  tcase_add_test(tc, test_my_sprintf_int);
  tcase_add_test(tc, test_my_sprintf_unsigned);
  tcase_add_test(tc, test_my_sprintf_width_string);
  tcase_add_test(tc, test_my_sprintf_minus_width_string);
  tcase_add_test(tc, test_my_sprintf_width_int);
  tcase_add_test(tc, test_my_sprintf_plus_int);
  tcase_add_test(tc, test_my_sprintf_space_int);
  tcase_add_test(tc, test_my_sprintf_plus_negative_int);
  tcase_add_test(tc, test_my_sprintf_precision_string);
  tcase_add_test(tc, test_my_sprintf_precision_int);
  tcase_add_test(tc, test_my_sprintf_precision_unsigned);
  tcase_add_test(tc, test_my_sprintf_precision_zero_int);
  tcase_add_test(tc, test_my_sprintf_short_int);
  tcase_add_test(tc, test_my_sprintf_long_int);
  tcase_add_test(tc, test_my_sprintf_short_unsigned);
  tcase_add_test(tc, test_my_sprintf_long_unsigned);
  tcase_add_test(tc, test_my_sprintf_float_default);
  tcase_add_test(tc, test_my_sprintf_float_precision);
  tcase_add_test(tc, test_my_sprintf_float_width);
  tcase_add_test(tc, test_my_sprintf_float_plus);
  tcase_add_test(tc, test_my_sprintf_float_zero_precision);
  tcase_add_test(tc, test_my_sprintf_float_space);
  tcase_add_test(tc, test_my_sprintf_float_minus_width);
  tcase_add_test(tc, test_my_sprintf_negative_float);
  tcase_add_test(tc, test_my_sprintf_width_unsigned);
  tcase_add_test(tc, test_my_sprintf_minus_width_int);
  tcase_add_test(tc, test_my_sprintf_width_precision_int);
  tcase_add_test(tc, test_my_sprintf_width_precision_string);
  tcase_add_test(tc, test_my_sprintf_width_char);
  tcase_add_test(tc, test_my_sprintf_minus_width_char);
  tcase_add_test(tc, test_my_sprintf_precision_negative_int);
  tcase_add_test(tc, test_my_sprintf_hex);
  tcase_add_test(tc, test_my_sprintf_HEX);
  tcase_add_test(tc, test_my_sprintf_octal);
  tcase_add_test(tc, test_my_sprintf_sharp_hex);
  tcase_add_test(tc, test_my_sprintf_sharp_HEX);
  tcase_add_test(tc, test_my_sprintf_sharp_octal);
  tcase_add_test(tc, test_my_sprintf_zero_width_int);
  tcase_add_test(tc, test_my_sprintf_zero_width_unsigned);
  tcase_add_test(tc, test_my_sprintf_zero_width_hex);
  tcase_add_test(tc, test_my_sprintf_zero_ignored_with_precision);
  tcase_add_test(tc, test_my_sprintf_pointer);
  tcase_add_test(tc, test_my_sprintf_exp_default);
  tcase_add_test(tc, test_my_sprintf_EXP_default);
  tcase_add_test(tc, test_my_sprintf_exp_small);
  tcase_add_test(tc, test_my_sprintf_exp_precision);
  tcase_add_test(tc, test_my_sprintf_exp_negative);
  tcase_add_test(tc, test_my_sprintf_exp_width);
  tcase_add_test(tc, test_my_sprintf_g_default);
  tcase_add_test(tc, test_my_sprintf_G_default);
  tcase_add_test(tc, test_my_sprintf_g_small);
  tcase_add_test(tc, test_my_sprintf_g_precision);
  tcase_add_test(tc, test_my_sprintf_g_sharp);
  tcase_add_test(tc, test_my_sprintf_star_width_int);
  tcase_add_test(tc, test_my_sprintf_star_precision_float);
  tcase_add_test(tc, test_my_sprintf_star_width_precision_float);
  tcase_add_test(tc, test_my_sprintf_long_double_f);
  tcase_add_test(tc, test_my_sprintf_long_double_e);
  tcase_add_test(tc, test_my_sprintf_long_double_g);
  tcase_add_test(tc, test_my_sprintf_zero_negative_int);
  tcase_add_test(tc, test_int_sscanf);
  tcase_add_test(tc, test_float_sscanf);
  tcase_add_test(tc, test_str_char_sscanf);
  tcase_add_test(tc, test_width_star_sscanf);
  tcase_add_test(tc, test_length_sscanf);

  tcase_add_test(tc, test_combined_sscanf);
  tcase_add_test(tc, test_special_specs_sscanf);

  tcase_add_test(tc, test_sscanf_pointer_only_sscanf);
  tcase_add_test(tc, test_sscanf_n_only_sscanf);
  tcase_add_test(tc, test_sscanf_empty_eof_sscanf);

  tcase_add_test(tc, test_to_upper_basic);
  tcase_add_test(tc, test_to_upper_empty);

  tcase_add_test(tc, test_to_lower_basic);
  tcase_add_test(tc, test_to_lower_empty);

  tcase_add_test(tc, test_insert_basic);
  tcase_add_test(tc, test_insert_at_start);
  tcase_add_test(tc, test_insert_out_of_bounds);
  tcase_add_test(tc, test_insert_empty_src);

  tcase_add_test(tc, test_trim_basic);
  tcase_add_test(tc, test_trim_empty_src);
  tcase_add_test(tc, test_trim_no_trim_chars);
  tcase_add_test(tc, test_trim_all_match);

  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  int failed = 0;
  Suite *s = my_string_suite();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed == 0 ? 0 : 1;
}
