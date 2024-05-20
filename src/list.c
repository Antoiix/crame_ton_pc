/*
** EPITECH PROJECT, 2024
** crame_ton_pc
** File description:
** list.c
*/

#include "my.h"

node_t *init_node_program(long long size)
{
    node_t *tmp = malloc(sizeof(node_t));

    tmp->val = malloc(sizeof(char) * (size + 1));
    tmp->next = NULL;
    if (!tmp->val) {
        return NULL;
    }
    return tmp;
}

int add_node_program(node_t **list, long long size)
{
    node_t *tmp = init_node_program(size);
    node_t *head;

    if (!tmp)
        return 84;
    if (!*list) {
        *list = tmp;
        return 0;
    }
    tmp->next = *list;
    *list = tmp;
    return 0;
}

