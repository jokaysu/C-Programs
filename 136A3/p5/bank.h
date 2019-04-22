#include <stdio.h>
#include <stdbool.h>

// A module for managing a bank account

// deposit(amount) increases the bank account by amount cents. 
// requires: amount > 0
// effects: modifies the bank account balance
void deposit(int amount);


// withdrawal(amount) decreases the bank account by amount cents if
//   it does not exceed the daily withdrawal limit.
//   If the request would exceed the daily withdrawal limit,
//   a message is displayed: "no withdrawal: daily limit exceeded" + newline
//   note: withdrawals can occur if there are insufficient funds
//   (i.e., withdrawal can cause the account to have a negative balance).
// requires: amount > 0
// effects: may modify the bank account balance
//          may display a message
//          may modify the remaining withdrawal limit
void withdrawal(int amount);


// print_balance() prints the current balance, followed by a newline
// examples:
//   "balance: $0.00" 
//   "balance: $100.00"
//   "balance: -$0.01"
// effects: displays a message
void print_balance(void);


// print_limit() prints the remaining daily withdrawal limit
//   followed by a newline
// examples:
//   "limit: $1000.00" 
//   "limit: $0.00"
// effects: displays a message
void print_limit(void); 


// new_day() updates the bank account for a new day:
//   * If the account has a non-negative balance, 
//     the daily withdrawal limit is reset back to the maximum value.
//   * If the account has a negative balance, 
//     the daily withdrawal limit is set to zero, and 
//     an overdraft penalty of $5 is removed from balance, and
//     a message is displayed: "Warning! Overdraft" + newline
//   effects: may modify the remaining withdrawal limit
//            may modify the bank account balance
//            may display a message
void new_day(void);


//*******************************
// BONUS QUESTION
//*******************************

// request_limit_increase() may permanently increase the
//   maximum withdrawal limit by $100
//   effects: may change the daily withdrawal limit
void request_limit_increase(void);
