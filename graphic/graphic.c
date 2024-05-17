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
    sfVideoMode videoMode = {1920, 1080, 32};
    window = sfRenderWindow_create(videoMode, "ça crame ?", sfResize | sfClose, NULL);
    sfTexture* texture = sfTexture_createFromFile("graphic/img/fond.jpg", NULL);
    if (!texture)
        return -1;
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return 0;
}
