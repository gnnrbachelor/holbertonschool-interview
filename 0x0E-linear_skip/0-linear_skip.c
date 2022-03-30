#include "search.h"

/**
 * part_two - completes skip list search
 * @prev:  prev node
 * @cur: cur node
 * @value: Value
 * Return: pointer to found node
 */
static skiplist_t *part_two(skiplist_t *prev, skiplist_t *cur, int value)
{
	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, cur->index);
	while (prev && prev->index <= cur->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);

		prev = prev->next;
	}
	return (NULL);
}

/**
 * linear_skip - search for value in skip list
 * @list: pointer to head
 * @value: value
 * Return: pointer to found node
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *cur, *prev, *found;

	if (!list)
		return (NULL);

	cur = list->express;
	prev = list;

	while (cur)
	{
		printf("Value checked at index [%lu] = [%d]\n", cur->index, cur->n);

		if (cur->n >= value)
			break;
		prev = cur;
		if (!cur->express)
		{
			while (!cur->next)
				cur = cur->next;
			break;
		}
		cur = cur->express;
	}
	found = part_two(prev, cur, value);
	return (found);

}


