// this module provides functions translated from Racket

// polyeval(a, b, c, x) evaluates ax^2 + bx + c
int polyeval(const int a, const int b, const int c, const int x);

// selector(a, x, y) produces x if a is non-zero, and y otherwise
int selector(const int a, const int x, const int y);

// max3(a, b, c) produces the max of a, b and c
int max3(const int a, const int b, const int c);

// sumsqr1(n) produces the sum of 1^2, 2^2, .... n^2
int sumsqr1(const int n);

// sumsqr2(n) produces the sum of 1^2, 2^2, .... n^2
int sumsqr2(const int n);

// sumsqr3(n) produces the sum of 1^2, 2^2, .... n^2
int sumsqr3(const int n);

// sameparity(a, b) produces 1 if a and b have the same parity (odd/even)
//   or 0 otherwise
int sameparity(const int a, const int b);
