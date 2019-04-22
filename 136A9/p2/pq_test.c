#include <stdio.h>
#include <string.h>
#include "pq.h"
#include "pq_util.h"
#include <stdlib.h>
#include <assert.h>

/*
 * This is a test harness with very specific input format.
 * Failure to follow format might lead to undefined behaviour.
 *
 * c : pq_create
 * d : pq_destroy
 * r : pq_remove
 * e : pq_is_empty
 * a : pq_add (reads two int values without error checking)
 * l : pq_length
 * p : pq_print
 * fp : pq_front_priority
 * fi : pq_front_item
 * ta: to_array
 * kws : k_way_split (reads one int value without error checking)
 */
 int main(void){
 	struct pq *queue = NULL;
 	while (1){
 		char cmd[4]; // c, d, r, e, a, l, p, fp, fi, ta, kws
 		int ret_val = scanf("%s", cmd);
 		if(ret_val == EOF){
 			break;
 		}
 		if (strcmp(cmd, "c") == 0) { //creating new pq
 			if(queue != NULL) {
				pq_destroy(queue); // destroy the old one
			}
			queue = pq_create();
			printf("PQueue Created\n");
		} else if (strcmp(cmd, "d") == 0) { //destroy/free
			pq_destroy(queue);
			queue = NULL;
			printf("PQueue Destroyed\n");
		} else if (strcmp(cmd, "r") == 0) {//remove
			assert(queue);
			printf("Removed: %d\n",pq_remove(queue)); 
		} else if (strcmp(cmd, "e") == 0) { //is_empty
			assert(queue);
			printf("Empty?:%s\n",pq_is_empty(queue) ? "true" : "false");
		} else if (strcmp(cmd, "a") == 0) { //add
			int item;
			scanf("%d", &item);
			int pri;
			scanf("%d", &pri);
			assert(queue);
			pq_add(queue, item, pri);
			printf("Added: %d %d\n",item,pri);
		} else if (strcmp(cmd, "l") == 0) {//pq_length
			assert(queue);
			printf("Length: %d\n",pq_length(queue));
		} else if (strcmp(cmd, "p") == 0) {//pq_print
			assert(queue);
			printf("Printing Queue:\n");
			pq_print(queue); 
		} else if (strcmp(cmd, "fp") == 0) {//pq_front_priority
			assert(queue);
			printf("Front priority: %d\n",pq_front_priority(queue));
		} else if (strcmp(cmd, "fi") == 0) {//pq_front_item
			assert(queue);
			printf("Front item: %d\n",pq_front_item(queue));
		} else if (strcmp(cmd, "ta") == 0) { //to_array
			int *arr_ptr = NULL;
			int len;
			assert(queue);
			to_array(queue, &arr_ptr,&len);

			//remember that to_array free's pqueue
			//setting to NULL so that incorrect usage causes assertions to fail
			queue = NULL; 
			printf("to_array destroyed queue\n");

			for(int i=0; i < len; ++i){
				if(i) printf(", ");
				printf("%d",arr_ptr[i]);
			}
			printf(".\n");
			free(arr_ptr);
		} else if (strcmp(cmd, "kws") == 0) {  //k_way_split
			int k;
			scanf("%d", &k);		
			assert(queue);
			struct pq ** pq_array = k_way_split(queue, k);

			//remember that k_way_split free's pqueue
			//setting to NULL so that incorrect usage causes assertions to fail
			queue = NULL; 

			printf("k_way_split destroyed queue\n");

			// Use pq_print to print each element in the array  
			printf("k was %d\n",k);
			for(int i=0;i<k;i++){
				printf("Queue %d\n",i);
				pq_print(pq_array[i]);
				pq_destroy(pq_array[i]); // deallocate each pq
			}
			free(pq_array);//deallocate array that contained pq's
		} else {
			printf("Invalid command (%s).\n",cmd);
			exit(EXIT_FAILURE);
		}
	}	//end while(1)
}
