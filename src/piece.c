#include <string.h>
#include "../include/piece.h"

void initPiece(struct Piece *piece, const char *name, const char *playerName)
{
	strcpy(piece -> name, name);
	strcpy(piece -> playerName, playerName);
}
