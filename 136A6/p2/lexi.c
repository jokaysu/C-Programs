/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include <string.h>
#include <stdio.h>

int main() {
	char s[100], small[100], large[100];
	if (scanf("%s", s) == 0) {
		printf("NO STRINGS\n");
		return 0;
	}
	strcpy(small, s);
	strcpy(large, s);
	while (scanf("%s", s)) {
		if (strcmp(s, small) < 0) strcpy(small, s);
		if (strcmp(s, large) > 0) strcpy(large, s);
		printf("B\n");
	}
	printf("%s %s\n", small, large);
	return 0;
}
