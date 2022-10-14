#include "monty.h"

/**
 * process_file - breka the buffer in to opcode and parameter and assign the proper function
 * @buffer: a line of text
 *
 * Return: Nothing
 */

void process_file(char *buffer)
{
    instruction_t insta[] = {{"push", op_push},
        {"pall", op_pall},
        {"pint", op_pint},
        {"pop", op_pop},
        {"swap", op_swap},
        {"add", op_add},
        {"nop", op_nop},
        {NULL, NULL}};

    int i = 0;
    char *dlim = "\n\t ";
    char *code = strtok(buffer, dlim);
    char *is_digit = malloc(sizeof(char) * 20);

    if (strcmp(code, "push") == 0)
    {
        is_digit = strtok(NULL, dlim);

        if (is_digit == NULL)
        {
            fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        if (_isint(is_digit))
        {
            op_param = atoi(is_digit);
        }
        else
        {
            fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

    }

    while((insta[i].opcode) != NULL)
    {
        if (strcmp(insta[i].opcode, code) == 0)
        {
            insta[i].f(&head, line_number);
        }

        i++;
    }
}
