/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// Click "ADD TEST..." to add your own test cases

#include <stdio.h>
#include "readnat.h"

//readAndMax(a) reads the natural numbers and returns the largest one
int readAndMax(const int a) {
	const int r = readnat();
	if (r == -1) return a;
	if (r > a) return readAndMax(r);
		else return readAndMax(a);
}

int main() {
	const int ans = readAndMax(0);
	printf("%d\n", ans);
	return 0;
}