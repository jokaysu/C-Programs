/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include "basic_pointer.h"

int *down_value (int *x, int *y) {
	if (*x == *y) return NULL;
	int *t;
	if (*x > *y) {
		t = x;
		*x = *y;
	} else {
		t = y;
		*y = *x;
	}
	return t;
}

struct posn *up_value(struct posn *p1, struct posn *p2) {
	int sum1 = p1->x + p1->y;
	int sum2 = p2->x + p2->y;
	if (sum1 == sum2) return NULL;
	struct posn *t;
	if (sum1 > sum2) {
		t = p2;
		p2->x = p1->x;
		p2->y = p1->y;
	} else {
		t = p1;
		p1->x = p2->x;
		p1->y = p2->y;
	}
	return t;
}

int read_two(int *n1, int *n2) {
	int count = 0;
	int r = readnat();
	if (r < 0) return count;
	count++;
	*n1 = r;
	r = readnat();
	if (r < 0) return count;
	count++;
	*n2 = r;
	return count;
}

bool sum_and_range(int n, int *sum, int *smallest, int *largest) {
	*smallest = 0;
	*largest = 0;
	*sum = 0;
	int r = readnat();
	if (r < 0) return true;
	*smallest = r;
	*largest = r;
	*sum = r;
	for (int i = 1; i < n; ++i) {
		r = readnat();
		if (r < 0) return true;
		*sum += r;
		if (r < *smallest) *smallest = r;
		if (r > *largest) *largest = r;
	}
	return false;
}
