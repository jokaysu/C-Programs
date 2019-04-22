#include "array-resize.h"
#include <stdio.h>

int main() {
	char *t1 = replace("hello", "o", "oo");
	char *t2 = replace("hello", "oo", "OO");
	printf("test 1 is %s\n", t1);
	printf("test 2 is %s\n", t2);
	return 0;
}