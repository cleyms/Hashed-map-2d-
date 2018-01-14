#include "grid.h"

Grid createGrid(const int max){
	Grid g;
	g.e = malloc(max*sizeof(Element));
	Element e = {0};
	e.next = NULL;
	int i = 0;
	for(; i < max; i++)
		g.e[i] = e;
	g.max = max;
	return g;
}

Element *getElement(const Grid g, const int x, const int y){
	int h = hash(x, y, g.max);
	Element *e = g.e+h;
	while(e->defined && e->x != x && e->y != y){
		if(e->next == NULL){
			Element *n = malloc(sizeof(*n));
			n->x = 0;
			n->y = 0;
			n->value = 0;
			n->defined = 0;
			e->next = n;
		}
		e = e->next;
	}
	return e;
}

int getGrid(const Grid g, const int x, const int y){
	Element *e = getElement(g, x, y);
	return e->value;
}
void setGrid(Grid g, const int x, const int y, const int val){
	Element *e = getElement(g, x, y);
	e->x = x;
	e->y = y;
	e->value = val;
	e->defined = 1;
}

void freeGrid(Grid g){
	Element *e1, *e2;
	int i = 0;
	for(; i < g.max; i++){
		e1 = g.e+i;
		while(e1->next != NULL){
			e2 = e1;
			e1 = e1->next;
			free(e2);
		}
	}
	free(g.e);
}
