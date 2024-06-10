#ifndef PIECE_H
#define PIECE_H

struct Piece
{
	char name[15];
	char playerName[100];
};

void initPiece(struct Piece *piece, const char *name, const char *playerName);

#endif // PIECE_H