/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include "calculator_functions.h" 
#include <stdio.h>

int main() {
	int n1, n2;
	char f;
	printf("Please enter your Math problem:\n");
	while (scanf("%d %c %d", &n1, &f, &n2) == 3) {
		int (*t)(int *, int *);
		if (f == '+') t = &plus;
		if (f == '-') t = &minus;
		if (f == '*') t = &times;
		if (f == '/') t = &divide;
		printf("%d %c %d = %d\n", n1, f, n2, 
			math(t, n1, n2));
		printf("Please enter your Math problem:\n");
	}
	printf("Invalid Input. Exiting.\n");
	return 0;
}

