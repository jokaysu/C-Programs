/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include "calculator_functions.h"

int plus(int *a, int *b) {
	return *a + *b;
}

int minus(int *a, int *b) {
	return *a - *b;
}

int times(int *a, int *b) {
	return *a * *b;
}

int divide(int *a, int *b) {
	return *a / *b;
}

int math(int (*f)(int *, int *), int n, int m) {
	return f(&n, &m);
}
