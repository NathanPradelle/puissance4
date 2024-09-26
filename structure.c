#include <stdio.h>
#include <stdlib.h>

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
} Map;

User *createUser(char *name, short order, short color, char pawn){

    User *user = malloc(sizeof(User));

    char *Username = malloc(sizeof(char) * (strlen + 1));
    strcpy(Username, name);

    user->name = Username;
    user->order = order;
    user->color = color;
    user->pawn = pawn;
    
    return user;
}

Map *createMap(int rows, int columns, int rule){

    Map *map = malloc(sizeof(Map));

    map->columns = rows;
    map->columns = columns;
    map->columns = rule;
}
