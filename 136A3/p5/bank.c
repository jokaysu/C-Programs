#include "bank.h"
#include <stdbool.h>

/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// We encourage you to write your own tests.
// Review Tutorial 2 slides "Run vs. Test"  
  
// WRITE YOUR CODE BELOW
  
static int balance = 0;
int c3;

void deposit(int amount) {
  balance += amount;
  if (balance < 50000) c3 = 0;
}

// DO NOT MODIFY THE ABOVE TWO DEFINITIONS
// COMPLETE THE IMPLEMENTATION BELOW:
bool b1, b3, b4;
bool b2 = true;
int c4;
bool b5 = true;

int maxLimit = 100000;
int limit = 100000;

void withdrawal(int amount) {
	b2 = false;
	if (amount > limit) 
		printf("no withdrawal: daily limit exceeded\n");
		else {
			balance -= amount;
			limit -= amount;
		}
	if (balance < 50000) c3 = 0;
	if (balance < -100000) b5 = false;
}

void print_balance(void) {
	if (balance < 0) printf("balance: -$%d.%02d\n", (0 - balance) / 100, 
		(0 - balance) - (0 - balance) / 100 * 100);
		else printf("balance: $%d.%02d\n", balance / 100, 
			balance - balance / 100 * 100);
}

void print_limit(void) {
	printf("limit: $%d.%02d\n", limit / 100, 
			limit - limit / 100 * 100);
}

void new_day(void) {
	b2 = true;
	if (balance < 50000) c3 = 0;
		else c3++;
	if (balance < 0) {
		limit = 0;
		balance -= 500;
		printf("Warning! Overdraft\n");
	} else limit = maxLimit;
	if (balance < -100000) b5 = false;
	c4++;
}

// KEEP THIS DEFINIITON IF YOU CHOOSE NOT TO DO THE BONUS

void request_limit_increase(void) {
  	if (balance >= 100000) b1 = true;
  		else b1 = false;
  	if (c3 >= 5) b3 = true;
  		else b3 = false;
  	if (c4 >= 10) b4 = true;
  		else b4 = false;
  	if (b1 && b2 && b3 && b4 && b5) {
  		maxLimit += 10000;
  		c4 = 0;
  	}
}

