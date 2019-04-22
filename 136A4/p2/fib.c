/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include "fib.h"

bool never = true;
int a[50];
int t; // target

int fib(int n) {
	never = false;
	t = n;
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i <= 46; ++i) 
		a[i] = a[i - 1] + a[i - 2];
	return a[n];
}

int next_fib(void) {
	if (never) return -1;
		else return a[++t];
}
