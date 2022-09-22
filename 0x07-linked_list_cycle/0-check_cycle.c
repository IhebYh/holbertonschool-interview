#include "lists.h"

/**
 * check_cycle - check if there's a cycle in a linked list
 * @list: linked list
 * Return: int
 */
int check_cycle(listint_t *list)
{
	listint_t *tmp, *tmp2;

	tmp = list->next;
	tmp2 = list->next->next;
	while (tmp && tmp2)
	{
		if (tmp == tmp2)
			return (1);
		tmp = tmp->next;
		tmp2 = tmp2->next->next;
	}
	return (0);
}
