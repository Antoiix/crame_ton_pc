/*
** EPITECH PROJECT, 2024
** crame_ton_pc
** File description:
** graphic.c
*/

#include "include/graphic.h"
#include <SFML/Graphics.h>

void handle_event(sfEvent *event, creator_t *button_creator, sfRenderWindow *window, int *game)
{
    if (event->type == sfEvtMouseButtonPressed) {
        for (int i = 0; i < button_creator->count; i++) {
            if (button_creator->button[i]->is_clicked(button_creator->button[i], event->mouseButton))
                *game = 1;
        }
    }
    if (event->type == sfEvtMouseMoved) {
        for (int i = 0; i < button_creator->count; i++) {
            if (button_creator->button[i]->is_hover(button_creator->button[i], event->mouseMove))
                sfRectangleShape_setFillColor(button_creator->button[i]->rect, sfRed);
            else
                sfRectangleShape_setFillColor(button_creator->button[i]->rect, sfWhite);
        }
    }
    sfFloatRect visibleArea =
            {0.f, 0.f, (float)event->size.width, (float)event->size.height};
    if (event->type == sfEvtResized)
        sfRenderWindow_setView(window, sfView_createFromRect(visibleArea));
}

int main()
{
    creator_t *button_creator = init_button();
    int game = 0;

    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Flamingo Display", sfResize | sfClose, NULL);
    if (!window)
        return 1;
    sfTexture *flamingo_texture = sfTexture_createFromFile("flamingo/flamingo_standing.png", NULL);
    sfTexture *flamingo_crying = sfTexture_createFromFile("flamingo/flamingo_death.png", NULL);
    if (!flamingo_texture)
        return 1;
    sfClock *clock = sfClock_create();
    create_all_buttons(button_creator);
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            handle_event(&event, button_creator, window, &game);
        }
        sfRenderWindow_clear(window, sfBlack);
        create_flamingo(window, clock, flamingo_texture);
        create_flamingo_crying(window, clock, flamingo_crying);
        flamingo_talking(window);
        draw_button(button_creator, window);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(flamingo_texture);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    return 0;
}
