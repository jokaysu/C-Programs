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
	int r = readnat();
	if (r == -1) {
		printf("%d\n", -1);
		return 0;
	}
	int lar = r;
	while (r != -1) {
		if (r > lar) lar = r;
		r = readnat();
	}
	printf("%d\n", lar);
	return 0;
}
