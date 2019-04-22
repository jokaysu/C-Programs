//tests.c

#include "fib_word.h"
#include <assert.h>
#include <stdio.h>

int main() {
	assert(fib_word(1, 16, 33));
	assert(!fib_word(1, 16, 49));
	assert(fib_word(2, 1, 13));
	assert(fib_word(2, 5, 181));
	assert(!fib_word(2, 5, 10));
	assert(!fib_word(2, 4, 17));
	assert(fib_word(2, 4, 18));
	printf("Passed.\n");
}