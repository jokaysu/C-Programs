#include "sequence.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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
	struct node *next;
};

struct Sequence {
	struct node *front;
};

struct Sequence *Sequence_create(void) {
	struct Sequence *ans = malloc(sizeof(struct Sequence));
	ans->front = NULL;
	return ans;
}

void Sequence_destroy(struct Sequence *seq) {
	struct node *cur = seq->front;
	while (cur) {
		struct node *del = cur;
		cur = cur->next;
		free(del);
	}
	free(seq);
}

int Sequence_length(const struct Sequence *seq) {
	int ans = 0;
	struct node *cur = seq->front;
	while (cur) {
		ans++;
		cur = cur->next;
	}
	return ans;
}

int Sequence_item_at(const struct Sequence *seq, int pos) {
	struct node *cur = seq->front;
	for (int i = 0; i < pos; ++i) 
		cur = cur->next;
	return cur->item;
}

void Sequence_insert_at(struct Sequence *seq, int pos, int val) {
	struct node *cur = seq->front;
	struct node *wow = malloc(sizeof(struct node));
	wow->item = val;
	if (pos == 0) {
		wow->next = seq->front;
		seq->front = wow;
		return;
	}
	for (int i = 0; i < pos - 1; ++i)
		cur = cur->next;
	wow->next = cur->next;
	cur->next = wow;
}

int Sequence_remove_at(struct Sequence *seq, int pos) {
	struct node *cur = seq->front;
	if (pos == 0) {
		int ans = cur->item;
		seq->front = cur->next;
		free(cur);
		return ans;
	}
	for (int i = 0; i < pos - 1; ++i)
		cur = cur->next;
	struct node *del = cur->next;
	int ans = del->item;
	cur->next = del->next;
	free(del);
	return ans;
}

void Sequence_print(const struct Sequence *seq) {
	if (seq) {
		struct node *cur = seq->front;
		int l = Sequence_length(seq);
		printf("[%d]", l);
		for (int i = 0; i < l; ++i, cur = cur->next) 
			printf(" %d", cur->item);
		printf("\n");
	} else printf("[empty]\n");
}
