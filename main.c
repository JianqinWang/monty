#include "monty.h"

int glob[] = {0, 0};
int main(int argc, char **argv)
{
	FILE *fp;
	char *line, *cmd;
	size_t len;
	ssize_t read;
	stack_t *head;
	unsigned int line_num;
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
		printf("couldn't open file\n");
		exit(EXIT_FAILURE);
	}
	line_num = 1;
	printf("begin reading\n");
	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("begin reading file\n");
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
				break;
			}
			printf("%s\n%s\n%d\n", cmd, instruct[j].opcode, strcmp(instruct[j].opcode, cmd));
		}
		printf("break loop\n");
		line_num++;
		printf("linenum change\n");
	}

	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
