#include <stdbool.h>

struct pq;

typedef struct pq *PQ;


// pq_create() returns a pointer to a dynamically allocated 
//    new (empty) priority queue
// effects : allocates memory (caller must free)
// time : O(1)
PQ pq_create(void);


// pq_destroy(pqueue) deallocates all dynamically allocated memory
//   within the entire pqueue
// requires : pqueue must be from a previous malloc/realloc
// effects : the memory at pqueue is invalid (freed)
// time : O(n) where n is the size of the pqueue
void pq_destroy(PQ pqueue);


// pq_add(pqueue,item,priority) inserts the item into pqueue   
//    (a lower value for priority means the item has higher priority in the 
//    pqueue.) 
// requires : pqueue is not NULL, priority is a positive int
// effects : mutates pqueue to contain item 
// time : O(logn)
void pq_add(PQ pqueue, int item, int priority);


// pq_remove(pqueue) removes and returns the item with the highest
//   priority from the pqueue. If there are multiple items with the same 
//   priority, the order does not matter.
// requires : pqueue is not NULL, pqueue is not empty
// effects : mutates pqueue 
// time : O(logn) 
int pq_remove(PQ pqueue);


// pq_is_empty(pqueue) returns true only if pqueue contains no items
//   otherwise returns false
// requires : pqueue is not NULL
// time : O(1)
bool pq_is_empty(const PQ pqueue);


// pq_print(pqueue) prints the queue
// effects : prints output
// example : The pqueue is printed in the order it is stored in the array. 
//   For example, if the heap is currently
//             (1,10)
//             /    \
//         (3,30)  (2,20)
//   then it will be printed as [(1,10),(3,30),(2,20)]
//   where each node is printed as (item,priority).
// requires : pqueue is not NULL
// time : O(n)
void pq_print(const PQ pqueue);


// pq_length(pqueue) returns the numbers of items in the pqueue
// requires : pqueue is not NULL
// time :  O(1), constant time! 
int pq_length(const PQ pqueue);


// pq_front_priority(pqueue) returns the priority of the item with the highest
//   priority
// requires : pqueue is not NULL and not empty
// time : O(1)
int pq_front_priority(const PQ pqueue);


// pq_front_item(pqueue) returns the value of the item with the highest 
//   priority in the pqueue. If two items have the same priority, 
//   order does not matter.
// requires : pqueue is not NULL and not empty
// time : O(1)
int pq_front_item(const PQ pqueue);
