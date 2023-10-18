#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int count)
{
	int m, t = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			t++;
		for (; bus.arg[t] != '\0'; t++)
		{
			if (bus.arg[t] > 57 || bus.arg[t] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	m = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, m);
	else
		addqueue(head, m);
}
