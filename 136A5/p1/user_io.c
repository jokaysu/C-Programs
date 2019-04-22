/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include "user_io.h"

int readnat() {
	int n;
	while (scanf("%d", &n) == 1) 
		if (n < 0) return -2;
			else return n;
	return -1;
}

float readnonnegfloat() {
	float f;
	while (scanf("%f", &f) == 1) 
		if (f < 0) return -2;
			else return f;
	return -1;
}
