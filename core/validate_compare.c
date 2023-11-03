#include "proto.h"
#include <stdio.h>
#include <stdlib.h> //for the abs() function


int validatePosition(int positionX, int positionY){
    
    if (positionX == 0 || (positionY < 1 || positionY >8)){ //checking if not out-of-bounds (1=validposition)
        
        printf("Coordinates are not valid. X must be from 'a' to 'h' and Y from '1' to '8'\n");
        
        return 0;
    }
    else{
    
        return 1;
    }    
}


int comparePosition(int kingX, int kingY, int queenX, int queenY){
    
    if (abs(kingX - queenX) == abs(kingY - queenY)){ //if the absolute value of deltaY == deltaY (we need m = 1 or -1, and m=deltaY/deltaX)
        
        printf("\n");
        printf("KING IS IN CHECK!\n");
    }
    else{
        
        if (kingX == queenX || kingY == queenY){ //if queen and king are in the same row or column
            
            printf("\n");
            printf("KING IS IN CHECK!\n");
        }
        else{
        
            printf("\n");
            printf("KING IS SAFE!\n");
        }
    }
}

