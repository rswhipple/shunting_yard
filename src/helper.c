#include "../inc/helper.h"

bool is_left_parenthesis(char c)
{ 
    if (c == '(') {
        return true; 
    } else {
        return false;
    }
}

bool is_right_parenthesis(char c)
{
    if (c == ')') {
        return true; 
    } else {
        return false;
    }
}

bool is_number(char c)
{
    if (c >= '0' && c <= '9') {
        return true; 
    } else {
        return false;
    }
}

bool is_operator(char c)
{
    if (c == 37 || c == 42 || c == 43 || c == 45 || c == 47) {
        return true; 
    } else {
        return false;
    }
}

int is_precedence(char* c)
{
    int precedence = -1;

    if (c[0] == '(') {
        precedence = 0; 
    } else if (c[0] == 43 || c[0] == 45) {
        precedence = 1; 
    } else if (c[0] == 37 || c[0] == 42 || c[0] == 47){
        precedence = 2; 
    } else if (c[0] == ')') {
        precedence = 3; 
    }

    return precedence;
}

bool is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n') {
        return true; 
    } else {
        return false;
    }
}

int my_add(int param_1, int param_2)
{
    int value = param_1 + param_2; 
    return value;
}

int my_sub(int param_1, int param_2)
{
    int value = param_1 - param_2;
    return value;
}

int my_mul(int param_1, int param_2)
{
    int value = param_1 * param_2;
    return value;
}

int my_div(int param_1, int param_2)
{
    int value = param_1 / param_2;
    return value;
}

int my_mod(int param_1, int param_2)
{
    int value = param_1 % param_2;
    return value;
}

int my_strlen(char* str) 
{
    int i = 0;

    do {
        i += 1;
    } while (str[i] != '\0');

    return i;
}

char* my_strcpy(char* dst, char* src)
{
    int i;
    int len = my_strlen(src);

    for (i = 0; i < len; i++) {
        dst[i] = src[i]; 
    }

    dst[i] = '\0';

    return dst;
}

int my_atoi(char* param_1) // NO NEED TO HANDLE NEGATIVE NUMBERS
{
    int output = 0;
    int i = 0;

    while (i < my_strlen(param_1)) {
        output *= 10;
        output += param_1[i] - '0';
        i++;
    }

    free(param_1);

    return output;
}

char* my_itoa(int param_1)
{
    char* result = malloc(sizeof(char) * 10);
    int i = 0;

    while (param_1 != 0) {
        result[i] = param_1 % 10 + '0';
        param_1 /= 10;
        i += 1;
    }
    result[i] = '\0';
    reverse_string(result);

    return result;
}

void reverse_string(char* dst)
{
    int len = my_strlen(dst);
    int i = 0;
    char temp;

    while (i < len / 2) {
        temp = dst[i];
        dst[i] = dst[len - 1 - i];
        dst[len - 1 - i] = temp;
        i += 1;
    }

}

void parse_error(void) 
{
    char* error = "parse error\n";
    write(2, error, my_strlen(error)); 
}

void zero_error(void) 
{
    char* error = "divide by zero\n";
    write(2, error, my_strlen(error)); 
}

void free_string_array(string_array* tokens)  
{
    int i = 0;

    while (i < tokens->size) {
        free(tokens->array[i]);
        i += 1;
    }

    free(tokens->array);
    free(tokens);
}

