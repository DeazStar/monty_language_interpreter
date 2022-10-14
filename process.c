#include "monty.h"

/**
 * @brief
 *
 */

void process_file(char *buffer)
{
    instruction_t insta[] = {{"push", op_push},
        {"pall", op_pall},
        {NULL, NULL}};

    int i = 0;
    char *dlim = "\n\t ";
    char *code = strtok(buffer, dlim);

    if (strcmp(code, "push") == 0)
    {
        op_param = atoi(strtok(NULL, dlim));

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