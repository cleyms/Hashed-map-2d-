#ifndef GAME
#define GAME

#include "noise.h"
#include "window.h"
#include "grid.h"
#include <math.h>

typedef struct Player{
	int x;
	int y;
} Player;

typedef struct River{
	int startX;
	int startY;
	int endX;
	int endY;
	int width;
} River;

void drawCase(Window*, const Player, const int, const int);

void drawRiver(Window*, const Player, const River);

void clrScreen(Window*);

void drawPlayer(Window*, const Player);

void drawChunk(Window*, const int, const int, int*, const int, const Player);

void generate(Grid, const int, const int);

void drawAllGrid(Window*, Grid, const Player);

void drawGrid(Window*, Grid, const Player);

#endif //GAME