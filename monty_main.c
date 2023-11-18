#include "monty.h"
#include <stdio.h>


FILE *file;

/**
 * main - function
 * @argc : argument
 * @argv : arg
 *
 * Return : 0 if successed
 */
int main(int argc, char *argv[])
{
	void (*opr)(stack_t **stack, unsigned int ln);
	size_t buffer = 1024, line_count = 0;
	ssize_t l;
	stack_t *tmp = NULL;
	char *files = NULL, *par, *args[2];

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");

	if (!file)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		l = getline(&files, &buffer, file);
		if (l == -1)
			break;
		line_count++;
		args[0] = strtok(files, "\n");
		if (!args[0] || args[0][0] == '#')
			continue;
		else if (strcmp("push", args[0]) == 0)
		{
			par = strtok(NULL, "\n");
			push(&tmp, par, line_count);
		}
		else
		{
			opr = hndle(args[0], line_count, &tmp);
			if (opr == NULL)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n", line_count, args[0]);
				exit(EXIT_FAILURE);
			}
			opr(&tmp, line_count);
		}
	}
	fclose(file), free(files), freee(tmp);
	return (0);
}
