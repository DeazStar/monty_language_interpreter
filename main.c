#include "monty.h"

int op_param = 0;
unsigned int line_number = 1;

stack_t *head;
/**
 * @brief
 *
 */


int main(int ac, char *argv[])
{
    FILE *fp;
    char *buffer = NULL;
    size_t len = 0;
    head = NULL;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file <%s>", argv[1]);
        exit(EXIT_FAILURE);
    }

    while(getline(&buffer, &len, fp) != -1)
    {
        process_file(buffer);
        line_number++;
    }

    return (0);


}