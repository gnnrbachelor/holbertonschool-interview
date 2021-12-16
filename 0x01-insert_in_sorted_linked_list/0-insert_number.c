#include "lists.h"


/**
 * insert_node - Inserts node in sorted linked list
 * @head: head
 * @number: number
 * Return: Pointer to new node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *n_node = NULL;
	listint_t *cur = *head;
	listint_t *prev = NULL;

	n_node = malloc(sizeof(listint_t));
	if (n_node == NULL)
		return (NULL);
	n_node->n = number;
	if (*head == NULL)
		*head = n_node;
	else
	{
		while (cur->next)
		{
			if (cur->n < n_node->n)
			{
				prev = cur;
				cur = cur->next;
			}
			else
				break;
		}
		if (cur->n < n_node->n && cur->next == NULL)
		{
			n_node->next = cur->next;
			cur->next = n_node;
		}
		else if (!prev)
		{
			n_node->next = cur;
			*head = n_node;
		}
		else
		{
			prev->next = n_node;
			n_node->next = cur;
		}
	}
	return (n_node);
}
