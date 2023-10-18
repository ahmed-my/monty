#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int count)
{
	stack_t *h;
	int length = 0, check;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	check = h->n;
	h->n = h->next->n;
	h->next->n = check;
}
