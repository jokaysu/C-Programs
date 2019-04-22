#include <assert.h>
#include <stdio.h>
#include "date.h"

int main(void) {
  // test your code using assert()
  const struct date date1 = {6,31,2016};
  const struct date date2 = {12,18,2016};
  const struct date date3 = {12,18,2016};
  const struct date date4 = {2,29,2100};
  const struct date date5 = {2,29,2000};
  const struct date date6 = {2,29,2012};
  const struct date date7 = {12,20,2016};
  
  assert(is_valid(date1) == false);
  assert(d_eq(date2 ,date3) == true);
  assert(is_valid(date4) == false);
  assert(is_valid(date5) == true);
  assert(is_valid(date6) == true);
  assert(greaterthan(date2, date7) == false);
  assert(greaterthan(date7, date2) == true);
  assert(greaterthan(date7, date5) == true);
  assert(greaterthan(date5, date6) == false);
  printf("Passed.\n");
}

