#include "monty.h"
/**
 * f_queue - function to print the top
 * @head: stack head
 * @count: line_number
 * Return: nothing
 */
void f_queue(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}

/**
 * add_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *check;

	check = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (check)
	{
		while (check->next)
			check = check->next;
	}
	if (!check)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		check->next = new_node;
		new_node->prev = check;
	}
}
