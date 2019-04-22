#include "dyn-arrays.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

char *my_strappend(const char *s1, const char *s2) {
	char *ans = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	int l1 = strlen(s1);
	int l2 = strlen(s2);
  int i;
	for (i = 0; i < l1; ++i) ans[i] = s1[i];
	for (i = 0; i < l2; ++i) ans[i + l1] = s2[i];
	ans[l1 + l2] = '\0';
	return ans;
}

char *hex_to_bin(const char *h) {
	int l = strlen(h);
	char *ans = malloc((4 * l + 1) * sizeof(char));
  int i;
	for (i = 0; i < l; ++i) {
		if (h[i] == '0') {
			ans[4 * i] = '0';
			ans[4 * i + 1] = '0';
			ans[4 * i + 2] = '0';
			ans[4 * i + 3] = '0';
		}
		if (h[i] == '1') {
			ans[4 * i] = '0';
			ans[4 * i + 1] = '0';
			ans[4 * i + 2] = '0';
			ans[4 * i + 3] = '1';
		}
		if (h[i] == '2') {
			ans[4 * i] = '0';
			ans[4 * i + 1] = '0';
			ans[4 * i + 2] = '1';
			ans[4 * i + 3] = '0';
		}
		if (h[i] == '3') {
			ans[4 * i] = '0';
			ans[4 * i + 1] = '0';
			ans[4 * i + 2] = '1';
			ans[4 * i + 3] = '1';
		}
		if (h[i] == '4') {
			ans[4 * i] = '0';
			ans[4 * i + 1] = '1';
			ans[4 * i + 2] = '0';
			ans[4 * i + 3] = '0';
		}
		if (h[i] == '5') {
			ans[4 * i] = '0';
			ans[4 * i + 1] = '1';
			ans[4 * i + 2] = '0';
			ans[4 * i + 3] = '1';
		}
		if (h[i] == '6') {
			ans[4 * i] = '0';
			ans[4 * i + 1] = '1';
			ans[4 * i + 2] = '1';
			ans[4 * i + 3] = '0';
		}
		if (h[i] == '7') {
			ans[4 * i] = '0';
			ans[4 * i + 1] = '1';
			ans[4 * i + 2] = '1';
			ans[4 * i + 3] = '1';
		}
		if (h[i] == '8') {
			ans[4 * i] = '1';
			ans[4 * i + 1] = '0';
			ans[4 * i + 2] = '0';
			ans[4 * i + 3] = '0';
		}
		if (h[i] == '9') {
			ans[4 * i] = '1';
			ans[4 * i + 1] = '0';
			ans[4 * i + 2] = '0';
			ans[4 * i + 3] = '1';
		}
		if (h[i] == 'A') {
			ans[4 * i] = '1';
			ans[4 * i + 1] = '0';
			ans[4 * i + 2] = '1';
			ans[4 * i + 3] = '0';
		}
		if (h[i] == 'B') {
			ans[4 * i] = '1';
			ans[4 * i + 1] = '0';
			ans[4 * i + 2] = '1';
			ans[4 * i + 3] = '1';
		}
		if (h[i] == 'C') {
			ans[4 * i] = '1';
			ans[4 * i + 1] = '1';
			ans[4 * i + 2] = '0';
			ans[4 * i + 3] = '0';
		}
		if (h[i] == 'D') {
			ans[4 * i] = '1';
			ans[4 * i + 1] = '1';
			ans[4 * i + 2] = '0';
			ans[4 * i + 3] = '1';
		}
		if (h[i] == 'E') {
			ans[4 * i] = '1';
			ans[4 * i + 1] = '1';
			ans[4 * i + 2] = '1';
			ans[4 * i + 3] = '0';
		}
		if (h[i] == 'F') {
			ans[4 * i] = '1';
			ans[4 * i + 1] = '1';
			ans[4 * i + 2] = '1';
			ans[4 * i + 3] = '1';
		}
	}
  ans[4 * l] = '\0';
	return ans;
}

