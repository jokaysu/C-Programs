struct stack;

struct stack *create_stack(void) ;

void stack_push(int item, struct stack *s) ;

void stack_destroy(struct stack *s) ;
 
bool stack_is_empty(const struct stack *s);

int stack_top(const struct stack *s);
 
int stack_pop(struct stack *s);

