#include "monty.h"
/**
 * f_mul - function to multiply the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: nothing
 */
void f_mul(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	check = h->next->n * h->n;
	h->next->n = check;
	*head = h->next;
	free(h);
}
