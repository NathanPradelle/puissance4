#include <stdio.h>

void grid(int rows, int columns, short **map, int cursor){
    for(int i = 0; i < 16 ; i++){
        printf("\n");
    }
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
                    }
                    printf("|\n");
                }
    for(int i = 0; i < columns; i++){
        printf("----");
    }
    printf("\n");
    for(int i = 0; i < cursor; i++){
        printf("    ");
    }
    printf("\033[0;35m <o>");
    printf("\033[0;37m");
}
