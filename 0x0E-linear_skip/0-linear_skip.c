#include "search.h"

/**
 * check_slow - checks orig list
 * @fast:  fast lane
 * @list: list
 * @value: Value * Return: pointer to found node
 * Return: Found node
 */
skiplist_t *check_slow(skiplist_t *fast, skiplist_t *list, int value)
{
	for (list = fast; list != fast->express; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (value == list->n)
			break;
	}
	if (list == fast->express)
		return (NULL);
	else
		return (list);
}

/**
 * linear_skip - search for value in skip list
 * @list: pointer to head
 * @value: value
 * Return: pointer to found node
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *fast = list;
	skiplist_t *found;

	if (!list)
		return (NULL);

	while (fast->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			fast->express->index, fast->express->n);
		if (fast->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				fast->index, fast->express->index);
			break;
		}
		fast = fast->express;
	}

	if (!fast->express)
	{
		for (list = fast; list->next; list = list->next)
			;
		printf("Value found between indexes [%lu] and [%lu]\n",
			fast->index, list->index);
	}
	if (fast && list && value)
		found = check_slow(fast, list, value);
	else
		return (NULL);
	return (found);
}


