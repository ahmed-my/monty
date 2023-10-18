#include "monty.h"
/**
 *f_rotr- function to rotates the stack to the bottom
 *@head: stack head
 *@count: line_number
 *Return: nothing
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *make;

	make = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (make->next)
	{
		make = make->next;
	}
	make->next = *head;
	make->prev->next = NULL;
	make->prev = NULL;
	(*head)->prev = make;
	(*head) = make;
}
