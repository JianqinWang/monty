#include "monty.h"

/**
 * _mod - find the mod of the top number from the second to top numbers
 * @head: beginning of the stack
 * @line_number: the line number of command in file
 * Return: nothing
 */
void _mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int i;

	temp = find_end(head);
	if (temp == NULL || temp->prev == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	if (temp->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	i = helper->n % temp->n;
	_pop(head, line_number);
	_pop(head, line_number);
	add_node_end(head, i);
}

/**
 * _pchar - print out the value at top of the stack as a character
 * @head: beginning of the stack
 * @line_number: line number of command in file
 * Return: nothing
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp = find_end(head);
	if (temp == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if (temp->n >= 32 && temp->n <= 127)
		printf("%c\n", temp->n);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pstr - print out the entire stack as a string
 * @head: beginning of the stack
 * @line_number: line number of command in file
 * Return: nothing
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	temp = find_end(head);
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->prev;
	}
	printf("\n");
}

/**
 * _rotl - move the value from top of stack to bottom of stack
 * @head: beginning of the stack
 * @line_number: line number of command in file
 * Return:; nothing
*/
void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (*head == NULL)
		return;
	temp = find_end(head);
	add_node(head, temp->n);
	while (temp != NULL)
	{
		temp = temp->prev;
	}
	_pop(head, line_number);
}

/**
 * _rotr - move the value from the bottom of the stack to top
 * @head: beginning of the stack
 * @line_number: lnie number of command in file
 * Return: nothing
*/
void _rotr(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	(void) line_number;

	if (*head == NULL)
		return;
	temp = *head;
	add_node_end(head, temp->n);
	helper = temp->next;
	helper->prev = NULL;
	*head = helper;
	free(temp);
}
