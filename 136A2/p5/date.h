// date.h
// Module for working with date which consists of day,month and year values

#include <stdbool.h>

struct date{
	int month;
	int day;
	int year;
};

//is_valid(d) determines if d is a valid date
bool is_valid(const struct date d);

//d_eq(d1,d2) determines if date d1 and d2 are equal
//requires: d1, d2 are valid dates
bool d_eq(const struct date d1, const struct date d2);

//greaterthan(d1,d2) determines if d1 is after the d2 date
//requires: d1, d2 are valid dates
bool greaterthan(const struct date d1, const struct date d2);

