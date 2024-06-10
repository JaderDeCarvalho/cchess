#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "player.h"

void renderBoard(struct Piece (*board)[8][8], struct Player *player1, struct Player *player2);

#endif // BOARD_H