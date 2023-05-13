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

    char *line = NULL;
    size_t lenght_of_line = 0;
    ssize_t number_of_characters_read = 0;

    unsigned int line_number = 1;
    char *command = NULL;

    /* stack_t **stack = NULL; */
    
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
    number_of_characters_read = getline(&line, &lenght_of_line, file);

    if (number_of_characters_read == -1)
        printf("This File is empty\n");
    
    if (line_number == 1)
        fclose(file);
    
    /* printf("%s\n", line); */

    command = strtok(line, " \n");
    /*
        if (command == NULL)

    */
    printf("%s\n", command);

    /*if (command == "push")
    {
        push(stack, line_number);
    } */

    segundo_token();

	return (EXIT_SUCCESS);
}
