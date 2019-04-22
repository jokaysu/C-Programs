/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include "safe-to-add.h"

bool safe_to_add(int a, int b) {
	if (a > 0 && b > 0) {
		int c = INT_MAX - a;
		if (c >= b) return true;
			else return false;
	} else if (a < 0 && b < 0) {
		int d = INT_MIN - a;
		if (d <= b) return true;
			else return false; 
	} else return true;
}
