#ifndef HELPER_H
#define HELPER_H
#include "header.h"

/* function prototypes helper.c */
bool is_left_parenthesis(char c);
bool is_right_parenthesis(char c);
bool is_number(char c);
bool is_operator(char c);
int is_precedence(char* c);
bool is_space(char c);
int my_add(int param_1, int param_2);
int my_sub(int param_1, int param_2);
int my_mul(int param_1, int param_2);
int my_div(int param_1, int param_2);
int my_mod(int param_1, int param_2);
int my_strlen(char* str);
char* my_strcpy(char* dst, char* src);
int my_atoi(char* param_1);
char* my_itoa(int param_1);
void reverse_string(char* dst);
void parse_error(void);
void zero_error(void);
void free_string_array(string_array* array); 

#endif