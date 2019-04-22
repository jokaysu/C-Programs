//You may not change this file in any way

struct llnode {
	int item;
	struct llnode *next;
};

struct llist {
	struct llnode *front;
};

// merge(dest, src1, src2) mutates dest to a list containing items
//   from src1 and src2 in sorted order.
// requires:  dest, src1 and src2 are not NULL and are sorted
// effects: mutates dest  
// time: O(n), where n is length(src1) + length(src2)
// RESTRICTIONS: the function may not allocate any memory other than stack allocated
//    pointers of type struct llnode *
void merge(struct llist *dest, struct llist *src1, struct llist *src2);

// merge_sort(lst) uses a divide and conquer algorithm to sort the linked list
// requires: lst is not NULL
// effects: mutates lst to be sorted by item
// time : O(nlogn), where n is the length of lst
// RESTRICTIONS: the function may allocate EMPTY llist(s) if needed.
//    the function MUST NOT allocate any llnode(s). Stack-allocated pointers to
//    llists(s) or llnodes(s) are acceptable.
void merge_sort(struct llist *lst);
	