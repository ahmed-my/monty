#include "monty.h"
#include <stdio.h>

/**
 * f_pall - prints the stack
 * @stack: double pointer to the stack
 * @counter: line number
 */
void f_pall(stack_t **stack, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	if (!stack || !*stack)
		return;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
