#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gamerules.c"
#include "graphics.c"
#include "structure.c"
#include "playerInput.c"

int winVerification (Map *map, int columns, int rows) {
    int count=0;
    int count2=0;
    for (int i = 0; i <rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            count=0;
            if (map->grid[i][j]!=0){
            while (map->grid[i][j]==map->grid[i+count][j+count]){
                count++;
                if (count==map->rule)
                    return 1;
            }
            while (map->grid[i][j]==map->grid[i+count][j]){
                count++;
                if (count==map->rule)
                    return 1;
            }
            while (map->grid[i][j]==map->grid[i][j+count]){
                count++;
                if (count==map->rule)
                    return 1;
            }
            while (map->grid[i][j]==map->grid[i+count][j-count]){
                count++;
                if (count==map->rule)
                    return 1;
            }
            }
            if (map->grid[0][j]==1){
                count2++;
            }
        }
    }
    if (count2==columns){
        return -1;
    }
    return 0;
}


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

    int isFinish = 0;
    while(!isFinish){
        grid(map->rows, map->columns, map->grid, cursor);
        cursor = moveCursor(cursor, map->columns, map->rows, map);
        //isFinish = winVerification(map, map->columns, map->rows);
    }
    if(isFinish == 1){
        printf("victoire !");
    } else{
        printf("égalité !");
    }

    return 0;
}