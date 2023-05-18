#include "monty.h"

/**
 * @file: file of the functions.
 * @line_number: line of the number.
 * Return: 0 on success, 1 on failure
*/

char *lines_reader(char *file, unsigned int line_number)
{
    FILE *file_monty;

    char *line = NULL;
    size_t lenght_of_line = 0;
    ssize_t number_of_characters_read = 0;
    unsigned int i;

    file_monty = fopen(file,"r");

    if (file_monty == NULL)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file); 
        exit(EXIT_FAILURE); 
    }

    for(i = 1; i <= line_number; i++)
    {
        number_of_characters_read = getline(&line, &lenght_of_line, file_monty);
        
        if (number_of_characters_read == -1)
        {
            fclose(file_monty);
            free(line);
            return(NULL);
        }
            
        if (line_number == i)
        {
            fclose(file_monty);
            return(line);
        }

    }
    return (NULL);
}
