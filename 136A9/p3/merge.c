#include "merge.h"
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

void merge(struct llist *dest, struct llist *src1, struct llist *src2) {
	struct llnode *cur1 = src1->front;
	struct llnode *cur2 = src2->front;
	if (!cur1 && !cur2) {
		return;
	} else if (!cur2) {
		dest->front = cur1;
		cur1 = cur1->next;
	} else if (!cur1) {
		dest->front = cur2;
		cur2 = cur2->next;
	} else {
		if (cur1->item < cur2->item) {
			dest->front = cur1;
			cur1 = cur1->next;
		} else {
			dest->front = cur2;
			cur2 = cur2->next;
		}
	}
	struct llnode *cur = dest->front;
	while (cur1 || cur2) {
		if (!cur1) {
			cur->next = cur2;
			cur = cur->next;
			cur2 = cur2->next;
		} else if (!cur2) {
			cur->next = cur1;
			cur = cur->next;
			cur1 = cur1->next;
		} else {
			if (cur1->item < cur2->item) {
				cur->next = cur1;
				cur = cur->next;
				cur1 = cur1->next;
			} else {
				cur->next = cur2;
				cur = cur->next;
				cur2 = cur2->next;
			}
		}
	}
}

void merge_sort(struct llist *lst) {
	int l = 0;
	struct llnode *cur = lst->front;
	while (cur) {
		cur = cur->next;
		l++;
	}
	if (l == 0 || l == 1) return;
	cur = lst->front;
	int mid = l / 2;
	for(int i = 0; i < mid - 1; ++i) 
		cur = cur->next;
	struct llnode *sav = cur;
	cur = cur->next;
	sav->next = NULL;
	struct llist *hh = malloc(sizeof(struct llist));
	struct llist *a = malloc(sizeof(struct llist));;
	a->front = cur;
	merge_sort(lst);
	merge_sort(a);
	merge(hh, lst, a);
	lst->front = hh->front;
	free(a);
	free(hh);
}
