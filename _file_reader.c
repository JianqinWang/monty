#include "monty.h"
/**
 * get_cmd - parse the command found from line from text file
 * @line: line to parse
 * @line_num: line number of command in text flie
 * Return: the command found from getline
 */
char *get_cmd(char *line, unsigned int line_num)
{
	int i;
	char *ptr;
	char *t, *temp_num, *helper;

	printf("enter get_cmd\n");
	t = strtok(line, " \n\t");
	printf("glob is %d %d\n", glob[0], glob[1]);
	if (strcmp(t, "push") == 0)
	{
		printf("enter\n");
		temp_num = strtok(NULL, " ");
		printf("temp_num is %s\n", temp_num);
		if (temp_num == NULL || strlen(temp_num) == 1)
		{
			printf("L%u: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		i = strtol(temp_num, &ptr, 10);
		printf("errno is %d\n", errno);
		if (errno == ERANGE || (*ptr != '\0' && *ptr != '\n'
					&& *ptr != ' ' && *ptr != '\t'))
		{
			printf("L%u: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		glob[0] = i;
		printf("set global\n");
	}
	printf("going to exit get_cmd\n");
	return t;
}
