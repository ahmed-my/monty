#include "monty.h"
/**
 * f_mod - function to implement the mod opcode
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @count: line_number
 * Return: nothing
 */
void f_mod(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	check = h->next->n % h->n;
	h->next->n = check;
	*head = h->next;
	free(h);
}
