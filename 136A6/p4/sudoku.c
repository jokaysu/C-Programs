/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include "sudoku.h"

//printUdS prints 25 "_" (a line) and a "\n"
void printUdS() {
	for (int i = 0; i < 25; ++i)
		printf("_");
	printf("\n");
}

//printLine print the l line of board b
void printLine(const char *b, int l) {
	for (int i = 0; i < 9; ++i) {
		if (i % 3 == 0) printf("| ");
		printf("%c ", b[9 * l + i]);
	}
	printf("|\n");
}

void print_board(const char *board) {
	for (int i = 0; i < 9; ++i) {
		if (i % 3 == 0) printUdS();
		printLine(board, i);
	}
	printUdS();
}

bool ruleA(const int b[]) {
	int i, j;
	for (i = 0; i < 9; ++i) 
		for (j = 0; j < 9; ++j) 
			if (b[i][j] < 0 || b[i][j] > 9) return false;
	return true;
}

bool ruleB(const int b[]) {
	int i, j;
	bool flag[10];
	for (i = 0; i < 9; ++i) {
		for (j = 1; j <= 9; ++j) flag[j] = false;
		for (j = 0; j < 9; ++j) 
			if (flag[b[i][j]]) return false;
				else flag[b[i][j]] = true;
	}
	return true;
}

bool ruleC(const int b[]) {
	int i, j;
	bool flag[10];
	for (j = 0; j < 9; ++j) {
		for (i = 1; i <= 9; ++i) flag[i] = false;
		for (i = 0; i < 9; ++i)
			if (flag[b[i][j]]) return false;
				else flag[b[i][j]] = true;
	}
	return true;
}

bool checkSmall(const int b[], int x, int y) {
	int i, j;
	bool flag[10];
	for (i = 1; i <= 9; ++i) flag[i] = false;
	for (i = x; i < x + 3; ++i)
		for (j = y; j < y + 3; ++j) 
			if (flag[b[i][j]]) return false;
				else flag[b[i][j]] = true;
	return true;
}

bool ruleD(const int b[]) {
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j) 
			if (!checkSmall(b, 3 * i, 3 * j)) 
				return false;
	return true;
}

bool is_valid(const char *board) {
	int a[9][9], i , j;
	for (i = 0; i < 9; ++i) 
		for (j = 0; j < 9; ++j) {
			if (board[9 * i + j] == '0') return false; // against rule a
			if (board[9 * i + j] == '.') a[i][j] = 0;
				else a[i][j] = board[9 * i + j] - '0';
		}
	return ruleA(a) && ruleB(a) && ruleC(a) && ruleD(a);
}
