#include <stdio.h>
#include "stack.h"

/* Static value of the stack */
static Stack stack;

/* Initialize correctly the stack to 0. */
void stack_init(void)
{
    stack.size = 0;
}

/* Returns the current size of the stack. */
int stack_size(void)
{
    return stack.size;
}

/* Returns 1 if the stack is empty, returns 0 otherwise. */
int stack_is_empty(void)
{
    if (stack.size < 1)
        return 1;
    
    return 0;
}

/* Returns the element at the top of the stack. */
int stack_top(void)
{
    return stack.values[stack.size - 1];
}

/* Pops the element at the top of the stack and returns it. */
int stack_pop(void)
{
    int last;
    
    last = stack_top();
    stack.size--;
    
    return last;
}

/* Pushes a given integer `n` at the top of the stack. */
void stack_push(int n)
{
    if (stack.size < MAX_SIZE)
    {
        stack.size++;
    }

    stack.values[stack.size - 1] = n;
}

/* Displays the content of the stack on the standard output. */
void stack_display(void)
{
    int i;
    
    for(i = stack.size - 1; i > -1; i--)
    {
        printf("Key: %d - Value: %d\n", i, stack.values[i]);
    }
}

/* Returns the element at index `index` inside the stack. The user is
   responsible of the use of this function. The answers may be not
   relevant if a call is done outside the current size of the
   stack. */
int stack_get_element(int index)
{
    return stack.values[index];
}
