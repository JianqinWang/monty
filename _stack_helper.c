#include "monty.h"

struct_t *add_node_end(struct_t **head, const int n)
{
	struct_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(struct_t));
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
