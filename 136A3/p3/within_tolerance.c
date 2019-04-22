#include "within_tolerance.h"
#include <assert.h>

bool within_tolerance(const double a, const double b, const double tolerance) {
  assert(tolerance >= 0);
  if (a < b) {
    return (b - a <= tolerance);
  } else {
    return (a - b <= tolerance);
  }
}
