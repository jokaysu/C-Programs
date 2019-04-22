/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/
  
// Runtime:
// Reason:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *readstr() {
	int maxlen = 1;
	int len = 0;
	char *ans = malloc(maxlen * sizeof(char));
	char r;
	int c = scanf("%c", &r);
  	bool flag = true;
	if (c != 1 || r == '\0') {
    free(ans);
    return NULL;
  	}
	while (c == 1 && r != '\n') {
    if (r != ' ') flag = false;
		ans[len] = r;
		len++;
		if (len == maxlen) {
			maxlen *= 2;
			ans = realloc(ans, maxlen * sizeof(char));
		}
		c = scanf("%c", &r);
	}
	ans[len] = '\0';
	ans = realloc(ans, (len + 1) * sizeof(char));
  	if (flag) {
    	free(ans);
    	return NULL;
  	}
	return ans;
}

int main() {
	int maxlen = 1;
	int len = 0;
	int i, j;
	char *t;
	char **a = malloc(maxlen * sizeof(char*));
	char *r = readstr();
	while (r) {
		a[len] = r;
		len++;
		if (len == maxlen) {
			maxlen *= 2;
			a = realloc(a, maxlen * sizeof(char*));
		}
		r = readstr();
	}
	//selection sort
	for (i = 0; i < len - 1; ++i)
		for (j = i + 1; j < len; ++j) 
			if (strcmp(a[i], a[j]) > 0) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	for (i = 0; i < len; ++i) {
		printf("%s\n", a[i]);
    free(a[i]);
  }
	free(a);
  	return 0;
}

