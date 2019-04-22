/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include "mean-three.h"

int mean3(int a, int b, int c) {
	int aa = a % 3;
	int bb = b % 3;
	int cc = c % 3;
	return (a / 3 + b / 3 + c / 3 + (aa + bb + cc) / 3);
}
