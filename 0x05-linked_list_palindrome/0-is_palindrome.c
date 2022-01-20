#include "lists.h"

/**
 * is_palindrome - Checks if linked list is palindrome
 * @head: Head
 * Return: 1 or 0
 */



int is_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *rev = NULL;
	int is_pali = 1;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = rev = reverse(slow);
	slow = *head;
	while (fast)
	{
		if (fast->n != slow->n)
		{
			is_pali = 0;
			break;
		}
		fast = fast->next;
		slow = slow->next;
	}
	return (is_pali);

}


/**
 * reverse - Reversed linked lists
 * @cur: Current node
 * Return: Pointer to new head
 */

listint_t *reverse(listint_t *cur)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return (prev);
}

