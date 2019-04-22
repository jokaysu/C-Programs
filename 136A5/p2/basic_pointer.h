#include "user_io.h"
#include <limits.h>
#include <stdbool.h>

int *down_value (int *x, int *y);

struct posn {
	int x;
	int y;
};

struct posn *up_value(struct posn *p1, struct posn *p2);

int read_two(int *n1, int *n2);

bool sum_and_range(int n, int *sum, int *smallest, int *largest)
