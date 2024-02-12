#include "../inc/cli.h"
#include "../inc/stack.h"
#include "../inc/helper.h"

string_array* parse_user_input(int argc, char** argv)
{
    // If there are more than 2 arguments, stderr
    if (argc != 2) {
        parse_error();
        return NULL;
    } 

    // Initiate string_array*
    string_array* tokens = malloc(sizeof(string_array) * 1);

    // Turn the expression into tokens
    if (arg_to_string_array(argv[1], tokens)) {
        // In case of error, send error message and free array
        parse_error(); 
        free_string_array(tokens);
        return NULL;
    }

    // Check to see if the expression is balanced
    if (!is_balanced(tokens->array)) {
        // In case of error, send error message and free array
        parse_error();
        free_string_array(tokens);
        return NULL;
    }

    return tokens;
}

int arg_to_string_array(char* expression, string_array* tokens) 
{
    // Get length of expression add 2 for NULL and '\0'
    int len = my_strlen(expression) + 2;

    // Initiate tokens array
    tokens->array = malloc(sizeof(char*) * len); 
    tokens->size = 0;
    for (int i = 0; i < len; i++) {
        tokens->array[i] = NULL;
    }

    int i = 0;
    int z = 0;
   
    while (expression[i] != '\0') {
        // If there is a space, skip it
        if (is_space(expression[i])) {
            i += 1;
        } 
        // If there is a number
        else if (is_number(expression[i])) {
            tokens->array[z] = copy_numbers_to_string(tokens->array[z], expression, &i); 
            tokens->size += 1;
            z += 1;
        } 
        // If there is an operator or parenthesis
        else if (is_operator(expression[i]) || is_left_parenthesis(expression[i]) || is_right_parenthesis(expression[i])) {
            tokens->array[z] = malloc(sizeof(char) * 2);
            tokens->array[z][0] = expression[i];
            tokens->array[z][1] = '\0';
            tokens->size += 1;
            i += 1;
            z += 1;
        } 
        // If there is an invalid character, parse error
        else {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}


bool is_balanced(char** tokens)
{
    c_stack_t stack = create_stack();
    int i = 0;

    // Check to see if all left parenthesis have a matching right parenthesis
    while (tokens[i] != NULL) {
        if (is_left_parenthesis(tokens[i][0])) {
            push(&stack, tokens[i]);
        } else if (is_right_parenthesis(tokens[i][0])) {
            if (is_empty(&stack)) {
                return false;
            } else if (is_left_parenthesis(tokens[i - 1] [0])) {
                return false;
            } else {
                pop(&stack);
            }
        }
        i++;
    }

    // Check that there are no leftover parenthesis
    if (is_empty(&stack)) {
        return true;
    } else {
        return false;
    }
}

char* copy_numbers_to_string(char* dst, char* src, int* i) 
{
    int j = 0;
    int placeholder = *i;

    // Find length of number
    while (is_number(src[*i])) {
        j += 1;
        *i += 1;
    }

    // Allocate memory for number
    dst = malloc(sizeof(char) * (j + 1));

    // Initialize token
    int l = 0;
    while (l < j + 1) {
        dst[l] = 0;
        l += 1;
    }

    // Add number to token
    l = 0;
    while (l < j) {
        dst[l] = src[placeholder];
        placeholder += 1;
        l += 1;
    }

    // Null terminate
    dst[j] = '\0';

    // Return expression index 
    return dst;
}

