// rational.h
// module for working with rational numbers

#include <stdbool.h>

// a rational structure represents a rational number 
//   with a numerator (num) and a denominator (den):
// * for example, num = 1, den = 3 corresponds to a third (1/3)
// * For a valid rational, den must not be 0
struct rational {
  int num;
  int den;
};

// R(n,d) returns the rational representing n/d
// requires: d is non-zero
struct rational R(int n, int d);


// NOTE: for all functions below, the return values will be *simplified*
//       the arguments may not be simplified

// Rules for simplifying rationals:
// * all integers (including zero) must have a den of 1
// * all rationals will use the lowest possible den,
//   so (2/4) will never be returned: instead, (1/2) would be returned
// * the den cannot be negative.  (-1/-2) or (1/-2) are not simplified

// simplify(n,d) returns the simplified rational, according to the rules above. 
struct rational simplify(int n, int d); 

// r_add(a,b) returns a rational representing the sum a + b
// requires: a,b are valid rationals
struct rational r_add(struct rational a, struct rational b);

// r_sub(a,b) returns a rational representing the difference a - b
// requires: a,b are valid rationals
struct rational r_sub(struct rational a, struct rational b);

// r_mult(a,b) returns a rational representing the product a * b
// requires: a,b are valid rationals
struct rational r_mult(struct rational a, struct rational b);

// r_div(a,b) returns a rational representing the division a / b
// requires: a,b are valid rationals and b is non-zero
struct rational r_div(struct rational a, struct rational b);

// r_equal(a,b) returns 1 if a and b represent the same rational number
//   and 0 otherwise
// requires: a,b are valid rationals
bool r_equal(struct rational a, struct rational b);

