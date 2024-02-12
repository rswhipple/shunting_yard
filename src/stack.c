#include "../inc/stack.h"

c_stack_t create_stack() 
{
    c_stack_t stack;
    stack.top = -1;

    return stack;
}

int push(c_stack_t* stack, char* token)
{
    // Check if stack is full
    if (stack->top > _SIZE_STACK - 1) {
        printf("stack overflow\n");
        return EXIT_FAILURE;
    }
    // Add token to stack
    stack->data[++stack->top] = token;

    return EXIT_SUCCESS;
}

char* pop(c_stack_t* stack) 
{
    // Check if stack is empty
    if (stack->top < 0) {
        printf("stack empty\n");
        return NULL;
    }

    // Return & change top of stack
    return stack->data[stack->top--];
}

char* top(c_stack_t* stack) 
{
    // Check if stack is empty
    if (stack->top < 0) {
        printf("stack empty\n");
        return NULL;
    }

    // Return top of stack
    return stack->data[stack->top];
}

bool is_empty(c_stack_t* stack) 
{
    if (stack->top == -1) {
        return true;
    } else {
        return false;
    }
}
