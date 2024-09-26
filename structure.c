#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    short order;
    short color;
    char pawn;

} User;

typedef struct {
    int rows;
    int columns;
    int rule;
    short **grid;
} Map;

User *createUser(char *name, short order, short color, char pawn){

    User *user = malloc(sizeof(User));

    char *Username = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(Username, name);

    user->name = Username;
    user->order = order;
    user->color = color;
    user->pawn = pawn;
    
    return user;
}

Map *InitializeMap(int rule, int rows, int columns){

    Map *map = malloc(sizeof(Map));

    map->rows = rows;
    map->columns = columns;
    map->rule = rule;

    short **grid = (short **) malloc(sizeof(short*) * rows);
    
        for(int i = 0; i < rows; i++){
            grid[i] = (short *) calloc(columns, sizeof(short));
        }
    
    map->grid = grid;

    return map;
}
