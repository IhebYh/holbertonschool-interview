#include "lists.h"

/**
 * check_cycle - check if there's a cycle in a linked list
 * @list: linked list
 * Return: int
 */
int check_cycle(listint_t *list)
{
	listint_t *tmp, *tmp2;

	tmp = tmp2 = list;
	while (tmp && tmp->next)
	{
		tmp = tmp->next->next;
		tmp2 = tmp2->next;
		if (tmp == tmp2)
			return (1);
	}
	return (0);
}
