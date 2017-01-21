#include "monty.h"

stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	return (new_node);
}

stack_t *find_end(stack_t **head)
{
	stack_t *temp;

	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->prev = NULL;
	new_node->next = *head;
	new_node->n = n;
	*head = new_node;
	return (*head);
}
