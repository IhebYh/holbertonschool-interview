#include "lists.h"

int check_cycle(listint_t *list)
{
	listint_t *tmp, *tmp2;

	tmp = list;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2){
			if (tmp2->next == tmp->next)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}