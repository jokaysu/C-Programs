#include <stdio.h>
#include "readnat.h"

// This is a simple program that reads in natural numbers from input
// until the end of file or an invalid natural number is encountered,
// and then prints the sum of the numbers.


// read_sum(sofar) reads in natural numbers from the input,
//   returning the sum of their result and sofar.
// requires: total sum is less than 2147483647

int read_sum(const int sofar) {
  const int n = readnat();
  if (n == -1) {
    return sofar;
  } else {
    return read_sum(sofar + n);
  }
}

int main(void) {
  const int sum = read_sum(0);
  printf("%d\n", sum);
}

