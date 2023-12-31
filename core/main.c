//reginaVSre.c da eserciziario (3.15)
#include <stdio.h>
#include <ctype.h>
#include "proto.h"


int main()
{
    char charWhiteKingX;
    int  whiteKingX;
    int  whiteKingY;
    
    char charBlackQueenX;
    int  blackQueenX;
    int  blackQueenY;
    
    int kingIsValid;
    int queenIsValid;

    int r, c, j, i, contaXpieno, contaYpieno; //variabili contatore (righe, colonne, x, y)

    char board[42][26];

    c=0; //colonne all'interno della scacchiera interna
    r=8; //righe della scacchiera interna
    contaXpieno = 0;
    contaYpieno = 0;

    printf("\033[H\033[J");
    for (i = 0; i <= 25; i++)
    {
        for (j = 0; j <= 41; j++)
        {
            board[j][i] = loadBoard(j, i, r, c, contaXpieno, contaYpieno);
            c = loadColonna(j, i, c);
            //printf("%c", board[j][i]); //debug
            r = loadRiga(j, i, r);
            if ((i !=0 && j != 0) && (i!=25 && j!=41))
            {
                if (contaXpieno == 9)
                {
                    contaXpieno=0;
                }
                else
                {
                    contaXpieno++;
                }
            }
        }
        //printf("\n");
        if ((i!=0 && j!=0) && (i!=25 && j!=41))
        {
            if (contaYpieno == 5) 
            {
                contaYpieno=0;
            }
            else
            {
                contaYpieno++;
            }
        }
    }

    do
    {
        printf("Insert coordinates for the white King (eg. a5): ");
        scanf(" %c%d", &charWhiteKingX, &whiteKingY);
        while(getchar()!='\n');
        charWhiteKingX = tolower(charWhiteKingX);
        whiteKingX = convertCharXintoInt(charWhiteKingX);
        //printf("%d", charWhiteKingX);  //DEBUG
        kingIsValid = validatePosition(whiteKingX, whiteKingY);
    }
    while (!kingIsValid);
    
    do
    {
        do
        {
            printf("Insert coordinates for the black Queen (eg. f6): ");
            scanf(" %c%d", &charBlackQueenX, &blackQueenY);
            while(getchar()!='\n');
            charBlackQueenX = tolower(charBlackQueenX);
            blackQueenX = convertCharXintoInt(charBlackQueenX);
            queenIsValid = validatePosition(blackQueenX, blackQueenY);
        }
        while (!queenIsValid);
        
        if (whiteKingX == blackQueenX && whiteKingY == blackQueenY)
        {
            printf("\n");
            printf("The Queen can't be in the same spot as the king.\n\n");
        }
    }
    while (whiteKingX == blackQueenX && whiteKingY == blackQueenY);


    printf("\033[H\033[J");
    for (int s = 0; s < 3; s++)
    {
        board[whiteKingX*5-3+s][26-(whiteKingY*3)]=loadPiece(s, 'K');
        board[blackQueenX*5-3+s][26-(blackQueenY*3)]=loadPiece(s, 'Q');
    }
    j=0;
    i=0;
    for (i = 0; i <= 25; i++)
    {
        for (j = 0; j <= 41; j++)
        {
            printf("%c", board[j][i]);
        }
        printf ("\n");
    }

    comparePosition(whiteKingX, whiteKingY, blackQueenX, blackQueenY);

    return 0;
}