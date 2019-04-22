#include "squeue.h"
#include <stdlib.h>

/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

struct squeue *squeue_create(void) {
  	struct squeue *q = malloc(2 * sizeof(struct stack *) + sizeof(int));
  	q->main = create_stack();
  	q->help = create_stack();
  	q->front = 0;
  	return q;
}

bool squeue_is_empty(const struct squeue *q) {
	return stack_is_empty(q->main);
}

void squeue_add(int item, struct squeue *q) {
	if (squeue_is_empty(q)) q->front = item;
	stack_push(item, q->main);
}

int squeue_front(const struct squeue *q) {
	return q->front;
}

int squeue_remove_front(struct squeue *q) {
	while(!squeue_is_empty(q)) 
		stack_push(stack_pop(q->main), q->help);
	int ans = stack_pop(q->help);
	if (!stack_is_empty(q->help)) q->front = stack_top(q->help);
	while(!stack_is_empty(q->help))
		stack_push(stack_pop(q->help), q->main);
	return ans;
}

void squeue_destroy(struct squeue *q) {
	stack_destroy(q->main);
	stack_destroy(q->help);
	q->front = 0;
	free(q);
}

