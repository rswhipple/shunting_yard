#include "../inc/evaluate.h"
#include "../inc/stack.h"
#include "../inc/queue.h"
#include "../inc/helper.h"

bool evaluate_expression(string_array* tokens)
{
    queue_t queue = create_queue();

    // Convert infix to postfix
    infix_to_postfix(tokens->array, &queue); 
    
    // Evaluate postfix expression
    if(!evaluate_postfix(&queue)) {
        return false;
    }

    return true;
}

queue_t* infix_to_postfix(char** tokens, queue_t* queue)
{
    c_stack_t stack = create_stack();

    // Employment of shunting-yard algorithm
    int i = 0;
    while (tokens[i] != NULL) {
        int p = is_precedence(tokens[i]);
        if (is_number(tokens[i][0])) {
            en_queue(queue, tokens[i]);
        } else if (p == 0) {
            push(&stack, tokens[i]);
        } else if (p == 1) {
            if (is_empty(&stack) || is_left_parenthesis(top(&stack)[0])) {
                push(&stack, tokens[i]);
            } else {
                while (!is_empty(&stack) && is_precedence(top(&stack)) >= p) {
                    en_queue(queue, pop(&stack));
                }
                push(&stack, tokens[i]);
            }
        } else if (p == 2) {
            if (is_empty(&stack) || is_precedence(top(&stack)) < p) {
                push(&stack, tokens[i]);
            } else {
                while (!is_empty(&stack) && is_precedence(top(&stack)) >= p) {
                    en_queue(queue, pop(&stack));
                }
                push(&stack, tokens[i]);
            }
        } else if (p == 3) {
            if (is_left_parenthesis(top(&stack)[0])) {
                pop(&stack);
            } else {
                while (!is_empty(&stack) && !is_left_parenthesis(top(&stack)[0])) {
                    en_queue(queue, pop(&stack));
                }
                pop(&stack);
            }
        }
        i++;
    }

    // Pop remaining operators from stack
    while (!is_empty(&stack)) {
        en_queue(queue, pop(&stack));
    }
    
    return queue;
}

bool evaluate_postfix(queue_t* queue)
{
    int result = 0;
    char* token;
    c_stack_t stack = create_stack();

    while ((token = de_queue(queue)) != NULL) {
        // If number, add to stack
        if (is_number(token[0])) {
            int len = my_strlen(token) + 1;
            char* temp = malloc(sizeof(char) * len);
            my_strcpy(temp, token);
            push(&stack, temp);
        } 
        // If operator
        else if (is_operator(token[0])) {
            // Check that there are at least 2 tokens in stack
            if (stack.top < 1) {
                parse_error();
                free_stack(&stack);
                return false;
            } 
            // Pop top 2 tokens from stack, convert to int, assign as operands
            int operand_right = my_atoi(pop(&stack)); 
            int operand_left = my_atoi(pop(&stack)); 

            // Do math
            if (token[0] == '%') {
                push(&stack, my_itoa(my_mod(operand_left, operand_right)));
            } else if (token[0] == '*') {
                push(&stack, my_itoa(my_mul(operand_left, operand_right)));
            } else if (token[0] == '/') {
                // Check for division by zero
                if (operand_right == 0) {
                    zero_error();
                    free_stack(&stack);
                    return false;
                }
                push(&stack, my_itoa(my_div(operand_left, operand_right)));
            } else if (token[0] == '+') {
                push(&stack, my_itoa(my_add(operand_left, operand_right)));
            } else if (token[0] == '-') {
                push(&stack, my_itoa(my_sub(operand_left, operand_right)));
            }
        }
    }

    // If there is more or less than 1 number in the stack, expression is invalid
    if (stack.top != 0) {
        parse_error();
        free_stack(&stack);
        return false;
    }

    // Pop result
    result = my_atoi(pop(&stack)); 

    // Print result
    printf("%i\n", result);

    return true;
}

void free_stack(c_stack_t* stack) {
    while(!is_empty(stack)) {
        free(pop(stack));
    }
}
