#include "grid.h"

int *createChunk(const int size){
	int *chunk = malloc(size*size*sizeof(int)), i = 0;
	for(; i < size*size; i++)
		chunk[i] = 0;
	return chunk;
}

Grid createGrid(const int max){
	Grid g;
	g.e = malloc(max*sizeof(Element));
	g.size = 5;
	Element e = {0};
	e.defined = 0;
	e.chunk = createChunk(g.size);
	e.next = NULL;
	int i = 0;
	for(; i < max; i++)
		g.e[i] = e;
	g.max = max;
	return g;
}

void freeGrid(Grid g){
	Element *e1, *e2;
	int i = 0;
	for(; i < g.max; i++){
		e1 = g.e+i;
		if(e1->next != NULL){
			e1 = e1->next;
			while(e1 != NULL){
				e2 = e1;
				e1 = e1->next;
				free(e2->chunk);
				free(e2);
			}
		}
	}
	free(g.e);
}

Element *getElement(Grid g, const int x, const int y){
	int h = hash(x, y, g.max);
	Element *e = g.e+h;
	while(e->defined && !(e->x == x && e->y == y)){
		if(e->next == NULL){
			Element *n = malloc(sizeof(*n));
			n->next = NULL;
			n->x = x;
			n->y = y;
			n->chunk = createChunk(g.size);
			n->defined = 0;
			e->next = n;
		}
		e = e->next;
	}
	return e;
}
