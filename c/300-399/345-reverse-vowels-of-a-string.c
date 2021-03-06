/*
 * Copyright (C) 2017, Saul Lawliet <october dot sunbathe at gmail dot com>
 * All rights reserved.
 *
 * 两个指针, 往中间查找
 */

#include <stdlib.h> /* malloc() */
#include <string.h> /* strlen(), strchr() */
#include "c/test.h"

void swap(char *a, char *b) {
  char tmp = *a; *a = *b; *b = tmp;
}

char *reverseVowels(char *s) {
  const char *vowels = "aeiouAEIOU";

  char *p1 = s,
       *p2 = s+strlen(s)- 1;

  while (p1 < p2) {
    if (!strchr(vowels, *p1)) {
      p1++; continue;
    }
    if (!strchr(vowels, *p2)) {
      p2--; continue;
    }
    swap(p1++, p2--);
  }

  return s;
}

void test(const char *expect, char *str) {
  int sz = strlen(str);
  char *s = malloc(sz + 1);
  strncpy(s, str, sz + 1);
  s = reverseVowels(s);

  EXPECT_EQ_STRING_AND_FREE_ACTUAL(expect, s);
}

int main(void) {
  test("holle", "hello");
  test("leotcede", "leetcode");
  test(".", ".");
  test("Aa", "aA");

  return testOutput();
}
