#include "set.h"
#include <stdio.h>
#include <stdlib.h>

/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

struct Set *set_create(void) {
	struct Set *ans = malloc(sizeof(int *) + sizeof(int));
	ans->arr = malloc(0 * sizeof(int));
	ans->num = 0;
	return ans;
}

void set_destroy(struct Set *s) {
	free(s->arr);
	s->num = 0;
	free(s);
}

int set_size(const struct Set *s) {
	return s->num;
}

void set_add(struct Set *s, int i) {
	if (s->num == 0) {
		s->num++;
		s->arr = realloc(s->arr, s->num * sizeof(int));
		s->arr[0] = i;
		return;
	}
	int j = 0;
	while (s->arr[j] < i) {
		j++;
		if (j == s->num) break;
	}
	if (j == s->num) {
		s->num++;
		s->arr = realloc(s->arr, s->num * sizeof(int));
		s->arr[s->num - 1] = i;
	} else if (s->arr[j] != i){
		s->num++;
		s->arr = realloc(s->arr, s->num * sizeof(int));
		for (int k = s->num - 1; k > j; k--)
			s->arr[k] = s->arr[k - 1];
		s->arr[j] = i;
	}
}

void set_remove(struct Set *s, int i) {
	int j = 0;
	while (s->arr[j] != i) {
		j++;
		if (j == s->num) break;
	}
	if (j != s->num) {
		s->num--;
		for (int k = j; k < s->num; ++k)
			s->arr[k] = s->arr[k + 1];
		s->arr = realloc(s->arr, s->num * sizeof(int));
	}
}

struct Set *set_union(const struct Set *s1, const struct Set *s2) {
	struct Set *ans = malloc(sizeof(int *) + sizeof(int));
	ans->num = s1->num + s2->num;
	ans->arr = malloc(ans->num * sizeof(int));
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < s1->num && j < s2->num) {
		if (s1->arr[i] < s2->arr[j]) {
			ans->arr[k] = s1->arr[i];
			i++;
		} else if (s1->arr[i] > s2->arr[j]) {
			ans->arr[k] = s2->arr[j];
			j++;
		} else if (s1->arr[i] == s2-> arr[j]) {
			ans->arr[k] = s1->arr[i];
			i++;
			j++;
			ans->num--;
			ans->arr = realloc(ans->arr, ans->num * sizeof(int));
		}
		k++;
	}
	int n;
	for (n = i; n < s1->num; ++n, ++k)
		ans->arr[k] = s1->arr[n];
	for (n = j; n < s2->num; ++n, ++k)
		ans->arr[k] = s2->arr[n];
	return ans;
}

struct Set *set_intersect(const struct Set *s1, const struct Set *s2) {
	struct Set *ans = malloc(sizeof(int *) + sizeof(int));
	ans->num = 0;
	ans->arr = malloc(ans->num * sizeof(int));
	int i = 0;
	int j = 0;
	while (i < s1->num && j < s2->num) {
		if (s1->arr[i] < s2->arr[j]) i++;
			else if (s1->arr[i] > s2->arr[j]) j++;
				else {
					ans->num++;
					ans->arr = realloc(ans->arr, ans->num * sizeof(int));
					ans->arr[ans->num - 1] = s1->arr[i];
					i++;
					j++;
				}
	}
	return ans;
}

void set_print(const struct Set *s) {
	printf("[");
	for (int i = 0; i < s->num - 1; ++i) 
		printf("%d,", s->arr[i]);
	printf("%d]\n", s->arr[s->num - 1]);
}

