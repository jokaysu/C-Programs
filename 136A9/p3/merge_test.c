#include "merge.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// read_list(lst) reads a number (n) which is treated as the number of 
//   subsequent numbers read in as items for the linked list.
//   The function does NO error checking (assumes correct input)
// requires: lst is not NULL
// effects: mutates lst 
// time : O(n) 
void read_list(struct llist *lst){
  int n;  //number of items to be read into list
  scanf("%d",&n); 

  for (int i = 0; i < n; ++i){
    int num;
    scanf("%d",&num); //expected to succeed

    //create new node
    struct llnode *new_node = malloc(sizeof(struct llnode));
    new_node->item = num;
    new_node->next = NULL;

    //if lst is empty, make node front
    if(lst->front == NULL){
      lst->front = new_node;
      continue;
    }

    //lst not empty, find last node
    struct llnode *curr = lst->front;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = new_node;		//insert at end
  }
}

int main(void){
  struct llist *lst = malloc(sizeof(struct llist));
  lst->front = NULL;
  read_list(lst); //read from standard input
  merge_sort(lst); //call merge_sort

  //print list
  bool first = true;
  struct llnode *curr = lst->front;
  while (curr != NULL) {
    if (first){
      first = false;
    } else {
      printf("->");
    }
    printf("%d",curr->item);
    curr = curr->next;
  }
  printf(".\n");
  
  curr = lst->front;
  while(curr != NULL) {
    struct llnode *temp = curr;
    curr = curr->next;
    free(temp);
  }
  free(lst);
}