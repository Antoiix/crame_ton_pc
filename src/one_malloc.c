/*
** EPITECH PROJECT, 2024
** crame_ton_pc
** File description:
** one_malloc.c
*/

#include "my.h"

int one_malloc(node_t **list)
{
    long long size = 0;
    int i = 0;

    size = 50;
    if (add_node_program(list, size) == 84) {
        return 84;
    }
    //usleep(1);
//    for (node_t *tmp = *list; tmp; tmp = tmp->next) {
//        i++;
//    }
//    printf("%d\n", i);
    //printf("%lld\n", size);
    return 0;
}
