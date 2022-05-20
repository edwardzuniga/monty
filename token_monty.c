#include "monty.h"

/**
 * is_num - checks to see if input is a number
 * @str: input to check for numberhood
 * Return: 1 if it is a number, 0 if not
 */

int is_num(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

/**
 * get_token - get tokens from line
 * @line: line from file
 * @line_num: line number
 *
 * Return: int
 */

char *get_token(char *line, unsigned int line_num)
{
	char delim[2] = "\n ";
	char *token = NULL;
	char *holder = NULL;

	token = strtok(line, delim);
	if (token == NULL)
		return (NULL);
	holder = strtok(NULL, delim);
	if (holder != NULL)
	{
		if (is_num(holder))
			global_var = atoi(holder);
		else
		{
			printf("L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	else if (holder == NULL && strcmp(token, "push") == 0)
	{
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	return (token);
}
