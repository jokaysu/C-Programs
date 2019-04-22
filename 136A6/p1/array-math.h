#include <stdbool.h>

// dot_product consumes two arrays and their length, then produces 
//   their dot-product
int dot_product(const int a[], const int b[], int s);

// is_orthogonal consumes two arrays and their length, then 
//   determines if they are orthogonal
bool is_orthogonal(const int a[], const int b[], int s);

//add_to_vector adds array a and b to c
void add_to_vector(const int a[], const int b[], int c[], int s);

//is_multiple determines if either a is a multiple of b or
//  b is a multiple of a 
bool is_multiple(const int a[], const int b[], int s);
