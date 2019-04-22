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

#include "divisors.h"

void divacc(const int sofar, const int n) {
	if (sofar == n) myPrintEnd(n);
		else {
			if (n % sofar == 0) myPrint(sofar);
			divacc(sofar + 1, n);
		}
}

void divisors(const int n) {
	divacc(1, n);
} 
