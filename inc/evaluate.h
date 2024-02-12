#ifndef EVALUATE_H
#define EVALUATE_H

#include "header.h"

/* function prototypes evaluate_exp.c */
bool evaluate_expression(string_array* tokens);
queue_t* infix_to_postfix(char** tokens, queue_t* queue);
bool evaluate_postfix(queue_t* queue);
void free_stack(c_stack_t* stack);

#endif