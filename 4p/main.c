#include <stdio.h>
#include "stack.h"

/* Simple stack displayer */
void print_stack(void)
{
    printf("Stack: \n");
    stack_display();
    printf("\n");
}

/* Test stack limitation size */
void robust_test(void)
{
    int i;

    stack_init();
    printf("\n\nROBUT TEST\n");
    for (i = 0; i < 43; i++)
    {
        stack_push(i);
    }
    printf("Stack size: %d\n", stack_size());

    stack_display();
}

/* Will test stack */
int main(int argc, char* argv[])
{
    stack_init();
    
    printf("Stack is empty? (1 = yes, 0 = no): %d\n", stack_is_empty());
    
    printf("Stack add value [16 - 35 - 42]...\n");
    stack_push(16);
    stack_push(35);
    stack_push(42);
    print_stack();
	
	printf("Stack is empty? (1 = yes, 0 = no): %d\n", stack_is_empty());
    
    printf("Stack last element: %d\n", stack_top());
    printf("Stack size: %d\n", stack_size());
    
    printf("Pop valued: %d\n", stack_pop());
    print_stack();
    
    printf("Stack add value [22 - 25]...\n");
    stack_push(22);
    stack_push(25);
    print_stack();
    
    printf("Stack first element: %d\n", stack_get_element(0));
    printf("Stack size: %d\n", stack_size());

    robust_test();
    
    return 0;
}
