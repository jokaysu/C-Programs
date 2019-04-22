#include <stdio.h>
#include "sequence.h"
#include "seq-tools.h"

/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

  // WRITE YOUR CODE BELOW

// a
void Sequence_add_one(struct Sequence *seq) {
    int n;
    for (int i = 0; i < Sequence_length(seq); ++i) {
        n = Sequence_item_at(seq, i);
        Sequence_remove_at(seq, i);
        Sequence_insert_at(seq, i, ++n);
    }
}


// b
struct Sequence *Sequence_build(int n) {
    struct Sequence *seq = Sequence_create();
    for(int i = 0; i < n; ++i) 
        Sequence_insert_at(seq, i, i);
    return seq;
}

// c
void Sequence_map(int (*fp)(int), struct Sequence *seq) {
    int n;
    for (int i = 0; i < Sequence_length(seq); ++i) {
        n = Sequence_item_at(seq, i);
        Sequence_remove_at(seq, i);
        Sequence_insert_at(seq, i, fp(n));
    }
}

// d
bool Sequence_equal(const struct Sequence *seq1, const struct Sequence *seq2) {
    for (int i = 0; i < Sequence_length(seq1); ++i) 
        if (Sequence_item_at(seq1, i) != Sequence_item_at(seq2, i)) 
            return false;
    return true;
}

// e
void avg_and_variance(const struct Sequence *seq, 
                               int *avg, int *var) {
    *avg = 0;
    for (int i = 0; i < Sequence_length(seq); ++i) 
        *avg += Sequence_item_at(seq, i);
    *avg /= Sequence_length(seq); 
    *var = 0;
    for (int i = 0; i < Sequence_length(seq); ++i) 
        *var += (Sequence_item_at(seq, i) - *avg) * 
                    (Sequence_item_at(seq, i) - *avg);
    *var /= Sequence_length(seq); 
}

// f
struct Sequence *Sequence_fib(int n) {
    struct Sequence *seq = Sequence_create();
    Sequence_insert_at(seq, 0, 0);
    if (n == 1) return seq;
    Sequence_insert_at(seq, 1, 1);
    if (n == 2) return seq;
    for (int i = 2; i < n; ++i) 
        Sequence_insert_at(seq, i, 
            Sequence_item_at(seq, i - 1) + Sequence_item_at(seq, i - 2));
    return seq;
}

// g
void Sequence_filter(bool (*fp)(int), struct Sequence *seq) {
    for (int i = 0; i < Sequence_length(seq); ++i) 
        if (!fp(Sequence_item_at(seq, i))) {
            Sequence_remove_at(seq, i);
            i--;
        }
}

// h
int Sequence_foldl(int (*fp)(int, int), int base, 
                   const struct Sequence *seq) {
    for (int i = 0; i < Sequence_length(seq); ++i) 
        base = fp(Sequence_item_at(seq, i), base);
    return base;
}

// i
void Sequence_reverse(struct Sequence *seq) {
    int n, m;
    int l = Sequence_length(seq);
    for (int i = 0; i < l / 2; ++i) {
        n = Sequence_item_at(seq, i);
        m = Sequence_remove_at(seq, l - i - 1);
        Sequence_insert_at(seq, l - i - 1, n);
        Sequence_remove_at(seq, i);
        Sequence_insert_at(seq, i, m);
    }
}
