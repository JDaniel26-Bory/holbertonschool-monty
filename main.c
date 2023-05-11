#include "monty.h"

int error = 0;

/**
 * main - monty program
 * @argc: argument count
 * @argv: array of argument
 * Return: error
*/

int main(int argc, char **argv)
{
FILE *f;
stack_t *stack = NULL;
unsigned int line_number = 0;
char str[1024];
char *t = NULL;
size_t n = 1024;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
f = fopen(argv[1], "r");
if (f == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (fgets(str, n, f) != NULL && error != 1)
{
line_number++;
t = strtok(str, "\n\t");
if (t != NULL)
{
check_opcode(t, &stack, line_number);
}
}
free_all(stack, f);
if (error == 1)
exit(EXIT_FAILURE);
return (EXIT_SUCCESS);
}
