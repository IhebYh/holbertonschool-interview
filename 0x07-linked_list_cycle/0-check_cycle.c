#include "lists.h"

/**
 * check_cycle - check if there's a cycle in a linked list
 * @list: linked list
 * Return: int
 */
int check_cycle(listint_t *list)
{
	listint_t *tmp;

	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (tmp->next == list->next)
				return (1);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (0);
}
