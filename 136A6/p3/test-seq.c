/* File: test-seq.c
Simple Testing Module for Sequence ADT
*/
#include <stdio.h>
#include <stdbool.h>
#include "sequence.h"



//tests basic Sequence operations

int main(void) {
  struct Sequence s1;
  Seq_init(&s1);
  Sequence_print(&s1);
  
  Sequence_insert_at(&s1 ,0, 100);
  Sequence_insert_at(&s1 ,1, 101);
  Sequence_print(&s1);
  printf("%d \n",Sequence_remove_at(&s1,1));
  Sequence_clear(&s1);                                   
  //add 99 items
  int num_add =99;                          
   for(int i = 0; i<= num_add; ++i){
     Sequence_insert_at(&s1 ,i, i);
   }
  //add one more
  Sequence_insert_at(&s1 ,100, 100);
  Sequence_print(&s1);
  
}