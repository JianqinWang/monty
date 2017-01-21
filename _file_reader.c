#include "monty.h"

char *get_cmd(char *line, unsigned int line_num)
{
	int i;
	char *t, *temp_num;

	t = strtok(line, " \n\t");
	printf("glob is %d %d\n", glob[0], glob[1]);
	if (strcmp(t, "push") == 0)
	{
		printf("enter\n");
		temp_num = strtok(NULL, " ");
		printf("temp_num is %s\n", temp_num);
		if (temp_num == NULL)
		{
			printf("L%u: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		for (i = 0; temp_num[i] >= 32 && temp_num[i] <= 126; i++)
		{
			printf("temp_num[i] is %c\n", temp_num[i]);
			if (temp_num[i] > '9' || temp_num[i] < '0')
			{
				printf("temp_num[i] is %c\n", temp_num[i]);
				printf("L%u: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
		}
		printf("run atoi\n");
		i = atoi(temp_num);
		printf("got atoi\n");
		glob[0] = i;
		printf("set global\n");
	}
	printf("going to exit get_cmd\n");
	return t;
}
