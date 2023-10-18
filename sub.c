#include "monty.h"
/**
 *f_sub- sustration
 *@head: stack head
 *@count: line_number
 *Return: no return
 */
void f_sub(stack_t **head, unsigned int count)
{
	stack_t *check;
	int diff, nodes;

	check = *head;
	for (nodes = 0; check != NULL; nodes++)
		check = check->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	check = *head;
	diff = check->next->n - check->n;
	check->next->n = diff;
	*head = check->next;
	free(check);
}
