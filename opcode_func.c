#include "monty.h"


/**
 * op_push - pushes and element to the stack
 * @stack: the pointer that points to the head node
 * @line_number: the line number
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
 * op_pall - prints all the values on the stack, starting from the top of the stack
 * @stack: the pointer that points to the head node
 * @line_number: the line number
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

/**
 * op_pint - prints the value at the top of the stack, followed by a new line
 * @stack: the pointer that points to the head node
 * @line_number: the line number
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);

	line_number++;

}

/**
 * op_pop - removes the top element of the stack.
 * @stack: the pointer that points to the head node
 * @line_number: the line number
 */


void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	free(tmp);


}

/**
 * op_swap - swaps the topo two elements of the stack.
 * @stack: the pointer that points to the head node
 * @line_number: the line number
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *tmp2 = *stack;
	stack_t *tmp3 = NULL;
	int i = 0;

	while(tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = *stack;

	if (i < 2)
	{
		fprintf(stderr, "L<%d>: can't swap, stack tooo short", line_number);
		exit(EXIT_FAILURE);
	}

	if (i == 2)
	{
		tmp2 = tmp2->next;
		tmp->next = tmp2->next;
		tmp->prev = tmp2;
		tmp2->next = tmp;
		tmp2->prev = NULL;
	}

	if (i > 2)
	{
		tmp2 = tmp2->next;
		tmp3 = tmp2->next;
		tmp3->prev = tmp;
		tmp->next = tmp2->next;
		tmp->prev = tmp2;
		tmp2->next = tmp;
		tmp2->prev = NULL;
	}

	*stack = tmp2;


}

/**
 * op_add - adds the top two elements of the stack
 * @stack: the pointer that points to the head node
 * @line_number: the line number
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *tmp2 = *stack;
	int sum = 0;
	int i = 0;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}


	if (i < 2)
	{
		fprintf(stderr, "L<%d>: can't add, stack tooo short", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	sum = tmp->n;
	tmp = tmp->next;
	sum += tmp->n;

	tmp->n = sum;

	*stack = tmp;

	free(tmp2);

}

/**
 * op_nop - does nothing
 * @stack: the pointer that points to the head node
 * @line_number: the line number
 */

void op_nop(stack_t **stack, unsigned int line_number)
{
	return;
}