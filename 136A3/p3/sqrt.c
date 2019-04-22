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
#include "sqrt.h"

double findSqrtAcc(double x, double n, double t) {
	if (within_tolerance(x * x, n, t)) return x;
		else return findSqrtAcc((x + n / x) / 2, n, t);
}

double find_sqrt(double n, double tolerance) {
	return findSqrtAcc(1, n, tolerance);
}
