#include "monty.h"

/**
 * add_node_end - add node to the end of the list
 * @head: beginning of the stack
 * @n: value to add to the linked list
 * Return: location of new_node
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	printf("enter add_node_end\n");
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

/**
 * find_end - find the end of the linked list
 * @head: beginning of stack
 * Return: last element in the linked list
 */
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

/**
 * add_node - add node at the beginning of the linked list
 * @head: beginnig of linked list
 * @n: value to add
 * Return: beginning
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	printf("enter add_node\n");
	temp = *head;
	printf("lol\n");
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->prev = NULL;
	printf("it's still working\n");
	new_node->next = *head;
	new_node->n = n;
	if (temp != NULL)
		temp->prev = new_node;
	printf("reset head\n");
	*head = new_node;
	return (new_node);
}
