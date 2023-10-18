#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack;
	unsigned int count;
	char *content;
	size_t size;
	ssize_t read_line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	stack = NULL;
	count = 0;
	content = NULL;
	size = 0;
	while ((read_line = getline(&content, &size, file)) > 0)
	{
		bus.file = file;
		bus.content = content;
		count++;

		execute(content, &stack, count, file);

		free(content);
		content = NULL;
	}
	free_stack(stack);
	free(content);
	fclose(file);
	return (EXIT_SUCCESS);
}
