/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// WRITE YOUR CODE BELOW
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "sequence.h"

void Seq_init(struct Sequence *s) {
	s->max_len = 100;
	s->length = 0;
}

int Sequence_length(const struct Sequence *seq) {
	return seq->length;
}

void Sequence_clear(struct Sequence *seq) {
	for (int i = 0; i < seq->length; ++i) 
		seq->arr[i] = 0;
	seq->length = 0;
}

int Sequence_item_at(const struct Sequence *seq, int pos) {
	return seq->arr[pos];
}

void Sequence_insert_at(struct Sequence *seq, int pos, int val) {
	if (seq->length >= seq->max_len) {
		printf("Sequence Filled: max length is %d items.\n", seq->max_len);
		return;
	}
	seq->length++;
	for (int i = seq->length; i < pos; --i) {
		seq->arr[i] = seq->arr[i - 1];
	}
	seq->arr[pos] = val;
}

int Sequence_remove_at(struct Sequence *seq, int pos) {
  int val = seq->arr[pos];
	for (int i = pos; i < seq->length; ++i)
		seq->arr[i] = seq->arr[i + 1];
	seq->length--;
  return val;
}

void Sequence_print(const struct Sequence *seq) {
	if (seq->length == 0) {
		printf("[empty]\n");
		return;
	}
	printf("[%d]", seq->length);
	for (int i = 0; i < seq->length; ++i) 
		printf(" %d", seq->arr[i]);
	printf("\n");
}

