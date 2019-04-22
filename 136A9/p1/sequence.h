// A module for an int Sequence ADT

struct Sequence;

// NOTE: All of the following functions REQUIRE:
//       pointers to a Sequence (e.g., seq) are not NULL


// Sequence_create() returns a pointer to a new (empty) Sequence
// effects : allocates memory (caller must free)
// time : O(1)
struct Sequence *Sequence_create(void);

// Sequence_destroy(seq) frees all dynamically allocated memory 
// effects : the memory at seq is invalid (freed)
// time : O(n)
void Sequence_destroy(struct Sequence *seq);


// Sequence_length(seq) returns the number of items in seq
// time : O(n)
int Sequence_length(const struct Sequence *seq);

// Sequence_item_at(seq, pos) returns the item in seq at the given pos
// requires: 0 <= pos < length(seq)
// time : O(n)
int Sequence_item_at(const struct Sequence *seq, int pos);


// Sequence_insert_at(seq, pos, val) inserts a new item with value val
//   at position pos in seq
//   (changing the position of items at position >= pos)
// requires: and 0 <= pos <= length(seq)
// effects: seq is modified
// time : O(n)
void Sequence_insert_at(struct Sequence *seq, int pos, int val);


// Sequence_remove_at(seq, pos) removes the item at position pos in seq
//   and returns the removed value
//   (changing the position of items > pos)
// requires: 0 <= pos < length(seq)
// effects: seq is modified
// time : O(n)
int Sequence_remove_at(struct Sequence *seq, int pos);



// Sequence_print(seq) prints out the items in seq
//   using the format: "[length] item1 item2 ... item_last\n"
//   or "[empty]\n"
// effects: prints out a message
// time: O(n)
void Sequence_print(const struct Sequence *seq);
