/*
** EPITECH PROJECT, 2024
** crame_ton_pc
** File description:
** flamingo_on_screen.c
*/

#include "include/graphic.h"

void create_flamingo(sfRenderWindow *window, sfClock *clock, sfTexture *texture)
{
    const int frame_width = 32;
    const int frame_height = 32;
    const int total_frames = 3;
    const float time_per_frame = 0.2f;
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);
    int current_frame = (int)(seconds / time_per_frame) % total_frames;
    sfIntRect frame_rect = {current_frame * frame_width, 0, frame_width, frame_height};
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, frame_rect);
    sfSprite_setPosition(sprite, (sfVector2f){200, 250});
    sfSprite_setScale(sprite, (sfVector2f){5.5f, 5.5f});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void create_flamingo_crying(sfRenderWindow *window, sfClock *clock, sfTexture *texture)
{
    const int frame_width = 32;
    const int frame_height = 32;
    const int total_frames = 6;
    const float time_per_frame = 0.2f;
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);
    int current_frame = (int)(seconds / time_per_frame) % total_frames;
    sfIntRect frame_rect = {current_frame * frame_width, 0, frame_width, frame_height};
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, frame_rect);
    sfSprite_setPosition(sprite, (sfVector2f){400, 250});
    sfSprite_setScale(sprite, (sfVector2f){5.5f, 5.5f});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void flamingo_talking(sfRenderWindow *window)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("flamingo/fire.ttf");
    sfText_setString(text, "Buenos dias, Putas\nsi tu veux faire flamber ton pc...\nclique sur jouer !");
    sfText_setColor(text, sfWhite);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, (sfVector2f){200, 200});
    sfRenderWindow_drawText(window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);

}


