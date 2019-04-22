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

//countEven(a) returns the number of even numbers
int countEven(const int a) {
	const int r = readnat();
	if (r == -1) return a;
	if (r % 2 == 0) return countEven(a + 1);
		else return countEven(a);
}

int main() {
	const int ans = countEven(0);
	printf("%d\n", ans);
	return 0;
}