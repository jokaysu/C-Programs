/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chznehng Su
    login ID: c28su
*/

// We encourage you to write your own tests.
// Review Tutorial 2 slides "Run vs. Test"  
  
// WRITE YOUR CODE BELOW
#include "fibonacci.h"

void fibanacciacc(int a, int b, int count) {
	if (count == 1) myPrintEnd(a + b);
		else {
			myPrint(a + b);
			fibanacciacc(b, a + b, count - 1);
		}
}

void fibonacci(int n) {
	if (n == 1 || n == 2) {
		if (n == 1) myPrintEnd(0);
			else {
				myPrint(0);
				myPrintEnd(1);
			}
	} else {
		myPrint(0);
		myPrint(1);
		fibanacciacc(0, 1, n - 2);
	}
}  
