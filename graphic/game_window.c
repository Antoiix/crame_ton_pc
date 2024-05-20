/*
** EPITECH PROJECT, 2024
** crame_ton_pc
** File description:
** game_window.c
*/

#include "include/graphic.h"


int game_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "GAME crame ton pc", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    sfEvent event;
    node_t *list = NULL;
    struct sysinfo memInfo;
    sfTime time;
    sfClock *clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        while (1) {
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(window);
            }
            sfRenderWindow_clear(window, sfBlack);
            flamingo_talking_two(window);
            sfRenderWindow_display(window);
            malloc_fonction();
            time = sfClock_getElapsedTime(clock);
            if (time.microseconds > 1.0) {
                if(sysinfo(&memInfo) != 0) {
                    perror("Error getting memory info");
                    return 84;
                }
                if ((float)((float)((memInfo.totalram - memInfo.freeram) / (1024 * 1024)) / (float)(memInfo.totalram / (1024 * 1024))) * 100 > 99.0)
                    return 0;
                my_free(&list, 2000);
                if (one_malloc(&list) == 84) {
                    return 84;
                }
                sfClock_restart(clock);
            }
        }
    }
    sfRenderWindow_destroy(window);
    return 0;
}