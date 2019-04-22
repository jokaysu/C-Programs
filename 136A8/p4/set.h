struct Set {
	int *arr;
	int num;
};

// set_create() returns a newly allocated Set
// effects: A new set is allocated.  Caller must free with set_destroy
// time: O(1)

struct Set *set_create(void);

// set_destroy(s) deletes the Set pointed to by s
// requires: s is not NULL
// effects: s is deallocated
// time: O(1)

void set_destroy(struct Set *s);

// set_size(s) returns the number of elements in s
// requires: s is not NULL
// time: O(1)

int set_size(const struct Set *s);

// set_add(s,i) adds i to the Set s, if it does not already contain i
// requires: s is not NULL
// effects: i is added to s
// time: O(n) where n is set_size(s)

void set_add(struct Set *s, int i);

// set_remove(i,s) removes i from s.  if i is not in s, s isn't changed
// requires: s is not NULL
// effects: s may have a member removed
// time: O(n) where n is set_size(s)

void set_remove(struct Set *s, int i);

// set_union(s1,s2) returns a new Set that is the union of s1 and s2
// requires: s1, s2 are not NULL
// effects: returns a newly allocated Set.  caller must free using set_destroy
// time: O(n) where n is set_size(s1) + set_size(s2)

struct Set *set_union(const struct Set *s1, const struct Set *s2);

// set_intersect(s1,s2) returns a new Set that is the intersection of s1 and s2
// requires: s1, s2 are not NULL
// effects: returns a newly allocated Set.  caller must free using set_destroy
// time: O(n) where n is set_size(s1) + set_size(s2)

struct Set *set_intersect(const struct Set *s1, const struct Set *s2);

// set_print(s) prints the contents of the Set s to the screen.
// requires: s is not NULL
// effects: text is printed to the screen
// time: O(n) where n is set_size(s)

// example.  If a Set s contains the values 1, 2, and 3, 
//   set_print(s) prints
// [1,2,3]
//
// (there is no whitespace other than the newline at the end).

void set_print(const struct Set *s);

