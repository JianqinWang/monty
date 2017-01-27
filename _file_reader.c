#include "monty.h"
/**
 * get_cmd - parse the command found from line from text file
 * @line: line to parse
 * @line_num: line number of command in text flie
 * Return: the command found from getline
 */
char *get_cmd(char *line, unsigned int line_num)
{
	long int i;
	char *ptr;
	char *t, *temp_num;

	t = strtok(line, " \n\t");
	if (strcmp(t, "push") == 0)
	{
		temp_num = strtok(NULL, " ");
		if (temp_num == NULL)
		{
			printf("L%u: usage: push integer\n", line_num);
			glob[2] = 1;
			return(NULL);
		}
		i = strtol(temp_num, &ptr, 10);
		if (errno == ERANGE || (*ptr != '\0' && *ptr != '\n'
					&& *ptr != ' ' && *ptr != '\t')
			|| i > INT_MAX || i < INT_MIN)
		{
			printf("L%u: usage: push integer\n", line_num);
			glob[2] = 1;
			return(NULL);
		}
		glob[0] = i;
	}
	return t;
}
