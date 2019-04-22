// A module for an int Sequence ADT

// This is an opaque structure definition
struct Sequence;

// NOTE: All of the following functions REQUIRE:
//       pointers to a Sequence (e.g., seq) are not NULL


// Sequence_create() returns a pointer to a new (empty) Sequence
struct Sequence *Sequence_create(void);


// Sequence_length(seq) returns the number of items in seq
int Sequence_length(const struct Sequence *seq);


// Sequence_clear(seq) removes all items from seq
// effects: seq is modified
void Sequence_clear(struct Sequence *seq);


// Sequence_item_at(seq, pos) returns the item in seq at the given pos
// requires: 0 <= pos < length(seq)
int Sequence_item_at(const struct Sequence *seq, int pos);


// Sequence_insert_at(seq, pos, val) inserts a new item with value val
//   at position pos in seq
//   (changing the position of elements at position >= pos)
// requires: and 0 <= pos <= length(seq)
// effects: seq is modified
void Sequence_insert_at(struct Sequence *seq, int pos, int val);


// Sequence_remove_at(seq, pos) removes the item at position pos in seq
//   and returns the removed value
//   (changing the position of elements > pos)
// requires: 0 <= pos < length(seq)
// effects: seq is modified
int Sequence_remove_at(struct Sequence *seq, int pos);


// Sequence_print(seq) prints out the items in seq
//   using the format: "[length] item1 item2 ... item_last\n"
//   or "[empty]\n"
// effects: prints out a message
void Sequence_print(const struct Sequence *seq);
