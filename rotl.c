#include "monty.h"
/**
 *f_rotl- function to rotates the stack to the top
 *@head: stack head
 *@count: line_number
 *Return: no return
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int count)
{
	stack_t *temp = *head, *check;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	check = (*head)->next;
	check->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = check;
}
