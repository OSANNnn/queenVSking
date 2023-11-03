#include "proto.h"

char loadBoard(int x, int y, int riga, int colonna, int contaX, int contaY)
{    

    if ((x % 5) -3 == 0 && y == 0 && x != 0)
    {
        return 'a' + colonna;
    }

    if ((x % 5) -3 == 0 && y == 25 && x != 0)
    {
        return  'a' + colonna;
    }

    if ((y % 3) -2 == 0 && x == 0 && y != 0)
    {
        return '0'+riga;
    }

    if ((y % 3) -2 == 0 && x == 41 && y != 0)
    {
        return '0'+riga;
    }

    if ((!y || !x) || y == 25 || x == 41)
    {
        return ' ';
    }

    if (contaX < 5 ^ contaY < 3 )
    {
        return ':';
    }
    else
    {
        return ' ';
    }

}

int loadColonna(int x, int y, int colonna)
{
    if ((x % 5) -3 == 0 && y == 0 && x != 0)
    {
        return colonna+1;
    }

    if ((x % 5) -3 == 0 && y == 25)
    {
        return colonna+1;
    }

    if (y > 0 && y < 25)
    {
        return 0;
    }

    return colonna;
}

int loadRiga(int x, int y, int riga)
{
    if (y % 3 == 0 && x == 0 && y != 0)
    {
        return riga-1;
    } 

    return riga;

}

char loadPiece(int index, char piece)
{
    if (piece == 'K')
    {
        if (index == 0)
        {
            return 'W';
        }

        if (index == 1)
        {
            return 'H';
        }

        if (index == 2)
        {
            return 'K';
        }
    }
    
    if (piece == 'Q')
    {
        if (index == 0)
        {
            return 'B';
        }

        if (index == 1)
        {
            return 'L';
        }

        if (index == 2)
        {
            return 'Q';
        }
    }
}
