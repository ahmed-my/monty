#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	check = h->n + h->next->n;
	h->next->n = check;
	*head = h->next;
	free(h);
}
