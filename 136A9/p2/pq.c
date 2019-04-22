#include "pq.h"
#include <stdlib.h>
#include <stdio.h>

/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

struct node {
	int item;
	int prio;
	struct node *next;
	struct node *back;
};

struct pq {
	struct node *front;
	int len;
};

struct pq *pq_create(void) {
	struct pq *ans = malloc(sizeof(struct pq));
	ans->front = NULL;
	ans->len = 0;
	return ans;
}

int pq_remove(struct pq *pqueue) {
	struct node *cur = pqueue->front;
	int ans = cur->item;
	pqueue->front = cur->next;
	if (cur->next) cur->next->back = NULL;
	free(cur);
	pqueue->len--;
	return ans;
}

void pq_destroy(struct pq *pqueue) {
	struct node *cur = pqueue->front;
	struct node *del = cur;
	while (cur) {
		del = cur;
		cur = cur->next;
		free(del);
	}
	free(pqueue);
}

bool pq_is_empty(const struct pq *pqueue) {
	return pqueue->len == 0;
}

int pq_front_priority(const struct pq *pqueue) {
	return pqueue->front->prio;
}

int pq_front_item(const struct pq *pqueue) {
	return pqueue->front->item;
}

int pq_length(const struct pq *pqueue) {
	return pqueue->len;
}

void pq_add(struct pq *pqueue, int item, int priority) {
	struct node *add = malloc(sizeof(struct node));
	add->item = item;
	add->prio = priority;
	struct node *cur = pqueue->front;
	if (!cur || priority < cur->prio) {
		add->next = cur;
		add->back = NULL;
		if (cur) cur->back = add;
		pqueue->front = add;
		pqueue->len++;
		return;
	}
	while (priority >= cur->prio && cur->next) cur = cur->next;
	if (priority < cur->prio) {
		add->next = cur;
		add->back = cur->back;
		cur->back->next = add;
		cur->back = add;
	} else {
		add->next = cur->next;
		add->back = cur;
		cur->next = add;
	}
	pqueue->len++;
}

void pq_print(const struct pq *pqueue) {
	struct node *tar = pqueue->front;
	struct node *cur = tar;
	int pr = 0;
	while (tar) {
		pr = tar->prio;
		printf("[%d]", pr);
		cur = tar;
		while (cur && cur->prio == pr) {
			printf(" %d", cur->item);
			cur = cur->next;
		}
		tar = cur;
		printf("\n");
	}
}
