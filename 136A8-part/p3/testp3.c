#include "squeue.h"
#include <stdio.h>
#include <assert.h>

int main() {
	struct squeue *q = squeue_create();
	assert(squeue_is_empty(q));
	squeue_add(1, q);
	squeue_add(2, q);
	squeue_add(3, q);
	assert(!squeue_is_empty(q));
	assert(squeue_front(q) == 1);
	assert(squeue_remove_front(q) == 1);
	assert(squeue_front(q) == 2);
	assert(squeue_remove_front(q) == 2);
	assert(squeue_remove_front(q) == 3);
	assert(squeue_is_empty(q));
	squeue_destroy(q);
	printf("pass\n");
	return 0;
}