#ifndef GAME
#define GAME

#include "libsdl.h"
#include "grid.h"
#include <math.h>

typedef struct Player{
	int x;
	int y;
} Player;

void clrScreen(Window*);

void drawPlayer(Window*, const Player);

void generate(Grid, const int, const int);

void drawMap(Window*, Grid, const Player);

#endif //GAME