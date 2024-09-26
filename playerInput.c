#include <stdlib.h>
#include <stdio.h>

int moveCursor(int cursor, int columns){
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
    
    default:
        break;
    }
    return cursor;
}