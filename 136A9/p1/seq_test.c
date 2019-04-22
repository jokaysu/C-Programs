#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sequence.h"
#include <assert.h>
/*
 * This is a test harness with very specific input format.
 * Failure to follow format might lead to undefined behaviour.
 *
 * c : Sequence_create
 * d : Sequence_destroy
 * l : Sequence_length
 * a : Sequence_item_at (reads an int)
 * i : Sequence_insert_at (reads two ints)
 * r : Sequence_remove_at (reads an int)
 * p : Sequence_print
 */
 int main(void){
 	struct Sequence *seq = NULL;
 	while (1){
 		char cmd[2]; // c, d, l, a, i, r, p
 		int ret_val = scanf("%s", cmd);
 		if(ret_val == EOF){
 			break;
 		}
 		if (strcmp(cmd, "c") == 0) {//creating new sequence
 			if(seq != NULL) {
				Sequence_destroy(seq); // destroy the old one
			}
			seq = Sequence_create();
			printf("Sequence Created\n");
		} else if (strcmp(cmd, "d") == 0) { //destroy/free
			assert(seq);
			Sequence_destroy(seq);
			seq = NULL;
			printf("Sequence Destroyed\n");
		} else if (strcmp(cmd, "l") == 0) { //Sequence_length
			assert(seq);
			printf("Length: %d\n",Sequence_length(seq));
		} else if (strcmp(cmd, "a") == 0) { //Sequence_item_at
			int at;
			scanf("%d", &at);
			assert(seq);
			printf("Item-at: %d is %d\n",at,Sequence_item_at(seq,at)); 
		} else if (strcmp(cmd, "i") == 0) { //Sequence_insert_at
			int at;
			scanf("%d", &at);
			int val;
			scanf("%d",&val);
			assert(seq);
			Sequence_insert_at(seq,at,val);
			printf("Inserted: %d at %d\n", val,at);
		} else if (strcmp(cmd, "r") == 0) { //Sequence_remove_at
			int at;
			scanf("%d", &at);
			assert(seq);
			printf("Removed: %d from %d\n",Sequence_remove_at(seq,at),at); 
		} else if (strcmp(cmd, "p") == 0) { //Sequence_print
			assert(seq);
			Sequence_print(seq);
		} else {
			printf("Invalid command (%s).\n",cmd);
			exit(EXIT_FAILURE);
		}
	}	//end while(1)
}