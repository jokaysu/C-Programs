/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// Click "ADD TEST..." to add your own test cases

#include "date.h"
#include <assert.h>

//isLeapYear(y) determines if y is a leap year
bool isLeapYear(const int y) {
	if (y % 100 == 0) {
		if (y % 400 == 0) return true;
			else return false;
	}
	else {
		if (y % 4 == 0) return true;
			else return false;
	}
}

//daysin(m, y) returns the days in m-th months in y year
int daysin(const int m, const int y) {
	if (m == 1) return 31;
	if (m == 2) {
		if (isLeapYear(y)) return 29;
			else return 28;
	}
	if (m == 3) return 31;
	if (m == 4) return 30;
	if (m == 5) return 31;
	if (m == 6) return 30;
	if (m == 7) return 31;
	if (m == 8) return 31;
	if (m == 9) return 30;
	if (m == 10) return 31;
	if (m == 11) return 30;
	if (m == 12) return 31;
	return 0;
}

bool is_valid(const struct date d) {
	if (d.month > 12) return false;
	if (d.day > daysin(d.month, d.year)) return false;
	return true;
}

bool d_eq(const struct date d1, const struct date d2) {
	assert(is_valid(d1));
	assert(is_valid(d2));
	if ((d1.day == d2.day) && (d1.month == d2.month) && (d1.year == d2.year))
		return true;
	else return false;
}

bool greaterthan(const struct date d1, const struct date d2) {
	assert(is_valid(d1));
	assert(is_valid(d2));
	if (d1.year > d2.year) return true;
	if (d1.year < d2.year) return false;
	if (d1.month > d2.month) return true;
	if (d1.month < d2.month) return false;
	if (d1.day > d2.day) return true;
		else return false;
}

