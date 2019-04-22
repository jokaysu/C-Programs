/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// We encourage you to write your own tests.
// Review Tutorial 2 slides "Run vs. Test"  
  
// WRITE YOUR CODE BELOW

#include "math_operations.h"

// multiplyacc(m, a, b) evaluates a * b
int multiplyacc(const int m, const int a, const int b) {
	if (b == 0) return m;
		else return multiplyacc(m + a, a, b - 1);
}

int multiply(const int a, const int b) {
	return multiplyacc(0, a, b);
}

// divideacc(d, a, b) evaluates a / b
int divideacc(const int d, const int a, const int b) {
	if (a < b) return d;
		else return divideacc(d + 1, a - b, b);
}

int divide(const int a, const int b) {
	if (b < 0) return 0 - divide(a, 0 - b);
	if (a < 0) return 0 - divide(0 - a, b);
	return divideacc(0, a, b);
}