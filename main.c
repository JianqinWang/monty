 #include "monty.h"

long int glob[] = {0, 0, 0};
/**
 * main - the main execution frame for monty interpreter
 * @argc: number of arguments read from command line
 * @argv: the commands read from command line as array
 * Return: EXIT_SUCCESS for success, EXIT_FAILURE if any failures
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *line, *cmd;
	size_t len;
	ssize_t read;
	stack_t *head;
	unsigned int line_num;

	len = 0;
	line = NULL;
	head = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_num = 1;
	while ((read = getline(&line, &len, fp)) != -1 && glob[2] != 1)
	{
		if (strlen(line) == 1 || strspn(line, " \r\n\t") == strlen(line))
			continue;
		cmd = get_cmd(line, line_num);
		if (cmd == NULL)
			break;
		check_op_code(&head, cmd, line_num);
		line_num++;
	}
	free(line);
	free_stack(&head);
	fclose(fp);
	if (glob[2] == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
