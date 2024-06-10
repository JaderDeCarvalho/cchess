#ifndef PLAYER_H
#define PLAYER_H

#include "piece.h"

struct Player
{
	char name[100];
	struct Piece capturedPieces[16];
	int capturedPiecesCount;
};

void initPlayer(struct Player *player, const char *name);

#endif // PLAYER_H