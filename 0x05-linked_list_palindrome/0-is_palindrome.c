#include "lists.h"

/**
 * is_palindrome - determines if linked list is a palindrome
 * @head: address of pointer to head node
 * Return: 1 if palindrome else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *copy = *head;

	return (pali_checker(*head, &copy));
}

/**
 * pali_checker - recursively checks if linked list is palindrome
 * @node: the current 2nd-half node to compare
 * @head: address of respective 1st-half node to compare
 * Return: 1 if matching else 0
 */
int pali_checker(listint_t *node, listint_t **head)
{
	return (!node || (pali_checker(node->next, head)
		&& (node->n == (*head)->n) ? (*head = (*head)->next), 1 : 0));
}
