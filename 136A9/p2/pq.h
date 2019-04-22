#include <stdbool.h>

struct pq;

// pq_create() returns a pointer to a dynamically allocated 
//    new (empty) priority queue
// effects : allocates memory (caller must free)
// time : O(1)
struct pq *pq_create(void);

// pq_destroy(pqueue) deallocates all dynamically allocated memory
//   within the entire pqueue
// requires : pqueue must be from a previous malloc/realloc
// effects : the memory at pqueue is invalid (freed)
// time : O(n) where n is the size of the queue
void pq_destroy(struct pq *pqueue);

// pq_add(pqueue,item,priority) inserts the item into pqueue so that the item
//    appears after all existing items with lower or equal priority values  
//    (a lower value for priority means the item has higher priority in the 
//    queue.) 
// requires : pqueue is not NULL, priority is a positive int
// effects: mutates pqueue to contain item 
// time : O(n)
void pq_add(struct pq *pqueue, int item, int priority);

// pq_remove(pqueue) removes and returns the item with the lowest priority
//   from the queue. If there are multiple items with the same priority, the 
//   item which has been in the queue the longest is removed and returned.
// requires : pqueue is not NULL, pqueue is not empty
// effects : mutates pqueue 
// time : O(1) 
int pq_remove(struct pq *pqueue);

// pq_is_empty(pqueue) returns true only if pqueue contains no items
//   otherwise returns false
// requires: pqueue is not NULL
// time : O(1)
bool pq_is_empty(const struct pq *pqueue);

// pq_print(pqueue) prints the queue by first printing the priority
//   of the highest priority item(s) and then all items with this priority 
//   followed by a newline. Then the next highest priority is printed followed
//   by all items with this priority, and so on.
//   Example: The queue (priorities in parantheses):
//    23(3) 35(3) 3(5) 46(10) 46(10) 47(10)
//    produces the output (newline characters added for emphasis):
//    [3] 23 35\n
//    [5] 3\n
//    [10] 46 46 47\n
// effects: prints output
// requires: pqueue is not NULL
// time: O(n)
void pq_print(const struct pq *pqueue);

// pq_length(pqueue) returns the number of items in the queue
// requires: pqueue is not NULL
// time :  O(1), constant time! 
int pq_length(const struct pq *pqueue);

// pq_front_priority(pqueue) returns the priority of the item at the front 
//   of the queue
// requires: pqueue is not NULL and not empty
// time : O(1)
int pq_front_priority(const struct pq *pqueue);

// pq_front_item(pqueue) returns the value of the item at the front 
//   of the queue
// requires: pqueue is not NULL and not empty
// time : O(1)
int pq_front_item(const struct pq *pqueue);
