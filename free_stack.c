#include "monty.h"
/**
 * free_stack - function to free double linked list
 * @head: pointer to  the stack
 */
void free_stack(stack_t *head)
{
	stack_t *check;

	check = head;
	while (head)
	{
		check = head->next;
		free(head);
		head = check;
	}
}
