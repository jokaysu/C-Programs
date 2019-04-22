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

//largeDiv(ld, t) returns the largest number that is divisible by n
int largeDiv(const int ld, const int t) {
	const int r = readnat();
	if (r == -1) return ld;
	if ((r % t == 0) && (r > ld)) return largeDiv(r, t);
		else return largeDiv(ld, t);
}

int main() {
	const int n = readnat();
	if (n == 0) {
		printf("0\n");
		return 0;
	}
	const int ans = largeDiv(0, n);
	printf("%d\n", ans);
	return 0;
}