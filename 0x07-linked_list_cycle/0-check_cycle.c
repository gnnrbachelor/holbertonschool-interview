#include "lists.h"

/**
 * check_cycle - checks for cycle in linked list
 * @list: Linked List
 * Return: 1 or 0
 *
 */


int check_cycle(listint_t *list)
{
	listint_t *fast = list;
	listint_t *slow = list;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
			return (1);
	}
	return (0);
}
