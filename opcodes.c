#include "monty.h"

/**

*/

void opcode(char *op, stack_t **stack, unsigned int line_number)
{
int i = 0;
instruction_t check_op[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop},
{NULL, NULL}
};
for (; check_op[i].opcode != NULL, i++)
{
if (strcmp(op, check_op[i].opcode) == 0)
{
check_op[i].f(stack, line_number);
return;
}
}
printf(stderr, "L%u: unknown instruction %s\n", line_number, op);
exit(EXIT_FAILURE);
}
