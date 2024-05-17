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

void create_flamingo(sfRenderWindow *window, sfClock *clock, sfTexture *texture);
void create_flamingo_crying(sfRenderWindow *window, sfClock *clock, sfTexture *texture);
void flamingo_talking(sfRenderWindow *window);

#endif //B_MUL_100_LIL_1_1_MYRADAR_MARTIN_DELANGUE_MY_H
