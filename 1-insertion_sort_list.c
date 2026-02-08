#include "sort.h"

/**
 * swap_with_prev - swaps a node with its previous node
 * @list: pointer to the head of the list
 * @node: node to swap with its previous
 */
static void swap_with_prev(listint_t **list, listint_t *node)
{
	listint_t *prev;

	prev = node->prev;
	prev->next = node->next;
	if (node->next)
		node->next->prev = prev;
	node->prev = prev->prev;
	node->next = prev;
	prev->prev = node;

	if (node->prev)
		node->prev->next = node;
	else
		*list = node;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort
 * @list: pointer to pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;

	while (curr)
	{
		next = curr->next;

		while (curr->prev && curr->n < curr->prev->n)
		{
			swap_with_prev(list, curr);
			print_list(*list);
		}
		curr = next;
	}
}
