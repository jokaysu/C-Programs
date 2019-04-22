/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

#include "balanced.h"

bool is_balanced(char str[]) {
	struct stack *stk = create_stack();
	int l = strlen(str);
	for (int i = 0; i < l; ++i) 
		if (str[i] == '(') {
			push(str[i], stk);
		} else if(str[i] == ')') {
			if (is_empty(stk)) {
				destroy_stack(stk);
				return false;
			} else pop(stk);
		}
  	bool ans = is_empty(stk);
  	destroy_stack(stk);
	return ans;
}

