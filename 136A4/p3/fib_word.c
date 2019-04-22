/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include "fib_word.h"

int leng(int x) {
	int count = 0;
	while (x != 0) {
		x /= 2;
		count++;
	}
	return count;
}

int twice(int x, int times) {
	int ans = x;
	for (int i = 0; i < times; ++i) 
		ans *= 2;
	return ans;
}

bool fib_word(int s0, int s1, int word) {
	int ans = 0;
	while (ans <= word) {
		ans = twice(s1, leng(s0)) + s0;
		if (ans == word) return true;
		s0 = s1;
		s1 = ans;
	}
	return false;
}
