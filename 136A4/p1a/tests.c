//tests.c
#include "safe-to-add.h"
#include <assert.h>
#include <stdio.h>

int main() {
	assert(safe_to_add(1, 2) == true);
	assert(safe_to_add(-1, INT_MIN) == false);
	assert(safe_to_add(2, INT_MIN) == true);
	assert(safe_to_add(3, INT_MAX) == false);
	assert(safe_to_add(-4, INT_MAX) == true);
	assert(safe_to_add(INT_MAX, INT_MIN) == true);
	printf("Passed.\n");
	return 0;
}