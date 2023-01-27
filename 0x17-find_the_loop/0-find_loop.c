#include "lists.h"

/**
 * find_listint_loop - uses floyd's algo to find loop
 * @head: pointer to head node of list
 * Return: pointer to node where loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_p = head, *fast_p = head;

	if (!head)
		return (NULL);
	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
		{
			return (slow_p);
		}
	}
	return (NULL);
}
