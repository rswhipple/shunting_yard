#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define _SIZE_STACK 101

/* structs */
struct stack_s {
    char* data[_SIZE_STACK];
    int top;    // like the index
}; 
typedef struct stack_s c_stack_t;

struct postfix_queue_s {
    c_stack_t stack_1;
    c_stack_t stack_2;
    char* front;
    bool (*is_empty)(c_stack_t*);
    int (*push)(c_stack_t*, char*);
    char* (*pop)(c_stack_t*);
};
typedef struct postfix_queue_s queue_t;

struct string_array_s {
    int size;
    char** array;
};
typedef struct string_array_s string_array;


#endif