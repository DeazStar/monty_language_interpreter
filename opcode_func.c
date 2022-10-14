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
	(void) stack;
	(void) line_number;
	return;
}

/**
 * op_sub - subtracts the top two elements of the stack
 * @stack: the pointer that points to the head node
 * @line_number: the line number
 */

void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *tmp2 = *stack;
	int sub = 0;
	int i = 0;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}


	if (i < 2)
	{
		fprintf(stderr, "L<%d>: can't subtract, stack tooo short", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	sub = tmp->n;
	tmp = tmp->next;
	sub -= tmp->n;

	sub = sub * -1;

	tmp->n = sub;

	*stack = tmp;

	free(tmp2);
}

/**
 * op_div - divide the top two elements of the stack
 * @stack: the pointer that points to the head node
 * @line_number: the line number
 */

void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *tmp2 = *stack;
	int div;
	int i = 0;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}


	if (i < 2)
	{
		fprintf(stderr, "L<%d>: can't divide, stack tooo short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;

	tmp2 = tmp->next;

	if (tmp2->n == 0)
	{
		fprintf(stderr, "L<%d>: division by zero\n", line_number);
	}

	div = tmp2->n;

	div = div / tmp->n;

	tmp2->n = div;

	*stack = tmp2;

	free(tmp);
}

/**
 * op_mul - multiply the top two elements of the stack
 * @stack: the pointer that points to the head node
 * @line_number: the line number
 */

void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *tmp2 = *stack;
	int mul;
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

	tmp2 = tmp->next;

	mul = tmp2->n;

	mul = mul * tmp->n;

	tmp2->n = mul;

	*stack = tmp2;

	free(tmp);
}

/**
 * op_mod - modules the top two elements of the stack
 * @stack: the pointer that points to the head node
 * @line_number: the line number
 */

void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *tmp2 = *stack;
	int mod;
	int i = 0;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}


	if (i < 2)
	{
		fprintf(stderr, "L<%d>: can't mod, stack tooo short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;

	tmp2 = tmp->next;

	if (tmp2->n == 0)
	{
		fprintf(stderr, "L<%d>: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = tmp2->n;

	mod = mod % tmp->n;

	tmp2->n = mod;

	*stack = tmp2;

	free(tmp);
}

/**
 * op_pchar - prints the char at the top of the stack.
 * @stack: the pointer that points to the head node
 * @line_number: the line number
 */

void op_pchar(stack_t **stack, unsigned int line_number)
{
	int n = (*stack)->n;
	if ((n >= 0 && n <= 255))
	{
		putchar((*stack)->n);
		printf("\n");
		return;
	}

	fprintf(stderr, "L<%d>: can't pchar, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
