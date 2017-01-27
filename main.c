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
	unsigned int line_num, cmd_stat;
	int j;
	instruction_t instruct[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		{"queue", _queue}, {"stack", _stack}
	};

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
		cmd_stat = 0;
		if (strlen(line) == 1 || strspn(line, " \r\n\t") == strlen(line))
			continue;
		cmd = get_cmd(line, line_num);
		for (j = 0; j < 17 && cmd != NULL; j++)
		{
			if (cmd[0] == '#')
				break;
			if (strcmp(instruct[j].opcode, cmd) == 0)
			{
				instruct[j].f(&head, line_num);
				cmd_stat = 1;
				break;
			}
		}
		if (cmd_stat == 0 && cmd[0] != '#')
		{
			printf("L%u: unknown instruction %s\n", line_num, cmd);
			glob[2] = 1;
			continue;
		}
		line_num++;
	}
	free(line);
	free_stack(&head);
	fclose(fp);
	if (glob[2] == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
