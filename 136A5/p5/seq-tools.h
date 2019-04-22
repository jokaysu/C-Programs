#include <stdbool.h>
#include "sequence.h"

// A module for working with Sequences

// NOTE: each of the following requires that all pointers are not NULL


// Sequence_add_one(seq) modifies seq by adding 1 to each item
// effects: modifies seq
void Sequence_add_one(struct Sequence *seq);


// Sequence_build(n) returns a NEW sequence of length n
//   with the items 0, 1, ..., n-1
struct Sequence *Sequence_build(int n);


// Sequence_map(fp, seq) applices fp to each item (eg., item_k = fp(item_k))
// effects: modifies seq
void Sequence_map(int (* fp)( int ), struct Sequence *seq);


// Sequence_equal(seq1, seq2) determines if seq1 and seq2 are identical
bool Sequence_equal(const struct Sequence *seq1, const struct Sequence *seq2);


// avg_and_variance(seq, &avg, &var) modifies avg and var
//   to store the average (mean) of all items [rounded down]
//   and the variance of all items.
//   The variance is calculated by summing over all items the difference
//   between the item and the average squared, divided by the number of items
//     sum [(item_k - avg)^2] / length
// requires: length(seq) > 0
// effects: modifies *avg and *var
void avg_and_variance(const struct Sequence *seq, int *avg, int *var);


// Sequence_fib(n) returns a NEW sequence of length n
//   with the first n fibonacci numbers:
//   for example, Sequence_fib(8) produces the sequence:
//     0, 1, 1, 2, 3, 5, 8, 13
// requires: n >= 1
struct Sequence *Sequence_fib(int n);


// Sequence_filter(fp, seq) removes all items from seq for which fp(item)
//   is false
// effects: modifies seq
void Sequence_filter(bool (*fp)(int), struct Sequence *seq);


// Sequence_foldl(fp, base, seq) applies the foldl function (from Racket)
//   to the elements of seq, starting with the initial value of base.
//   in other words, fp(item_n-1, ... fp(item_1, fp(item_0, base)))
//   if seq is empty, it returns base
int Sequence_foldl(int (*fp)(int, int), int base, const struct Sequence *seq);


// BONUS:

// Sequence_reverse(seq) reverses the sequence seq.
// effects: modifies seq
void Sequence_reverse(struct Sequence *seq);
// NOTE: you may not generate a new sequence... to do this properly,
//   you should swap item_0 with item_n-1, and item_1 and item_n-2, etc...
