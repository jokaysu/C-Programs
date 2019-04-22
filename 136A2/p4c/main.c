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

//larger(c, t) counts the number that larger than t
int larger(const int c, const int t) {
	const int r = readnat();
	if (r == -1) return c;
	if (r > t) return larger(c + 1, t);
		else return larger(c, t);
}

int main() {
	const int n = readnat();
	const int ans = larger(0, n);
	printf("%d\n", ans);
	return 0;
}