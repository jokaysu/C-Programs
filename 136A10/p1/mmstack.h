// a MMStack (Min/Max Stack)
// is a Stack ADT for storing integers
// that can return the Min/Max items in the stack
// all operations (except, perhaps, destroy) are O(1)

struct mmstack;

typedef struct mmstack *MMStack;

// create_MMStack() returns a pointer to a dynamically allocated 
//   new (empty) stack
//   effects: allocates memory (caller must free)
//   time: O(1)
MMStack create_MMStack(void);

// destroy_MMStack(mms) deallocates all dynamically allocated memory
//   within the entire mmstack
// requires : mmstack must be from a previous malloc/realloc
// effects : the memory at mmstack is invalid (freed)
// time : O(n) (at most, depending on the implementation), where n = mms_length(mms)
void destroy_MMStack(MMStack mms);

// mms_length(mms) returns the number of entries in mms
//   requires : mmstack is not NULL
//   time: O(1)
int mms_length(MMStack mms);

// mms_push(mms, i) puts i on the top of the mms
//   requires : mms is not NULL
//   effects: mutates mms and the length of mms is updated
//   time: O(1)
void mms_push(MMStack mms, int i);

// mms_pop(mms) removes and returns item from the top of the mms
//   requires:  mms is a valid, non-empty, MMStack
//   effects: nutates mms and length of mms is updated
//   time: O(1)
int mms_pop(MMStack mms);

// mms_min(mms) returns the minimum item stored in the mms
//   requires:  mms is a valid, non-empty, MMStack
//   time: O(1)
int mms_min(MMStack mms);

// mms_max(mms) returns the maximum item stored in the mms
//   requires:  mms is a valid, non-empty, MMStack
//   effects: O(1)
int mms_max(MMStack mms);
