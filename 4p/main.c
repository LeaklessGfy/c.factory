#include <stdio.h>
#include "stack.h"

/* Will test stack */
int main(int argc, char* argv[])
{
    stack_init();
    
    printf("Stack is empty? (1 = yes, 0 = no): %d\n", stack_is_empty());
    
    printf("Adding value\n");
    stack_push(16);
    stack_push(35);
    stack_push(42);
	
	printf("Stack is empty? (1 = yes, 0 = no): %d\n", stack_is_empty());
    
    printf("Stack last element: %d\n", stack_top());
    printf("Stack size: %d\n", stack_size());
    
    printf("Pop valued: %d\n", stack_pop());
    
    printf("Adding value\n");
    stack_push(22);
    
    printf("Display the stack: \n");
    stack_display();
    
    printf("First element of stack: %d\n", stack_get_element(0));
    printf("Stack size: %d\n", stack_size());
    
    return 0;
}
