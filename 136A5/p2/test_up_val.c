#include <assert.h>
#include "basic_pointer.h"
#include <stdlib.h>
#include <stdio.h>

void case1() {
  struct posn small = {.x = 1, .y = 2};
  struct posn big = {.x = 3, .y = 4};
  assert(up_value(&small, &big) == &small);
  assert(big.x == small.x);
  assert(big.y == small.y);
  printf("Case 1 Passed.\n");
}

void case2() {
  // Add your test
  struct posn small = {.x = 1, .y = 2};
  struct posn big = {.x = 3, .y = 4};
  printf("Case 2 Passed.\n");
}

int main() {
  printf("Running 'test_up_val':\n");
  case1();
  // case2();
  printf("Test 'test_up_val' Passed.\n");
}
