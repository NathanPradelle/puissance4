#include <stdio.h>
#include <stdlib.h>
#include "graphics.c"

int main(){
    int columns = 7;
    int rows = 6;
    short **map = (short**) malloc(sizeof(short*) * rows);
    for(int i = 0; i <rows; i++){
        map[i] = (short*) calloc(columns, sizeof(short));
    }
    map[0][0] = 1;
    grid(rows, columns, map);


    return -1;
}