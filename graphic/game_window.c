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
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        flamingo_talking_two(window);
        sfRenderWindow_display(window);
        malloc_fonction();
    }
    sfRenderWindow_destroy(window);
    return 0;
}