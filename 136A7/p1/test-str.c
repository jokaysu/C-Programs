#include <stdbool.h>
#include <assert.h>
#include "str-funct.h"

int main(void) {
  //test letter_freq_count
  int letters[27] ={0};
  letter_freq_count("aAbc", letters);
  assert(letters[0]==2);
  assert(letters[1]==1);
  assert(letters[2]==1);
  
  //test anagram
  assert(anagram("Comedian", "Demoniac"));
  
  //test ccount
  const char s1[] = "abcd";
  const char s2[] = "abc";
  const char *arr[] = {s1, s2};
  assert(ccount(arr, 2, 'a') == 2);
  assert(ccount(arr, 2, 'd') == 1);
}