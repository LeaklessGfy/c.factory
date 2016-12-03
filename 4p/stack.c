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
    if (stack.size == 0)
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
    stack.values[stack.size] = n;
	
	if (stack.size + 1 < MAX_SIZE)
	{
	    stack.size++;
	}
}

/* Displays the content of the stack on the standard output. */
void stack_display(void)
{
    int i;
    
    for(i = 0; i < stack.size; i++)
    {
        printf("%d\n", stack.values[i]);
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
