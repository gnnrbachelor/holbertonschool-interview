#include "lists.h"

/**
 * find_list - Finds loop in linked list
 * @head: Head
 * Return: Address of loop beginning or NULL
 *
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare = head;
	listint_t *tortoise = head;

	if (!head || !head->next)
		return (NULL);

	while (hare && hare->next)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (hare);
		}
	}
	return (NULL);
}

