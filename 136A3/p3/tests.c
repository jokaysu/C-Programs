#include <stdio.h>
#include <assert.h>
#include "sqrt.h"
#include "within_tolerance.h"

// This is a simple test file provided for your testing

// when working with floats and doubles,
// we don't want to have precise values in .in and .expect files

// the real test will be the assertion in test_sqrt
// we can also inspect the results manually (visually) for confirmation


const double test_tolerance = 0.001;

//test_sqrt(n) finds the square root of n, and asserts that this value squared
//             is within test_tolerance of n.
//effects: prints out a message for visual testing

void test_sqrt(const double n) {
  double s = find_sqrt(n, test_tolerance);
  printf("the sqrt of %f is %f\n", n, s);
  assert(within_tolerance(n, s * s, test_tolerance));
}


int main(void) {
  test_sqrt(9);
  test_sqrt(25);
}
