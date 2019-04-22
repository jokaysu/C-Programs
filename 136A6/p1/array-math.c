/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW

#include "array-math.h"

int dot_product(const int a[], const int b[], int s) {
	int sum = 0;
	for (int i = 0; i < s; ++i) 
		sum += a[i] * b[i];
	return sum;
}

bool is_orthogonal(const int a[], const int b[], int s) {
	return (dot_product(a , b, s) == 0);
}

void add_to_vector(const int a[], const int b[], int c[], int s) {
	for (int i = 0; i < s; ++i) 
		c[i] = a[i] + b[i];
}

//check if all elements are zero
bool isAllZero(const int x[], int s) {
	for (int i = 0; i < s; ++i) 
		if (x[i] != 0) return false;
	return true;
}

bool is_multiple(const int a[], const int b[], int s) {

	int t = 0;
	while (a[t] == 0 && b[t] == 0) t++;
	if (a[t] == 0) return isAllZero(a, s);
	if (b[t] == 0) return isAllZero(b, s);

	int div = a[t] / b[t];
	int i;
	bool flag1 = true;
	for (i = t; i < s; ++i) 
		if (b[i] * div != a[i]) {
			flag1 = false;
			break;
		}
	div = b[t] / a[t];
	bool flag2 = true;
	for (i = t + 1; i < s; ++i) 
		if (a[i] * div != b[i]) {
			flag2 = false;
			break;
		}
	return (flag1 || flag2);
}
