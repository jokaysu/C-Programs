//test.c
#include "mean-three.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>

int main() {
	assert(mean3(1, 2, 5) == 2);
	assert(mean3(INT_MAX, INT_MAX, INT_MAX) == INT_MAX);
	assert(mean3(INT_MAX, INT_MAX - 1, INT_MAX - 1) == INT_MAX - 1);
	assert(mean3(INT_MIN, INT_MIN + 1, INT_MIN + 1) == INT_MIN + 1);
	printf("Passed.\n");
	return 0;
}