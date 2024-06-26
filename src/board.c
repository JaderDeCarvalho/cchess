#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/piece.h"
#include "../include/player.h"
#include "../include/board.h"

void initiateEmptyBoard(struct Piece (*board)[8][8])
{
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++)
		{
			struct Piece piece;

			char playerName[100];
			strcpy(playerName, "No Player");

			char name[15];
			
			if ((i % 2 == 0 && j % 2 == 0) || 
				 i % 2 != 0 && j % 2 != 0)
			{
				strcpy(name, "|");
			}
			else
			{
				strcpy(name, " ");
			}

			initPiece(&piece, name, playerName);
			
			*board[i][j] = piece;
		}
	}
}

void populateBoard(struct Piece (*board)[8][8], struct Player *player1, struct Player *player2)
{
	// Create green rook and put it in the board
	struct Piece greenRook;
	strcpy(greenRook.playerName, ((*player1)).name);
	strcpy(greenRook.name, "\033[1m\033[32mR\033[0m");
	*board[7][0] = greenRook;
	*board[7][7] = greenRook;

	// Create green knight and put it in the board
	struct Piece greenKnight;
	strcpy(greenKnight.playerName, (*player1).name);
	strcpy(greenKnight.name, "\033[1m\033[32mN\033[0m");
	*board[7][1] = greenKnight;
	*board[7][6] = greenKnight;

	// Create green bishop and put it in the board
	struct Piece greenBishop;
	strcpy(greenBishop.playerName, (*player1).name);
	strcpy(greenBishop.name, "\033[1m\033[32mB\033[0m");
	*board[7][2] = greenBishop;
	*board[7][5] = greenBishop;

	// Create green king and put it in the board
	struct Piece greenKing;
	strcpy(greenKing.playerName, (*player1).name);
	strcpy(greenKing.name, "\033[1m\033[32mK\033[0m");
	*board[7][3] = greenKing;

	// Create green queen and put it in the board
	struct Piece greenQueen;
	strcpy(greenQueen.playerName, (*player1).name);
	strcpy(greenQueen.name, "\033[1m\033[32mQ\033[0m");
	*board[7][4] = greenQueen;

	// Create green pawns and put it in the board
	struct Piece greenPawn;
	strcpy(greenPawn.playerName, (*player1).name);
	strcpy(greenPawn.name, "\033[1m\033[32mP\033[0m");
	*board[6][0] = greenPawn;
	*board[6][1] = greenPawn;
	*board[6][2] = greenPawn;
	*board[6][3] = greenPawn;
	*board[6][4] = greenPawn;
	*board[6][5] = greenPawn;
	*board[6][6] = greenPawn;
	*board[6][7] = greenPawn;

	// Create red rook and put it in the board
	struct Piece redRook;
	strcpy(redRook.playerName, (*player2).name);
	strcpy(redRook.name, "\033[1m\033[31mR\033[0m");
	*board[0][0] = redRook;
	*board[0][7] = redRook;

	// Create red knight and put it in the board
	struct Piece redKnight;
	strcpy(redKnight.playerName, (*player2).name);
	strcpy(redKnight.name, "\033[1m\033[31mN\033[0m");
	*board[0][1] = redKnight;
	*board[0][6] = redKnight;

	// Create red bishop and put it in the board
	struct Piece redBishop;
	strcpy(redBishop.playerName, (*player2).name);
	strcpy(redBishop.name, "\033[1m\033[31mB\033[0m");
	*board[0][2] = redBishop;
	*board[0][5] = redBishop;

	// Create red king and put it in the board
	struct Piece redKing;
	strcpy(redKing.playerName, (*player2).name);
	strcpy(redKing.name, "\033[1m\033[31mK\033[0m");
	*board[0][3] = redKing;

	// Create red queen and put it in the board
	struct Piece redQueen;
	strcpy(redQueen.playerName, (*player2).name);
	strcpy(redQueen.name, "\033[1m\033[31mQ\033[0m");
	*board[0][4] = redQueen;

	// Create red pawns and put it in the board
	struct Piece redPawn;
	strcpy(redPawn.playerName, (*player2).name);
	strcpy(redPawn.name, "\033[1m\033[31mP\033[0m");
	*board[1][0] = redPawn;
	*board[1][1] = redPawn;
	*board[1][2] = redPawn;
	*board[1][3] = redPawn;
	*board[1][4] = redPawn;
	*board[1][5] = redPawn;
	*board[1][6] = redPawn;
	*board[1][7] = redPawn;
}

void renderBoard(struct Piece (*board)[8][8], struct Player *player1, struct Player *player2)
{
	char playerOneCapturedPieces [350];
	playerOneCapturedPieces[0] = '\0';
	char playerTwoCapturedPieces [350];
	playerTwoCapturedPieces[0] = '\0';
	char buffer[100];

	for (int i = 0; i < (*player1).capturedPiecesCount; i++)
	{
		sprintf(buffer, " %s", (*player1).capturedPieces[i].name);
		strcat(playerOneCapturedPieces, buffer);
	}

	for (int i = 0; i < (*player2).capturedPiecesCount; i++)
	{
		sprintf(buffer, " %s", (*player2).capturedPieces[i].name);
		strcat(playerTwoCapturedPieces, buffer);
	}

	printf("      A     B     C     D     E     F     G     H   ");
	printf(" \n");
	printf("   -------------------------------------------------");
	printf(" \n");
	printf("8  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |", (*board)[0][0].name, (*board)[0][1].name, (*board)[0][2].name, (*board)[0][3].name, (*board)[0][4].name, (*board)[0][5].name, (*board)[0][6].name, (*board)[0][7].name);
	printf(" \n");
	printf("   -------------------------------------------------");
	printf(" \n");
	printf("7  |  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||        \033[1m\033[31mCaptured\033[0m -%s", (*board)[1][0].name, (*board)[1][1].name, (*board)[1][2].name, (*board)[1][3].name, (*board)[1][4].name, (*board)[1][5].name, (*board)[1][6].name, (*board)[1][7].name, playerTwoCapturedPieces);
	printf(" \n");
	printf("   -------------------------------------------------");
	printf(" \n");
	printf("6  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |        \033[1m\033[31mPlayer 2\033[0m - %s", (*board)[2][0].name, (*board)[2][1].name, (*board)[2][2].name, (*board)[2][3].name, (*board)[2][4].name, (*board)[2][5].name, (*board)[2][6].name, (*board)[2][7].name, (*player2).name);
	printf(" \n");
	printf("   -------------------------------------------------");
	printf(" \n");
	printf("5  |  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||", (*board)[3][0].name, (*board)[3][1].name, (*board)[3][2].name, (*board)[3][3].name, (*board)[3][4].name, (*board)[3][5].name, (*board)[3][6].name, (*board)[3][7].name);
	printf(" \n");
	printf("   -------------------------------------------------");
	printf(" \n");
	printf("4  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |", (*board)[4][0].name, (*board)[4][1].name, (*board)[4][2].name, (*board)[4][3].name, (*board)[4][4].name, (*board)[4][5].name, (*board)[4][6].name, (*board)[4][7].name);
	printf(" \n");
	printf("   -------------------------------------------------");
	printf(" \n");
	printf("3  |  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||        \033[1m\033[32mPlayer 1\033[0m - %s", (*board)[5][0].name, (*board)[5][1].name, (*board)[5][2].name, (*board)[5][3].name, (*board)[5][4].name, (*board)[5][5].name, (*board)[5][6].name, (*board)[5][7].name, (*player1).name);
	printf(" \n");
	printf("   -------------------------------------------------");
	printf(" \n");
	printf("2  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |        \033[1m\033[32mCaptured\033[0m -%s", (*board)[6][0].name, (*board)[6][1].name, (*board)[6][2].name, (*board)[6][3].name, (*board)[6][4].name, (*board)[6][5].name, (*board)[6][6].name, (*board)[6][7].name, playerOneCapturedPieces);
	printf(" \n");
	printf("   -------------------------------------------------");
	printf(" \n");
	printf("1  |  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||  %s  |||%s|||", (*board)[7][0].name, (*board)[7][1].name, (*board)[7][2].name, (*board)[7][3].name, (*board)[7][4].name, (*board)[7][5].name, (*board)[7][6].name, (*board)[7][7].name);
	printf(" \n");
	printf("   -------------------------------------------------");
	printf(" \n");
}

int extractRow(char *coordinate)
{
	switch (coordinate[1])
	{
		case '1':
			return 7;
		case '2':
			return 6;
		case '3':
			return 5;
		case '4':
			return 4;
		case '5':
			return 3;
		case '6':
			return 2;
		case '7':
			return 1;
		case '8':
			return 0;
		default:
			return -1;
	}
}

int extractColumn(char *coordinate)
{
	switch (toupper(coordinate[0]))
	{
		case 'A':
			return 0;
		case 'B':
			return 1;
		case 'C':
			return 2;
		case 'D':
			return 3;
		case 'E':
			return 4;
		case 'F':
			return 5;
		case 'G':
			return 6;
		case 'H':
			return 7;
		default:
			return -1;
	}
}