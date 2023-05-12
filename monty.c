#include "monty.h"

/**
 * main
 * @argc: Size of argv
 * @argv: Array of arguments
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "%s", "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
