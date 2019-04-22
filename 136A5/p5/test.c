#include <assert.h>
#include <stdio.h>
#include "sequence.h"
#include "seq-tools.h"

// Write your tests here

void case1() {
  struct Sequence *s = Sequence_create();
  printf("Inserting 10 elements..\n");
  assert (Sequence_length(s) == 0);
  for (int i=0; i < 10; ++i) {
    Sequence_insert_at(s, i, i*i);
  }
  printf("After:\n");
  Sequence_print(s);
  printf("Checking index 4..\n");
  assert(Sequence_item_at(s, 4) == 16);
  printf("Removing index 2..\n");
  Sequence_remove_at(s, 2);
  printf("After:\n");
  Sequence_print(s);
  printf("Inserting to index 3..\n");
  assert(Sequence_item_at(s, 3) == 16);
  printf("Clearing Sequence..\n");
  Sequence_clear(s);
  printf("After:\n");
  Sequence_print(s);
}

int main(void) {
  printf("Running..\n");
  case1();
  printf("Passed.\n");
}
