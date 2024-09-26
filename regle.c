#include <stdio.h>
#include <stdlib.h>
int win2 (int **map, int taille, int columns, int rows) {
    int count=0;
    int count2=0;
    for (int i = 0; i <rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            count=0;
            while (map[i][j]==map[i+count][j+count]){
                count++;
                if (count==taille)
                    return map[i][j];
            }
            while (map[i][j]==map[i+count][j]){
                count++;
                if (count==taille)
                    return map[i][j];
            }
            while (map[i][j]==map[i][j+count]){
                count++;
                if (count==taille)
                    return map[i][j];
            }
            while (map[i][j]==map[i+count][j-count]){
                count++;
                if (count==taille)
                    return map[i][j];
            }
            if (map[0][j]==1){
                count2++;
            }
        }
    }
    if (count2==columns){
        return -1;
    }
}

int win (int **map, int taille, int columns, int rows){
    int count=0;
    for (int i = 0; i <rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (map[i][j]==map[i][j+1]==map[i][j+2]==map[i][j+3]){
                return map[i][j];
            }
            if (map[i][j]==map[i+1][j]==map[i+2][j]==map[i+3][j]){
                return map[i][j];
            }
            if (map[i][j]==map[i+1][j-1]==map[i+2][j-2]==map[i+3][j-3]){
                return map[i][j];
            }
            if (map[0][j]==1){
                count++;
            }
        }
    }
    if (count==columns){
        return -1;
    }
    return 0;
}

int **tour(int **map,int play,int joueurId, int longueur ){
    int i=0;
    while (map[play][i]==0||i!=(longueur+1)){
        i++;
    }
    map[play][i-1]=joueurId;
    return map;
}

int main(){
    int columns = 6;
    int joueurId=1;
    int rows = 7;
    int taille=4;
    int res;
    int play=1;
    int **map = malloc(sizeof(int) * rows);
    for(int i = 0; i <rows; i++){
        map[i] = malloc(sizeof(int) * columns);
    }
    res=win(map,taille,columns,rows);

    map=tour(map,play,joueurId,rows);
    free(map);
    return -1;
}