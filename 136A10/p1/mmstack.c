// a MMStack (Min/Max Stack)
// is a Stack ADT for storing integers
// that can return the Min/Max items in the stack
// all operations (except, perhaps, destroy) are O(1)

#include <stdlib.h>
#include <assert.h>
#include "mmstack.h"

/*
INTEGRITY STATEMENT (modify if necessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/



struct mmstack {
    int *arr;
    int length;
    int minLen;
    int *min;
    int maxLen;
    int *max;
};

MMStack create_MMStack(void){
    MMStack mms = malloc(sizeof(struct mmstack));
    mms->length = 0;
    mms->minLen = 0;
    mms->maxLen = 0;
    mms->min = malloc(mms->minLen * sizeof(int));
    mms->max = malloc(mms->maxLen * sizeof(int));
    mms->arr = malloc(mms->length * sizeof(int));
    return mms;
}


// O(1) as well!
void destroy_MMStack(MMStack mms){
    free(mms->arr);
    free(mms->min);
    free(mms->max);
    free(mms);
}


int mms_length(MMStack mms) {
    return mms->length;
}


void mms_push(MMStack mms, int i){
    mms->length++;
    mms->arr = realloc(mms->arr, mms->length * sizeof(int));
    mms->arr[mms->length - 1] = i;
    if (mms->minLen == 0 || i < mms->arr[mms->min[mms->minLen - 1]]) {
        mms->minLen++;
        mms->min = realloc(mms->min, mms->minLen * sizeof(int));
        mms->min[mms->minLen - 1] = mms->length - 1;
    }
    if (mms->maxLen == 0 || i > mms->arr[mms->max[mms->maxLen - 1]]) {
        mms->maxLen++;
        mms->max = realloc(mms->max, mms->maxLen * sizeof(int));
        mms->max[mms->maxLen - 1] = mms->length - 1;
    }}


int mms_pop(MMStack mms) {
    if(mms->min[mms->minLen - 1] == mms->length - 1) {
        mms->minLen--;
        mms->min = realloc(mms->min, mms->minLen * sizeof(int));
    }
    if(mms->max[mms->maxLen - 1] == mms->length - 1) {
        mms->maxLen--;
        mms->max = realloc(mms->max, mms->maxLen * sizeof(int));
    }
    int ans = mms->arr[mms->length - 1];
    mms->length--;
    mms->arr = realloc(mms->arr, mms->length * sizeof(int));
    return ans;
}


int mms_min(MMStack mms) {
    return mms->arr[mms->min[mms->minLen - 1]];
}


int mms_max(MMStack mms) {
    return mms->arr[mms->max[mms->maxLen - 1]];
}
