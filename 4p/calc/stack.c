#include <stdio.h>
#include "stack.h"

static Stack stack;

void stack_init(void)
{
    stack.size = 0;
}

int stack_size(void)
{
    return stack.size;
}

int stack_is_empty(void)
{
    if (stack.size == 0)
        return 1;
    
    return 0;
}

int stack_top(void)
{
    return stack.values[stack.size - 1];
}

int stack_pop(void)
{
    int p;
    
    p = stack_top();
    stack.size--;
    
    return p;
}

void stack_push(int n)
{
    stack.values[stack.size] = n;
    stack.size++;
}

void stack_display(void)
{
    int i;
    
    for(i = 0; i < stack.size; i++)
    {
        printf("%d\n", stack.values[i]);
    }
}

int stack_get_element(int index)
{
    return stack.values[index];
}
