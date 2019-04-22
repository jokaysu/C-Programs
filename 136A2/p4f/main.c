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

// longest(cn, cl, ll) prints the length of longest sequence that
//     are in non-decreasing order
int longest(const int cn, const int cl, const int ll) {
	const int r = readnat();
	if (r == -1) return ll;
	if (r < cn) {
		return longest(r, 1, ll);
	}
	else {
		if (cl + 1 > ll) return longest(r, cl + 1, cl +1);
			else return longest(r, cl + 1, ll);
	}
}

int main() {
	const int ans = longest(0, 0, 0);
	printf("%d\n", ans);
	return 0;
}