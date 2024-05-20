/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Shell Boostrap
** File description:
** bootstrap.h
*/

#ifndef B_MUL_100_LIL_1_1_MYRADAR_MARTIN_DELANGUE_MY_H
    #define B_MUL_100_LIL_1_1_MYRADAR_MARTIN_DELANGUE_MY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Sleep.h>
    #include <time.h>
    #include <fcntl.h>
    #include <math.h>
    #include <SFML/Audio.h>
    #include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <SFML/Graphics.h>
#include <SFML/System/Sleep.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>
#include <SFML/Audio.h>


#define MAX 20

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent);
    sfTexture *texture;
    int is_actif;
    int view;
} button_s;

typedef struct creator_t {
    button_s *button[MAX];
    int count;
} creator_t;

int gamee(sfRenderWindow *window);

void create_flamingo(sfRenderWindow *window, sfClock *clock, sfTexture *texture);
void create_flamingo_crying(sfRenderWindow *window, sfClock *clock, sfTexture *texture);
void flamingo_talking(sfRenderWindow *window);

int create_all_buttons(creator_t *button_creator);
creator_t *init_button(void);
void draw_button(creator_t *button_creator, sfRenderWindow *window);

int game_window(void);
void flamingo_talking_two(sfRenderWindow *window);

#endif //B_MUL_100_LIL_1_1_MYRADAR_MARTIN_DELANGUE_MY_H
