#ifndef GRID
#define GRID

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

typedef struct Element{
	int x;
	int y;
	int	 *chunk;
	int defined;
	struct Element *next;
} Element;

typedef struct Grid{
	Element *e;
	int max;
	int size;
} Grid;

int *createChunk(const int);

Grid createGrid(const int);

void freeGrid(Grid);

Element *getElement(Grid, const int, const int);

#endif //GRID