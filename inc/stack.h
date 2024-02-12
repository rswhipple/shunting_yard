#ifndef STACK_H
#define STACK_H

#include "header.h"

/* function prototypes stack.c */
c_stack_t create_stack();
int push(c_stack_t* stack, char* token);
char* pop(c_stack_t* stack);
char* top(c_stack_t* stack) ;
bool is_empty(c_stack_t* stack);

#endif