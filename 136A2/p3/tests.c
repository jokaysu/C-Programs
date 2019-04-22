#include <assert.h>
#include "math_operations.h"
#include <stdio.h>

int main(void) {
  // test your code using assert()
	assert(multiply(2, 3) == 6);
	assert(divide(-6, 2) == -3);
	assert(divide(-8, -4) == 2);
	assert(multiply(0, 9) == 0);
	printf("Pass.\n");
}
