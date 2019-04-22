#include <assert.h>
#include "rational.h"

// See interface for purpose statement and requirements
struct rational R(int n, int d) {
  assert(d != 0);
  const struct rational r = {n, d};
  return r;
}

// Your code below

struct rational simplifyacc(int a, int b, int d) {
  if (a == 0) return R(0, 1);
	if (d > a || d > b) return R(a, b);
	if (a % d == 0 && b % d == 0) 
		return simplifyacc(a / d, b / d, d);
		else return simplifyacc(a, b, d + 1);
}

struct rational simplify(int n, int d) {
	if (d < 0) {
		n = -n;
		d = -d;
	}
	return simplifyacc(n, d, 2);
}

struct rational r_add(struct rational a, struct rational b) {
	return simplify(a.num * b.den + a.den * b.num, a.den * b.den);
}

struct rational r_sub(struct rational a, struct rational b) {
	return simplify(a.num * b.den - a.den * b.num, a.den * b.den);
}

struct rational r_mult(struct rational a, struct rational b) {
	return simplify(a.num * b.num, a.den * b.den);
}

struct rational r_div(struct rational a, struct rational b) {
	return simplify(a.num * b.den, a.den * b.num);
}

bool r_equal(struct rational a, struct rational b) {
	struct rational c = simplify(a.num, a.den);
	struct rational d = simplify(b.num, b.den);
	return (c.num == d.num && c.den == d.den);
}

