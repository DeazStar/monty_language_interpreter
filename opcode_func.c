#include "monty.h"


/**
 * @brief
 *
 */

void op_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new = malloc(sizeof(stack_t));

    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }

    new->n = op_param;
    new->prev = NULL;
    new->next = *stack;

    *stack = new;

    new = NULL;

    free(new);

    line_number++;
}


/**
 * @brief
 *
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;

    if (*stack == NULL)
    {
        return;
    }

    while (tmp != NULL)
    {
        fprintf(stdout, "%d\n", tmp->n);
        tmp = tmp->next;
    }

    free(tmp);

    line_number++;
}
