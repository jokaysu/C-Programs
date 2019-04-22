/**
 File: sequence.h
*/

//Warning: DO NOT MODIFY THIS FILE


struct Sequence {
     int max_len;
     int arr[100];
     int length;
};

//Seq_init(seq) initializes the max_len and length values in Sequence structure
// max_len is the size of the internal array, which is 100
// length is the number of current elements, which is initially zero 
//requires: seq!=NULL
void Seq_init(struct Sequence *seq); 


//Sequence_length(seq) returns the number of items in seq
//requires: seq!=NULL
int Sequence_length(const struct Sequence *seq);


//Sequence_clear(seq) removes all items from seq
//requires: seq!=NULL
//effects: seq is modified
void Sequence_clear(struct Sequence *seq);


// Sequence_item_at(seq,pos) returns the item in seq at the given pos
// requires: 0 <= pos < length(seq)
//           seq!=NULL
int Sequence_item_at(const struct Sequence *seq, int pos);

// Sequence_insert_at(seq,pos,val) inserts a new value at position pos in seq
// All items' indices after the new item increase by 1
// requires: 0 <= pos <= length(seq) <= max_len
// seq!=NULL
// effects: seq may be modified
// if length == max_len prints a warning message 
// "Sequence Filled: max length is %d items.\n"
// new item is *not added
void Sequence_insert_at(struct Sequence *seq, int pos, int value);


// Sequence_remove_at(seq, pos) removes the item at pos in seq 
//  and returns the removed value
// All items' indices after the deleted item decrease by 1
// requires: 0 <= pos < length(seq)
//           seq!=NULL
// effects: seq is modified
int Sequence_remove_at(struct Sequence *seq, int pos);


// Sequence_print(seq) prints out the items in seq
//   using the format: "[length] item1 item2 ... item_last\n"
//   or "[empty]\n"
// requires: seq!=NULL
// effects: prints out a message
void Sequence_print(const struct Sequence *seq);
