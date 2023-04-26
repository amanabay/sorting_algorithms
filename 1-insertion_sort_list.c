#include "sort.h"

/**
 * insertion_sort_list - sorts an array of integers in ascending orderusing
 * the insertion sort algorithm
 *
 * @list: list to be sorted
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux;
	int n;

	if (list == NULL)
		return;

	aux = *list;
	while (aux)
	{
		while (aux)
		{
			if (aux->next != NULL && aux->n > aux->next->n)
			{
				n = aux->n;
				*(int *)&aux->n = aux->next->n;
				*(int *)&aux->next->n = n;
				aux = *list;
				print_list(*list);
				break;
			}
			aux = aux->next;
		}
	}
}
