#include "proto.h"
#include <stdio.h>

int convertCharXintoInt(char piece){
    
    int value = piece - 'a' + 1; //ascii decimal value - value of the first ascii used, (if a - a then = 0 etc.) +1 since we start our board coordinates at 1
    
    if (value < 0 || value > COLUMNS){ //if it's out of the range of the board gives 0 as an invalid value
        
        return 0;
    }
    
    return value;
    
    /*                       //unoptimal system
    if (piece == 'a'){
    
        value = 1;
        
    }else
        
        if (piece == 'b'){
            
            value = 2;
            
        }else
            
            if (piece == 'c'){
            
                value = 3;
            
            }else
                
                if (piece == 'd'){
            
                    value = 4;
            
                }else
                    
                    if (piece == 'e'){
            
                        value = 5;
                    
                    }else
                        
                        if (piece == 'f'){
            
                            value = 6;
            
                        }else
                            
                            if (piece == 'g'){
            
                                value = 7;
            
                            }else
                            
                                if (piece == 'h'){
                                    
                                    value = 8;
                                    
                                }
    return value; old and unoptimal conversion*/  //unoptimal
}