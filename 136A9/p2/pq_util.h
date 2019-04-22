struct pq;

// to_array(pqueue) places at *arr_ptr a dynamically allocated array of ints
//   containing queue items in the order they appeared in the queue
//   without their priorities.
//   Updates *len to the length of the array/queue. 
//   If pqueue is empty, *arr_ptr is not mutated but len is set to 0.
// requires : pqueue is not NULL, arr_ptr is not NULL, *arr_ptr is NULL
// effects : the memory at pqueue is invalid (freed),
//     allocates memory (caller must free), mutates *arr_ptr and *len. 
// time : O(n)
void to_array(struct pq *pqueue, int **arr_ptr, int *len);


// k_way_split(pqueue,k) splits the items in pqueue k ways. 
//   Let pos be the position of an item in pqueue.
//   (the first item is at position 0). 
//   The function creates and returns a heap allocated array 
//   containing k newly created priority queues. 
//   The first priority queue contains items for which 
//   pos % k is 0, the second queue contains items for which
//   pos % k is 1 and so on. The k-th queue (the last one) 
//   contains items for which pos % k is k-1. 
//   
// requires: pqueue is not null, k is positive
// effects: the memory at pqueue is invalid (freed), 
//          allocates memory (caller must free)
// time: O(n^2) where n is the number of elements in pqueue
struct pq **k_way_split(struct pq *pqueue, const int k);
