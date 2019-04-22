#include "array-math.h"
#include <assert.h>
#include <stdio.h>

int main() {
	int a[] = {1, 2};
	int b[] = {3, 4};
	int c[] = {0, 0};
	int d[] = {4, 6};
	int e[] = {2, 3};
	int f[] = {0, 1};
	int g[] = {0, 2};
	int h[] = {0, 0};
	assert(dot_product(a, b, 2) == 11);
	assert(is_orthogonal(a, b, 2) == false);
	assert(is_orthogonal(b, c, 2) == true);
	add_to_vector(a, b , c, 2);
	assert(c[0] == d[0] && c[1] == d[1]);
	assert(is_multiple(d, e, 2));
	assert(is_multiple(c, d, 2));
	assert(is_multiple(e, f, 2));
	assert(!is_multiple(e, g, 2));
	assert(!is_multiple(e, b, 2));
	assert(is_multiple(c, h, 2));
	printf("passed.\n");
}