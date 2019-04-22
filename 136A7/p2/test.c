#include "balanced.h"
#include <assert.h>
#include <stdio.h>

int main() {
	assert(is_balanced("()"));
	assert(is_balanced("((hello))"));
	assert(!is_balanced(")("));
	assert(!is_balanced("((hello)"));
	assert(is_balanced("((())())"));
	assert(!is_balanced("((())))"));
	printf("passed\n");
}
