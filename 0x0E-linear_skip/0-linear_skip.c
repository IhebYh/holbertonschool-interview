#include "search.h"

/**
 * getLen - Get the Length of skiplist
 * @head : skip list
 * Return: size_t
 */
size_t getLen(skiplist_t *head)
{
	size_t i = 0;

	while (head)
	{
		head = head->next
		i++;
	}
	return (i);
}

/**
  * printCheck - printing checked value message to make the
  * code look clean
  * @index: index
  * @value: value
  */
void printCheck(size_t index, int value)
{
	printf("Value checked at index [%d] = [%d]\n", index, value);
}

/**
  * printFound - printing found value message to make the
  * code look clean
  * @index: index
  * @value: value
  */
void printFound(size_t index, int value)
{
	printf("Found %d at index: %d\n", value, index);
}

/**
  * printCompare - printing compared value message to make the
  * code look clean
  * @i: index
  * @p: previous index
  */
void printCompare(size_t i, size_t p)
{
	printf("Value found between indexes [%d] and [%d]\n", p, i);
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
	skiptlist_t prev = head;
	size_t index = 0, prev_index = 0, len = 0;

	len = getLen(head);
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->value == value)
		{
			printFound(index, value);
			return (head);
		}
		if (head->value < value)
		{
			printCheck(index, value);
			prev_index = index;
			index += sqrt(len);
		}
		if (head->value > value)
		{
			printCompare(index, prev_index);
			index = prev_index;
			head = prev;
			while (head)
			{
				if (head->value == value)
				{
					printFound(index, value);
					return (head);
				}
				if (head->value < value)
					printCheck(index, value);
				head = head->next;
				index++;
			}
			return (NULL);
		}
	}
	return (NULL);
}
