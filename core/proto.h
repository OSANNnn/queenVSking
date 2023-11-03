#ifndef PROTO_H
#define PROTO_H

#define ROWS 8
#define COLUMNS 8


//conversion from char to int
int convertCharXintoInt(char positionX);

//validation of the coordinates (must be inside 1 and COLUMNS for both)
int validatePosition(int positionX, int positionY);

//compare the position of queen and king to check if the king is in 'check' or not
int comparePosition(int kingX, int kingY, int queenX, int queenY);

//load the empty checkboard
char loadBoard(int x, int y, int riga, int colonna, int contaX, int contaY);

//load colonna
int loadColonna(int x, int y, int colonna);

//load riga
int loadRiga(int x, int y, int riga);

//load piece into board
char loadPiece(int index, char piece);


#endif
