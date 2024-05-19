/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** contains all of prototypes
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/sysinfo.h>

typedef struct node_s {
    char *val;
    struct node_s *next;
} node_t;

int add_node_program(node_t **list, long long size);
int one_malloc(node_t **mem);
#endif
