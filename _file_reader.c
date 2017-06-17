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
	char *t, *temp_num;

	t = strtok(line, "\n\t \r");
	if (strcmp(t, "push") == 0)
	{
		temp_num = strtok(NULL, "\n\t \r");
		if (temp_num == NULL)
		{
			printf("L%u: usage: push integer\n", line_num);
			glob[2] = 1;
			return (NULL);
		}

		for (i = 0; temp_num[i] != '\0'; i++)
		{
			if (i == 0 && (temp_num[i] == '+' || temp_num[i] == '-'))
				continue;
			if (temp_num[i] < '0' || temp_num[i] > '9')
			{
				printf("L%u: usage: push integer\n", line_num);
				glob[2] = 1;
				return (NULL);
			}
		}
		glob[0] = atoi(temp_num);
	}
	return (t);
}
/**
 * check_op_code - check if the cmd found is one of the built-in opcodes.
 * If op code is found, program will execute
 * @head: pointer to the bottom of the stack
 * @cmd: the cmd being checked if it is built-it
 * @line_num: line num where the command was found.
 */

void check_op_code(stack_t **head, char *cmd, unsigned int line_num)
{
	int j;
	unsigned int cmd_stat;
	/* list of opcodes */
	instruction_t instruct[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		{"queue", _queue}, {"stack", _stack}
	};

	cmd_stat = 0;
	for (j = 0; j < 17 && cmd != NULL; j++)
	{
		if (cmd[0] == '#')
			break;
		if (strcmp(instruct[j].opcode, cmd) == 0)
		{
			instruct[j].f(head, line_num);
			cmd_stat = 1;
			break;
		}
	}
	if (cmd_stat == 0 && cmd[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_num, cmd);
		glob[2] = 1;
	}
}
