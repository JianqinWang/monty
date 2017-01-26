#include "monty.h"

int glob[] = {0, 0};
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
	printf("begin reading\n");
	while ((read = getline(&line, &len, fp)) != -1)
	{
		cmd_stat = 0;
		printf("begin reading file\n");
		if (strlen(line) == 1)
			break;
		cmd = get_cmd(line, line_num);
		printf("got the cmd %s\n", cmd);
		for (j = 0; j < 17; j++)
		{
			if (cmd[0] == '#')
				break;
			if (strcmp(instruct[j].opcode, cmd) == 0)
			{
				printf("found function\n");
				instruct[j].f(&head, line_num);
				cmd_stat = 1;
				break;
			}
			printf("%s\n%s\n%d\n", cmd, instruct[j].opcode, strcmp(instruct[j].opcode, cmd));
		}
		if (cmd_stat == 0)
		{
			printf("L%u: unknown instruction %s\n", line_num, cmd);
			free_stack(&head);
			exit(EXIT_FAILURE);
		}
		printf("break loop\n");
		line_num++;
		printf("linenum change\n");
	}
	free_stack(&head);
	fclose(fp);
	if (line)
		free(line);
	free_stack(&head);
}
