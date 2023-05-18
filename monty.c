#include "monty.h"

/**
 * main - Executes de commands of a monty file
 * @argc: Size of argv
 * @argv: Array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{

    unsigned int line_number = 1;
    char *command = NULL;
    char *line = NULL;

    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    for(; (line = lines_reader(argv[1], line_number)) != NULL; line_number++)
    {
        /* printf("%s\n", line); */
        
        command = strtok(line, " \r\t\n");
        if (command == NULL)
        {
            line_number++;
            continue;
        }

        if (strcmp(command, "push") == 0)
        {
            push(&stack, line_number);
        }
        else if (strcmp(command, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else
        {
            dprintf(STDERR_FILENO, "L%u: usage: unknown instruction %s\n", line_number, command);
            exit(EXIT_FAILURE);
        }

        /*
        if (strcmp(command, "nop") == 0)
        {
            nop(&stack, line_number);
        }
        */
        
        free(line);
    }

    return (EXIT_SUCCESS);
}
