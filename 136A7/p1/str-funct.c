/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/
  
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "str-funct.h"
    
//bool cap(char ch) determines if ch is capital
bool cap(char ch) {
	return ('A' <= ch && ch <= 'Z');
}

//bool low(char ch) determines if ch is capital
bool low(char ch) {
	return ('a' <= ch && ch <= 'z');
}

void letter_freq_count(const char *s,int count[]) {
	int l = strlen(s);
	for (int i = 0; i < l; ++i) {
		if (cap(s[i])) count[s[i] - 'A']++;
		if (low(s[i])) count[s[i] - 'a']++;
	}
}

bool anagram(const char *s1,const char *s2) {
	int c1[26], c2[26];
	letter_freq_count(s1, c1);
	letter_freq_count(s2, c2);
	for (int i = 0; i < 26; ++i) 
		if (c1[i] != c2[i]) 
			return false;
	return true;
}

//char other(char c) returns upper-case of ch if it is lower-case,
//  or lower-case otherwise
char other(char c) {
	if ('A' <= c && c <='Z') return c - 'A' + 'a';
		else return c - 'a' + 'A';
}

int ccount(const char *strings[], int len, char ch) {
	int i, j, l;
	int ans = 0;
	for (i = 0; i < len; ++i) {
		l = strlen(strings[i]);
		for (j = 0; j < l; ++j) 
			if (strings[i][j] == ch || strings[i][j] == (other(ch)))
				ans++;
	} 
	return ans;
}
