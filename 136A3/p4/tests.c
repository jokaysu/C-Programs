#include "rational.h"
#include <assert.h>
#include <stdio.h>

int main() {
    struct rational r1 = R(2, 4);
    struct rational r2 = R(3, 6);
    assert(r_equal(r_add(r1, r2), R(1, 1)));
    assert(r_equal(r_sub(r1, r2), R(0, 1)));
    assert(r_equal(r_mult(r1, r2), R(1, 4)));
    assert(r_equal(r_div(r1, r2), R(1, 1)));
    printf("Pass.\n");
    return 0;
}