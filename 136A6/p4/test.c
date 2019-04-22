#include "sudoku.h"
#include <assert.h>
#include <stdbool.h>

int main() {
	char b1[82] = "53..7....6..195....98....6.8...6...34..8.3..17...2...6.6....28....419..5....8..79";
	print_board(b1); 
	char b2[82] = "538.7....6..195....98....6.8...6...34..8.3..17...2...6.6....28....419..5....8..79";
	assert(is_valid(b1) == true);
	assert(is_valid(b2) == false);
	printf("Passed.\n");
	return 0;
}