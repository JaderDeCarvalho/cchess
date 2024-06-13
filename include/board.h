#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "player.h"

void initiateEmptyBoard(struct Piece (*board)[8][8]);

void populateBoard(struct Piece (*board)[8][8], struct Player *player1, struct Player *player2);

void renderBoard(struct Piece (*board)[8][8], struct Player *player1, struct Player *player2);

int extractRow(char *coordinate);

int extractColumn(char *coordinate);

#endif // BOARD_H