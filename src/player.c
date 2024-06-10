#include <string.h>
#include "../include/player.h"

void initPlayer(struct Player *player, const char *name)
{
	strcpy(player -> name, name);
	player -> capturedPiecesCount = 0;
}