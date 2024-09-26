#include <stdio.h>

void grid(int rows, int columns, short **map){
    for(int i = 0; i < rows ; i++){
            for(int j = 0; j < columns  ; j++){
                char c;    
                switch(map[i][j]){
                            case 0:
                                c = ' ';
                                break;
                            case 1:
                                c = 'X';
                                break;
                            case 2:
                                c = 'O';
                                break;  
                        }
                        printf("| %c ", c);
                        printf("%d ", map[i][j]);
                    }
                    printf("|\n");
                }
}
