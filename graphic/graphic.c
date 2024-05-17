/*
** EPITECH PROJECT, 2024
** crame_ton_pc
** File description:
** graphic.c
*/

#include <SFML/Graphics.h>

int main()
{
    sfRenderWindow* window;
    sfVideoMode videoMode = {800, 600, 32};
    window = sfRenderWindow_create(videoMode, "ça crame ?", sfResize | sfClose, NULL);

    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
