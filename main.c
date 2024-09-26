#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphics.c"
#include "structure.c"


int main(){
    
    char *firstUserName = malloc(sizeof(char) * 20);
    char *secondUserName = malloc(sizeof(char) * 20);

    Map *map = InitializeMap(4, 6, 7); 
    
    for (int i = 0; i<6; i++){
        for (int j = 0; j<7; j++){
            printf("%d", map->grid[i][j]);
        }
        printf("\n");
    }
    
    printf("Nom du User1 : ");
    scanf("%s", firstUserName);
    printf("\nNom du User2 : ");
    scanf("%s", secondUserName);
    
    User *firstUser = createUser(firstUserName, 0, 0, 'x');
    User *secondUser = createUser(secondUserName, 1, 1, '0');
    
    return 0;
}