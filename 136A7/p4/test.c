#include "fun-with-strings.h"
#include <assert.h>
#include <stdio.h>

int main() {
	assert(is_palindrome("tacocat"));
	assert(is_palindrome("noon"));
	assert(!is_palindrome("dooD"));
	assert(!is_palindrome("MOoM"));
	printf("a correct\n");
	char s1a[] = "computer";
	char s1o[] = "computeray";
	char s1b[] = "omputercay";
	char s2a[] = "science";
	char s2o[] = "scienceay";
	char s2b[] = "ciencesay";
	pig_latin(s1a, s1o);
	pig_latin(s2a, s2o);
	printf("Test for b:\n");
	printf("Test1: %s %s\n", s1o, s1b);
	printf("Test2: %s %s\n", s2o, s2b);
	assert(mostfreq("abcbcc") == 'c');
	assert(mostfreq("abba") == 'a');
	printf("c correct\n");
	printf("All Passed.\n");
}