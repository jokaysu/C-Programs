#include <assert.h>
#include <stdio.h>
#include "bank.h"

int main() {
	deposit(100000);
	withdrawal(40000);
	print_balance();
	print_limit();
	withdrawal(40000);
	print_balance();
	print_limit();
	new_day();
	print_balance();
	print_limit();
	withdrawal(40000);
	print_balance();
	print_limit();
	new_day();
	print_balance();
	print_limit();
	return 0;
}