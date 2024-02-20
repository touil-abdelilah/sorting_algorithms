#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *prev_node;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    curr = (*list)->next;
    while (curr != NULL)
    {
        prev_node = curr->prev;
        while (prev_node != NULL && prev_node->n > curr->n)
        {
            if (prev_node->prev != NULL)
                prev_node->prev->next = curr;
            if (curr->next != NULL)
                curr->next->prev = prev_node;
            prev_node->next = curr->next;
            curr->prev = prev_node->prev;
            prev_node->prev = curr;
            curr->next = prev_node;
            if (curr->prev == NULL)
                *list = curr;
            print_list(*list);
            prev_node = curr->prev;
        }
        curr = curr->next;
    }
}

