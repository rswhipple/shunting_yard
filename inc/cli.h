#ifndef _CLI_H
#define _CLI_H

#include "header.h"

/* function prototypes cli.c */
string_array* parse_user_input(int argc, char** argv);
int arg_to_string_array(char* expression, string_array* tokens);
bool is_balanced(char** tokens);
char* copy_numbers_to_string(char* dst, char* src, int* i);

#endif