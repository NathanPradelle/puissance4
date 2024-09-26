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

    int userCount = 0;
    int cursor = 0;
    printf("Nombre de joueur: ");
    scanf("%d", &userCount);

    char **userNames = malloc(sizeof(char*) * userCount);

    if (userCount <= 1 || userCount >= 5){
        printf("il faut entre 2 et 4 joueurs");
        return 0;
    }

    User **userArray = (User**) malloc(sizeof(User*) * userCount);

    for (int i = 0; i<userCount; i++){

        userArray[i] = (User*) malloc(sizeof(User));

        char *carac = (char*) malloc(sizeof(char) * 4);
        char *color = (char*) malloc(sizeof(char) * 6);
        userNames[i] = (char*) malloc(sizeof(char) * 21);

        printf("Nom du User%d :\n", i+1);
        scanf("%s", userNames[i]);

        printf("Forme de vos pièce (un caractere):\n");
        scanf("%s", carac);

        printf("couleur ('rouge', 'vert', 'bleu', 'jaune') :\n", i);
        scanf("%s", color);
        if (strcmp("rouge", color) == 0){
            color = "\033[0;31m";
        }else if (strcmp("vert", color) == 0){
            color = "\033[0;32m";
        }else if (strcmp("bleu", color) == 0){
            color = "\033[0;34m";
        }else if (strcmp("jaune", color) == 0){
            color = "\033[0;33m";
        }else{
            printf("Couleur non valide");
            return -1;
        }

        if (!(strlen(userNames[i]) > 20)){
        userArray[i] = createUser(userNames[i], i, color, carac);
        }else{
            printf("Votre nom est trop long");
            return -1;
        }
    }

    Map *map = InitializeMap(4, 6, 7); 
    


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