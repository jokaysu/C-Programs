#include "translation.h"
#include <assert.h>
#include <stdio.h>

// Add your own tests using assert().
// Review Tutorial 2 slides "Run vs. Test"  
  
int main(void) {
  assert(polyeval(3,5,7,2) == 29);
  assert(selector(1,2,3) == 2);
  assert(max3(3,2,1) == 3);
  assert(sumsqr1(4) == 30);
  assert(sumsqr2(4) == 30);
  assert(sumsqr3(4) == 30);
  assert(sameparity(2,4) == 1);
  printf("Passed.\n");
}
