/*
** EPITECH PROJECT, 2024
** crame_ton_pc
** File description:
** graphic.c
*/

#include "include/graphic.h"
#include <SFML/Graphics.h>

int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Flamingo Display", sfResize | sfClose, NULL);
    if (!window)
        return 1;
    sfTexture *flamingo_texture = sfTexture_createFromFile("flamingo/flamingo_standing.png", NULL);
    sfTexture *flamingo_crying = sfTexture_createFromFile("flamingo/flamingo_death.png", NULL);
    if (!flamingo_texture)
        return 1;
    sfClock *clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        create_flamingo(window, clock, flamingo_texture);
        create_flamingo_crying(window, clock, flamingo_crying);
        flamingo_talking(window);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(flamingo_texture);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    return 0;
}
