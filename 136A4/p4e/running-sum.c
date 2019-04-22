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
#include <limits.h>

int main() {
	int n = readnat();
	int sum;
	while (n != -1) {
		if (INT_MAX - sum < n) {
			printf("overflow\n");
			sum = 0;
		} else {
			sum += n;
			printf("%d\n", sum);
		}
		n = readnat();
	}
	return 0;
}
