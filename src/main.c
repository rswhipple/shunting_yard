#include "../inc/helper.h"
#include "../inc/cli.h"
#include "../inc/evaluate.h" 

int main(int argc, char** argv)
{
    // PARSE
    string_array* tokens = NULL;
    if ((tokens = parse_user_input(argc, argv)) == NULL) {
        return EXIT_FAILURE;
    }   

    // EVALUATE EXPRESSION
    if (!evaluate_expression(tokens)) {
        free_string_array(tokens);
        return EXIT_FAILURE;
    }

    // DEALLOCATE MEMORY
    free_string_array(tokens);

    return EXIT_SUCCESS;
}