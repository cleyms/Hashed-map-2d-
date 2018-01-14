#ifndef GRID
#define GRID

#include <stdlib.h>

typedef struct Element{
	int x;
	int y;
	int value;
	int defined;
	struct Element *next;
} Element;

typedef struct Grid{
	Element *e;
	int max;
} Grid;

Grid createGrid(const int);

Element *getElement(const Grid, const int, const int);

int getGrid(const Grid, const int, const int);

void setGrid(Grid, const int, const int, const int);

void freeGrid(Grid);

#endif //GRID