#include "pq.h"
#include "pq_util.h"
#include <stdlib.h>

/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

void to_array(struct pq *pqueue, int **arr_ptr, int *len) {
	if (pq_is_empty(pqueue)) {
		*len = 0;
		return;
	}
	*len = 0;
	*arr_ptr = malloc((*len) * sizeof(int));
	while (!pq_is_empty(pqueue)) {
		*arr_ptr = realloc(*arr_ptr, ((*len) + 1) * sizeof(int));
		(*arr_ptr)[(*len)] = pq_remove(pqueue);
		(*len)++;
	}
	pq_destroy(pqueue);
}

/*
  TIME: O(n) where n is the size of pqueue
  Reason: When we use pq_add() to add an element always with
    a higher priority than the first element in the pqueue,
    pq_add() can always be done in O(1), because it always
    inserts the element in the first place.
    What we need to do is to make sure every element has higher 
    priority than those previously inserted. What I did is to 
    get their negative value stored in help[].
  Analysis:  In iteration #1, we use pq_add() as O(1), 
  	and repeat for n times. So #1 in total, runtime will be O(n).
  	In iteration #2, we use pq_add() as O(1), and repeat
  	for n times(there are n elements in all spilitted pqueue
  	combined). So #2 in total, runtime will be O(n)
*/
struct pq **k_way_split(struct pq *pqueue, const int k) {
	struct pq *help[k];
	for (int i = 0; i < k; ++i) 
		help[i] = pq_create();
	int cur = 0;
	while (!pq_is_empty(pqueue)) { // #1
		pq_add(help[cur % k], pq_front_item(pqueue), 
			0 - pq_front_priority(pqueue));
		cur++;
		pq_remove(pqueue);
	}
	pq_destroy(pqueue);
	struct pq **ans = malloc(k * sizeof(struct pq *));
	for (int i = 0; i < k; ++i) { // #2
		ans[i] = pq_create();
		while (!pq_is_empty(help[i])) {
			pq_add(ans[i], pq_front_item(help[i]), 
				0 - pq_front_priority(help[i]));
			pq_remove(help[i]);
		}
		pq_destroy(help[i]);
	}
	return ans;
}
