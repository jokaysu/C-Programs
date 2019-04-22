/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// Click "ADD TEST..." to add your own test cases

#include "readnat.h"
#include <stdio.h>

int myAbs(int x) {
	if (x < 0) return -x;
		else return x;
}

int main() {
	int n = readnat();
	if (n == 0) {
		printf("%d\n", 0);
		return 0;
	}
	int m = readnat();
	int ans, diff, i, r;
	while (m != 0) {
		ans = readnat();
		diff = myAbs(ans - n);
		for (i = 1; i < m; ++i) {
			r = readnat();
			if (myAbs(r - n) < diff) {
				ans = r;
				diff = myAbs(ans - n);
			}
		}
		printf("%d\n", ans);	
		m = readnat();
	}
	return 0;
}
