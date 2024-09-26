#include <stdlib.h>
#include <stdio.h>

void falling(Map *map,int cursor,int joueurId, int rows ){
    int i=0;
    while (i != rows -1  && map->grid[i+1][cursor] == 0){
        i++;
    }
    map->grid[i][cursor]=joueurId;
}

void createPawn(Map *map, int cursor, int rows){
    falling(map, cursor, 1, rows);
    
}

int moveCursor(int cursor, int columns, int rows, Map *map){
    char key;
    scanf("%c", &key);
    switch (key)
    {
    case 'q':
        if(cursor>=0){
            cursor -= 1;
        }
        break;
    case 'd':
        if(cursor<columns-1){
            cursor += 1;
        }
        break;
    case ' ':
        createPawn(map, cursor, rows);
        break;
    default:
        break;
    }
    return cursor;
}

