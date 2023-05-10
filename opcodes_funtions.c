#include "monty.h"

/**
 * push - push an integer
 * @stack: double pointer to head of stack
 * @line_number: line number of file we are processing
*/

void push(stack_t **stack, unsigned int line_number)
{
int d;
char *arg;

arg = strtok(NULL, "\n\t");
if (arg == NULL || check_digit(arg))
{
printf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
data = atoi(arg);
if (add_node(stack, d) == NULL)
{
printf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
}
