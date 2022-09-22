#include "lists.h"

int check_cycle(listint_t *list)
{
	listint_t *tmp;

	while (list && list->next != list)
	{
		tmp = list->next;
		while (tmp){
			if (tmp->next == list->next)
				return (1);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (0);
}