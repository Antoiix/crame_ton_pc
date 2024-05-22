/*
** EPITECH PROJECT, 2024
** crame_ton_pc
** File description:
** test.c
*/

#include "my.h"

int main(void)
{
    struct sysinfo memInfo;

    while (1) {
        if(sysinfo(&memInfo) != 0) {
            perror("Error getting memory info");
            return 84;
        }
        printf("%f %f\n", (float)((memInfo.totalram - memInfo.freeram) / (1024 * 1024)), (float)(memInfo.totalram / (1024 * 1024)));
//        printf("%f\n", (memInfo.totalram - memInfo.freeram) / (1024 * 1024) / (float)(memInfo.totalram / (1024 * 1024)) * 100);
    }
}
