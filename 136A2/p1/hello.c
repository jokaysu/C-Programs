/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// We encourage you to write your own tests.
// Review Tutorial 2 slides "Run vs. Test"  
  
// WRITE YOUR CODE BELOW
  
#include <stdio.h>

int main() {
	printf("Hello,\n\n");
	printf("This is a test to see if you can use the C ");
	const int sub = 136;
	printf("printf function in CS %d.\n\n", sub);
	printf("Watch your spacing very carefully.\n");
	printf("                   ~~~~~~~~~~~~~~\n\n");
	printf("You can assume there are no spaces at the end of the lines.\n\n");
	printf("One restriction: you cannot use numbers directly.\n\n");
	printf("So, in order to print the fun number ");
	const int n = 1337;
	const int m = 4010;
	printf("%d and %d, you must use %%d.\n\n", n, m);
	printf("Also, please define:\n\n");
	printf("const int n = %d;\n\n", n);
	printf("const int m = %d;\n\n", m);
	printf("And then use m and n (and %%d) to print:\n");
	printf("\"The sum of %d and %d is %d!\".\n\n", n, m, n + m);
	printf("Don't forget to put a newline (\\n) ");
	printf("at the end of the last line.\n");
	return 0;
}