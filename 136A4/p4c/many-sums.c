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

int main() {
	int n, m, r, sum;
	n = readnat();
	m = readnat();
	for (int i = 0; i < n; ++i) {
		sum = 0;
		for (int j = 0; j < m; ++j) {
			r = readnat();
			sum += r;
		}
		printf("%d\n", sum);
	}
	return 0;
}
