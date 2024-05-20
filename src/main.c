/*
** EPITECH PROJECT, 2024
** navy
** File description:
** main.c
*/

#include "my.h"

int malloc_fonction(void)
{
    node_t *list = NULL;
    struct sysinfo memInfo;
    sfTime time;
    sfClock *clock = sfClock_create();

    while (1) {
            if(sysinfo(&memInfo) != 0) {
                perror("Error getting memory info");
                return 84;
            }
            if ((float)((float)((memInfo.totalram - memInfo.freeram) / (1024 * 1024)) / (float)(memInfo.totalram / (1024 * 1024))) * 100 > 99.0)
                return 0;
            //my_free(&list, 20000);
            if (one_malloc(&list) == 84) {
                return 84;
            }
    }
    return 0;
}
