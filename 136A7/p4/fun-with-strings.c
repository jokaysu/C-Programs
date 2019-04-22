/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/
  
#include <string.h>
#include "fun-with-strings.h"

// is_palindrome(str) determines if str is a palindrome
// Time: O(n), n is the length of str
bool is_palindrome(const char *str) {
	int l = strlen(str);
	int mid = l / 2;
	for (int i = 0; i < mid; ++i) 
		if (str[i] != str[l - 1 - i])
			return false;
	return true;
}

// pig_latin(in, out) stores the Pig Latin of "in" in "out"
// Requires: "out" is large enough to store the result
// Effects: modifies output
// Time: O(n), n is the length of "in"
void pig_latin(const char *in, char *out) {
	int l = strlen(in);
	for (int i = 0; i < l - 1; ++i) 
		out[i] = in[i + 1];
	out[l - 1] = in[0];
	out[l] = 'a';
	out[l + 1] = 'y';
}

// mostfreq(str) finds the character that occurs the most frequently in str
// Time: O(n)
// Reason: In both i from 1 to l loop, it is O(1) inside. Then runtime is O(n)
char mostfreq(const char *str) {
	int l = strlen(str);
	int a[128], i;
	for (i = 32; i < 127; i++) 
		a[i] = 0;
	for (i = 0; i < l; ++i)
		a[str[i]]++;
	int t = a[str[0]];
	char ans = str[0];
	for (i = 1; i < l; ++i)
		if (a[str[i]] > t) {
			t = a[str[i]];
			ans = str[i];
		}
	return ans;
}
