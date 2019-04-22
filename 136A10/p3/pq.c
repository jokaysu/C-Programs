#include "pq.h"
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

struct node {
    int it;
    int pr;
};

typedef struct node *Node;
  
struct pq {
    Node arr;
    int len;
};


PQ pq_create(void) {
    PQ pqueue = malloc(sizeof(struct pq));
    pqueue->len = 0;
    pqueue->arr = malloc(pqueue->len * sizeof(struct node));
    return pqueue;
}


void pq_destroy(PQ pqueue) {
    for (int i = 0; i < pqueue->len - 1; ++i) {
        Node del = &(pqueue->arr[i]);
        free(del);
    }
    free(pqueue);
}

void swapNode(Node n, int i1, int i2) {
    int t = 0;
    t = n[i1].it;
    n[i1].it = n[i2].it;
    n[i2].it = t;
    t = n[i1].pr;
    n[i1].pr = n[i2].pr;
    n[i2].pr = t;
}

void bubbleUp(PQ pqu, int ind) {
    if (ind == 0) return;
    int par = (ind - 1) / 2;
    if (pqu->arr[ind].pr < pqu->arr[par].pr) {
        swapNode(pqu->arr, ind, par);
        bubbleUp(pqu, par);
    }
}

void pq_add(PQ pqueue, int item, int priority) {
    pqueue->len++;
    pqueue->arr = realloc(pqueue->arr, pqueue->len * sizeof(struct node));
    pqueue->arr[pqueue->len - 1].it = item;
    pqueue->arr[pqueue->len - 1].pr = priority;
    bubbleUp(pqueue, pqueue->len - 1);
}

void bubbleDown(PQ pqu, int ind) {
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;
    if (left >= pqu->len) return;
    if (right >= pqu->len) {
        if (pqu->arr[left].pr < pqu->arr[ind].pr) 
            swapNode(pqu->arr, left, ind);
    } else {
        if (pqu->arr[left].pr < pqu->arr[ind].pr) {
            swapNode(pqu->arr, left, ind);
            bubbleDown(pqu, left);
        } else if (pqu->arr[right].pr < pqu->arr[ind].pr) {
            swapNode(pqu->arr, right, ind);
            bubbleDown(pqu, right);
        }
    }
}

int pq_remove(PQ pqueue) {
    pqueue->len--;
    int ans = pqueue->arr[0].it;
    swapNode(pqueue->arr, 0, pqueue->len);
    pqueue->arr = realloc(pqueue->arr, pqueue->len * sizeof(struct node));
    bubbleDown(pqueue, 0);
    return ans;
}


bool pq_is_empty(const PQ pqueue) {
    return pqueue->len == 0;
}



void pq_print(const PQ pqueue) {
    printf("[");
    for (int i = 0; i < pqueue->len; ++i) {
        if (i) printf(",");
        printf("(%d,%d)", pqueue->arr[i].it, pqueue->arr[i].pr);
    }
    printf("]\n");
}


int pq_length(const PQ pqueue) {
    return pqueue->len;
}



int pq_front_priority(const PQ pqueue) {
    return pqueue->arr[0].pr;
}


int pq_front_item(const PQ pqueue) {
    return pqueue->arr[0].it;
}