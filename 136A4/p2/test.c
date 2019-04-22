//test.c

#include "fib.h"
#include <assert.h>
#include <stdio.h>

int main() {
	assert(next_fib() == -1);
	assert(fib(2) == 1);
	assert(next_fib() == 2);
	assert(next_fib() == 3);
	int t = fib(45);
	assert(next_fib() == fib(46));
	printf("Passed.\n");
	return 0;
}