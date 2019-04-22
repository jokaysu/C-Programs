#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/*
 * This is a test harness with very specific input format.
 *
 * c : bst_create
 * d : bst_destroy
 * s : bst_size
 * i : bst_insert
 * f : bst_find
 * sel : bst_select
 * r : bst_remove
 * rng : bst_range
 * p : bst_print
 * bta : bst_to_sorted_array
 * atb : sorted_array_to_bst
 * 
 */
 int main(void){
 	struct bst *t = NULL;
 	while (1){
 		char cmd[4]; 
 		int ret_val = scanf("%s", cmd);
 		if(ret_val == EOF){
 			break;
 		}
 		if (strcmp(cmd, "c") == 0) {//creating new heap
 			if(t != NULL) {
				bst_destroy(t); // destroy the old one
			}
			t = bst_create();
			printf("BST Created\n");
		} else if (strcmp(cmd, "d") == 0) { //destroy/free
			bst_destroy(t);
			t = NULL;
			printf("BST Destroyed\n");
        } else if (strcmp(cmd, "s") == 0) { // size
            printf("BST Size: %d\n", bst_size(t));
        } else if (strcmp(cmd, "i") == 0) { // insert
            int item;
			scanf("%d", &item);
			bst_insert(item, t);
			printf("Inserted: %d\n",item);
        } else if (strcmp(cmd, "f") == 0) { // find
            int item;
			scanf("%d", &item);
			bst_find(item, t);
			printf("find %d?: %s\n",item,bst_find(item,t) ? "true" : "false");
        } else if (strcmp(cmd, "sel") == 0) { // select
            int k;
			scanf("%d", &k);
			printf("Select %d: %d\n",k, bst_select(k,t));
        } else if (strcmp(cmd, "r") == 0) { // remove
            int item;
			scanf("%d", &item);
			bst_remove(item, t);
			printf("Removed: %d\n",item);
        } else if (strcmp(cmd, "rng") == 0) { // range
            int start;
			scanf("%d", &start);
            int end;
			scanf("%d", &end);
            printf("Range %d-%d: %d\n",start,end,bst_range(start,end,t));
        } else if (strcmp(cmd, "p") == 0) { // print
            int o;
			scanf("%d", &o);
            bst_print(o,t);
        } else if (strcmp(cmd, "bta") == 0) { // bst to sorted array
            int *arr = bst_to_sorted_array(t);
            printf("[");
            for (int i = 0; i < bst_size(t); ++i) {
                if (i) printf(",");
                printf("%d", arr[i]);
            }
            printf("]\n");
            free(arr);
        } else if (strcmp(cmd, "atb") == 0) { // sorted array to bst
            if(t != NULL) {
				bst_destroy(t); // destroy the old one
			}
            int len = 0;
            scanf("%d", &len);
            int *arr = malloc(sizeof(int)*len);
            for (int i = 0; i < len; ++i) {
                scanf("%d", &arr[i]);
            }
            t = sorted_array_to_bst(arr, len);
            free(arr);
            printf("BST Created from sorted array\n");
        } else {
			printf("Invalid command (%s).\n",cmd);
			exit(EXIT_FAILURE);
		}
	}	//end while(1)
}