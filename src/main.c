#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "../include/piece.h"
#include "../include/player.h"
#include "../include/board.h"

struct Piece board[8][8];
struct Player player1, player2;

bool gameEnded = false;
bool isPlayerOneTurn = true;

void makeMove(char *pieceToMoveCoordinate, char *destinationCoordinate);

int main()
{
	char playerName[100];

	system("cls");

	printf("\n");
	printf("Insert player 1 name: ");
	scanf("%s", &playerName);
	initPlayer(&player1, playerName);

	printf("Insert player 2 name: ");
	scanf("%s", &playerName);
	initPlayer(&player2, playerName);

	system("cls");
	printf("\n");

	initiateEmptyBoard(&board);
	populateBoard(&board, &player1, &player2);
	renderBoard(&board, &player1, &player2);

	while (!gameEnded)
	{
		char pieceToMoveCoordinate[3];
		char destinationCoordinate[3];

		char playersTurnName [100];
		strcpy(playersTurnName, isPlayerOneTurn ? player1.name : player2.name);

		printf("\n\n");

		printf("%s, chose the piece you want to move: ", playersTurnName);
		scanf("%2s", pieceToMoveCoordinate);
		printf("%s, now chose the destination's coordinate: ", playersTurnName);
		scanf("%2s", destinationCoordinate);

		makeMove(pieceToMoveCoordinate, destinationCoordinate);
		system("cls");
		printf("\n");
		renderBoard(&board, &player1, &player2);
		
		isPlayerOneTurn = !isPlayerOneTurn;
	}

	return 0;
}

void makeMove(char *pieceToMoveCoordinate, char *destinationCoordinate)
{
	int sourceRow = extractRow(pieceToMoveCoordinate);
	int sourceColumn = extractColumn(pieceToMoveCoordinate);

	int destinationRow = extractRow(destinationCoordinate);
	int destinationColumn = extractColumn(destinationCoordinate);

	struct Piece temp = board[destinationRow][destinationColumn];
	board[destinationRow][destinationColumn] = board[sourceRow][sourceColumn];

	if (strcmp(temp.playerName, "No Player") != 0)
	{
		if (isPlayerOneTurn && strcmp(temp.playerName, player2.name) == 0)
		{
			player1.capturedPieces[player1.capturedPiecesCount++] = temp;
		}
		else if (!isPlayerOneTurn && strcmp(temp.playerName, player1.name) == 0)
		{
			player2.capturedPieces[player2.capturedPiecesCount++] = temp;
		}
	}

	strcpy(board[sourceRow][sourceColumn].playerName, "No Player");

	if ((sourceRow % 2 == 0 && sourceColumn % 2 == 0) || 
		 sourceRow % 2 != 0 && sourceColumn % 2 != 0)
	{
		strcpy(board[sourceRow][sourceColumn].name, "|");
	}
	else
	{
		strcpy(board[sourceRow][sourceColumn].name, " ");
	}
}