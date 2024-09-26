#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphics.c"
#include "structure.c"
#include "playerInput.c"


int main(){
    int cursor = 0;
    char *firstUserName = malloc(sizeof(char) * 20);
    char *secondUserName = malloc(sizeof(char) * 20);

    Map *map = InitializeMap(4, 6, 7); 
    
    printf("Nom du User1 : ");
    scanf("%s", firstUserName);
    printf("\nNom du User2 : ");
    scanf("%s", secondUserName);
    
    User *firstUser = createUser(firstUserName, 0, 0, 'x');
    User *secondUser = createUser(secondUserName, 1, 1, '0');
    
    while(1){
        grid(map->rows, map->columns, map->grid, cursor);
        cursor = moveCursor(cursor, map->columns);
    }

    return 0;
}