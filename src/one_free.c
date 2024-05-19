/*
** EPITECH PROJECT, 2024
** crame_ton_pc
** File description:
** one_free.c
*/

#include "my.h"

void free_first(node_t **list)
{
    node_t *tmp = *list;

    if (!*list) {
        return;
    }
    *list = tmp->next;
    free(tmp);
}

void my_free(node_t **list, int n)
{
    int i = 0;

    if (!*list)
        return;
    while (i != n) {
        free_first(list);
        i++;
    }
}
