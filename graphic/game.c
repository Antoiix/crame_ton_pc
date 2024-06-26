/*
** EPITECH PROJECT, 2024
** crame_ton_pc
** File description:
** game.c
*/


#include "include/graphic.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

const int FRAME_WIDTH = 32;
const int FRAME_HEIGHT = 32;
const int TOTAL_FRAMES = 3;
const float TIME_PER_FRAME = 0.2f;

size_t addRandomSquare(sfRectangleShape **squares, size_t count)
{
    sfRectangleShape* square = sfRectangleShape_create();
    sfVector2f size = {50, 50};
    sfRectangleShape_setSize(square, size);

    sfTexture *texture = sfTexture_createFromFile("graphic/flamingo/flamingo_standing.png", NULL);
    sfRectangleShape_setTexture(square, texture, sfTrue);

    sfColor color;
    switch (count % 3) {
        case 0:
            color = sfColor_fromRGB(255, 0, 0);
            break;
        case 1:
            color = sfColor_fromRGB(255, 128, 0);
            break;
        case 2:
            color = sfColor_fromRGB(253, 253, 150);
            break;
        default:
            color = sfColor_fromRGB(255, 255, 255);
            break;
    }
    sfRectangleShape_setFillColor(square, color);

    sfVector2f position = {rand() % (1850 - (int)size.x), rand() % (970 - (int)size.y)};
    sfRectangleShape_setPosition(square, position);

    squares[count] = square;
    count++;
    return count;
}

int isPointInsideRectangle(sfVector2f point, sfRectangleShape *rectangle)
{
    sfVector2f position = sfRectangleShape_getPosition(rectangle);
    sfVector2f size = sfRectangleShape_getSize(rectangle);

    return (point.x >= position.x && point.x <= position.x + size.x &&
            point.y >= position.y && point.y <= position.y + size.y);
}

void display_win_message(sfRenderWindow *window) {
    sfFont *font = sfFont_createFromFile("graphic/flamingo/fire.ttf");
    if (!font) {
        return;
    }
    sfText *text = sfText_create();
    sfText_setString(text, "You WIN !");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setColor(text, sfWhite);

    sfFloatRect textRect = sfText_getLocalBounds(text);
    sfVector2u windowSize = sfRenderWindow_getSize(window);
    sfText_setPosition(text, (sfVector2f){(windowSize.x - textRect.width) / 2, (windowSize.y - textRect.height) / 2});

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    sfSleep(sfSeconds(2));

    sfText_destroy(text);
    sfFont_destroy(font);
}

void animateSquares(sfRectangleShape **squares, size_t count, sfClock *animationClock)
{
    sfTime time = sfClock_getElapsedTime(animationClock);
    float seconds = sfTime_asSeconds(time);
    int current_frame = (int)(seconds / TIME_PER_FRAME) % TOTAL_FRAMES;
    sfIntRect frame_rect = {current_frame * FRAME_WIDTH, 0, FRAME_WIDTH, FRAME_HEIGHT};

    for (size_t i = 0; i < count; i++) {
        sfRectangleShape_setTextureRect(squares[i], frame_rect);
    }
}

int gamee(sfRenderWindow *window)
{
    node_t *list = NULL;
    struct sysinfo memInfo;

    srand(time(NULL));
    sfRectangleShape *squares[10000];
    size_t count = 0;
    int nb = 0;
    sfClock *clock = sfClock_create();
    sfClock *animationClock = sfClock_create();
    sfTime timeSinceLastSquare = sfClock_getElapsedTime(clock);

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
                sfVector2f mousePosition = { event.mouseButton.x, event.mouseButton.y };
                for (size_t i = 0; i < count; i++) {
                    if (isPointInsideRectangle(mousePosition, squares[i])) {
                        sfRectangleShape_destroy(squares[i]);
                        nb++;
                        printf("touché %d\n", nb);
                        my_free(&list, 200000);
                        squares[i] = squares[count - 1];
                        count--;
                        break;
                    }
                }
            }
        }
        if (sysinfo(&memInfo) != 0) {
            perror("Error getting memory info");
            clear_list(list);
            exit(84);
        }
        if ((float)((float)((memInfo.totalram - memInfo.freeram) / (1024 * 1024)) / (float)(memInfo.totalram / (1024 * 1024))) * 100 > 99.0) {
            clear_list(list);
            exit(0);
        }

        if (one_malloc(&list) == 84) {
            clear_list(list);
            exit(84);
        }

        if (sfTime_asSeconds(timeSinceLastSquare) >= 0.5) {
            count = addRandomSquare(squares, count);
            sfClock_restart(clock);
        }
        if (nb >= 53) {
            display_win_message(window);
            clear_list(list);
            exit(0);
        }

        animateSquares(squares, count, animationClock);
        timeSinceLastSquare = sfClock_getElapsedTime(clock);
        sfRenderWindow_clear(window, sfBlack);
        for (size_t i = 0; i < count; i++) {
            sfRenderWindow_drawRectangleShape(window, squares[i], NULL);
        }
        sfRenderWindow_display(window);
    }
    for (size_t i = 0; i < count; i++) {
        sfRectangleShape_destroy(squares[i]);
    }
    sfClock_destroy(clock);
    sfClock_destroy(animationClock);
    return 0;
}