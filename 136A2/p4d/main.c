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

// diff(d, ma, mi) evaluates max - min
int diff(const int d, const int ma, const int mi) {
	const int r = readnat();
	if (r == -1) return d;
	if (r > ma) return diff(r - mi, r, mi);
	if (r < mi) return diff(ma - r, ma, r);
	return diff(d, ma, mi);
}

int main() {
	const int f = readnat();
	const int ans = diff(0, f, f);
	printf("%d\n", ans);
	return 0;
}