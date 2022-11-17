#include "search.h"

/**
 * printCheck - printing checked value message to make the
 * code look clean
 * @index: index
 * @value: value
 */
void printCheck(int index, int value)
{
	printf("Value checked at index [%d] = [%d] \n", index, value);
}

/**
 * printCompare - printing compared value message to make the
 * code look clean
 * @i: index
 * @p: previous index
 */
void printCompare(int i, int p)
{
	printf("Value found between indexes [%d] and [%d] \n", p, i);
}

/**
 * getTail - Get the Tail of the list
 * @list : skiplist
 * Return: skiplist_t*
 */
skiplist_t *getTail(skiplist_t *list)
{
	while (list->next)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

/**
 * linear - a function that searches for a value in a sorted linear list
 * @head : skiplist
 * @value : int
 * Return: skiplist_t* || NULL
 */
skiplist_t *linear(skiplist_t *head, int value)
{
	while (head)
	{
		if (head->n <= value)
			printCheck(head->index, head->n);
		if (head->n == value)
			return (head);
		head = head->next;
	}
	return (NULL);
}

/**
 * linear_skip - a function that searches for a value in a
 * sorted skip list of integers.
 * @head : skiplist
 * @value : int
 * Return: skiplist_t* || NULL
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *prev = head;
	int prev_index = 0;

	if (!head)
		return (NULL);
	while (head->next)
	{
		prev_index = head->index;
		prev = head;
		head = prev->express ? head->express : head->next;
		if (head->n == value)
		{
			return (head);
		}
		if (head->n < value)
		{
			printCheck(head->index, head->n);
		}
		if ((head->n > value && prev->n < value) || head->express == NULL)
		{
			if (head->n < value && head->express == NULL)
			{
				prev = head;
				prev_index = prev->index;
				printCompare(getTail(head)->index, prev_index);
			}
			else
			{
				printCheck(head->index, head->n);
				printCompare(head->index, prev_index);
				head = prev;
			}
			return (linear(head, value));
		}
	}
	return (NULL);
}
