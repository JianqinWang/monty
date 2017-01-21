#include "monty.h"

void _mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	i = helper->n % temp->n;
	glob[0] = i;
	_pop(head, line_number);
	_pop(head, line_number);
	_push(head, line_number);
}

void _pchar(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp = find_end(head);
	printf("%c\n", temp->n);
}

void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp = find_end(head);
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->prev;
	}
	printf("\n");
}

void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;

	temp = find_end(head);
	printf("********************%d\n", temp->n);
	*head = add_node(head, temp->n);
}
