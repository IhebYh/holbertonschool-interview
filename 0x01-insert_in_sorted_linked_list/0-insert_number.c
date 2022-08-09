#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head : head of the linked list
 * @number : number to insert
 * Return: listint_t* or null
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *node = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;
	if ((*head == NULL) || (*head)->n >= new->n)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		node = *head;
		while (node->next != NULL && number >= node->next->n)
		{
			node = node->next;
		}
		new->next = node->next;
		node->next = new;
	}
	return (new);
}
