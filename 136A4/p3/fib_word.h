// fib_word(s0,s1,word) returns true if word is part of a sequence where
//  s0 and s1 represent the first two elements, and the 
//  n-th element is formed by concatenating binary representations
//  of elements at (n-1) and (n-2). If word is not a part of 
//  that sequence, false is returned. 
// require: s0 > 0, s1 > 0, word > 0
#include <stdbool.h>

bool fib_word(int s0, int s1, int word);
