#include <stdio.h>
#include <stdlib.h>
#include "graphics.c"

int main(){
    int columns = 7;
    int rows = 6;
    printf("hello");
    short **map = malloc(sizeof(short) * rows);
    for(int i = 0; i <rows; i++){
        map[i] = malloc(sizeof(short) * columns);
    }


    return -1;
}