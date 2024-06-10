// #include "../include/piece.h"
#include "../include/player.h"
#include "../include/board.h"

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