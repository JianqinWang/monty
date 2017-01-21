#include "monty.h"

/**
 * _push - function that will push integer n onto stack
 * @head: start of stack
 * @line_number: line number in file
 * Return: nothing
 */
void _push(stack_t **head, unsigned int line_number)
{
	(void) line_number;

	printf("enter push\n");
	if (glob[1] == 0)
		add_node_end(head, glob[0]);
	else
		add_node(head, glob[0]);
}

/**
 * _pall - function that wil print everything out on stack
 * @head: beginning of stack
 * @line_number: line_number in file
 * Return: nothing
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	printf("enter pall\n");
	if (*head != NULL)
	{
		temp = find_end(head);
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}
	printf("finish\n");
}

/**
 * _pint - function that will print first int in stack
 * @head: beginning of stack
 * @line_number: line number of line in file
 * Return: nothing
 */
void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	printf("-------------------------------------------\n");
	temp = find_end(head);
	if (temp == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", temp->n);
}

/**
 * _pop - function that will "pop" the most recent item off stack
 * @head: beginning of stack
`* @line_number: line number in file
 * Return: nothing
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;

	printf("enter pop\n");
	if (*head == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = find_end(head);
	helper = temp->prev;
	if (helper != NULL)
		helper->next = NULL;
	else
		*head = NULL;
	free(temp);
}

/**
 * _swap - swap the location of the top two values in the stack
 * @head: beginning of the stack
 * @line_number: the line number of command in the file
 * Return: nothing
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *helper;
	int help;

	temp = find_end(head);
	printf("enter swap\n");
	if (temp == NULL || temp->prev == NULL )
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	helper = temp->prev;
	printf("%d, %d\n", temp->n, helper->n);
	help = temp->n;
	temp->n = helper->n;
	helper->n = help;
}
