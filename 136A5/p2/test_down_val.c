#include <assert.h>
#include "basic_pointer.h"
#include <stdlib.h>
#include <stdio.h>

void case1() {
  int small = 1;
  int big = 2;
  assert(down_value(&small, &big) == &big);
  assert(big == small);
  printf("Case 1 Passed.\n");
}

void case2() {
  // Add your test
  int small = 1;
  int big = 2;
  printf("Case 2 Passed.\n");
}

int main(void) {
  printf("Running 'test_down_val':\n");
  case1();
  // case2();
  printf("Test 'test_down_val' Passed.\n");
}
