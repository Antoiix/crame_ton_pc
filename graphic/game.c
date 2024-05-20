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

size_t addRandomSquare(sfRectangleShape **squares, size_t count)
{
    sfRectangleShape* square = sfRectangleShape_create();
    sfVector2f size = {50, 50};
    sfRectangleShape_setSize(square, size);
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

int gamee(sfRenderWindow *window)
{
    srand(time(NULL));
    sfRectangleShape *squares[10000];
    size_t count = 0;
    int nb = 0;
    sfClock *clock = sfClock_create();
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
                        squares[i] = squares[count - 1];
                        count--;
                        break;
                    }
                }
            }
        }
        if (sfTime_asSeconds(timeSinceLastSquare) >= 0.5) {
            count = addRandomSquare(squares, count);
            sfClock_restart(clock);
        }
        if (nb >= 25) {
            display_win_message(window);
            break;
        }
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
    return 0;
}