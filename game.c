#include "game.h"

void clrScreen(Window *w){
	setColor(w, 0x555);
	drawRect(w, 0, 0, 510, 510);
}

void drawPlayer(Window *w, const Player p){
	setColor(w, 0xB11);
	int s = w->fsize;
	int caseX = w->width/s/2;
	int caseY = w->height/s/2;
	drawRect(w, (caseX+p.x)*s, (caseY+p.y)*s, s, s);
}

void drawMap(Window *w, Grid m, const Player p){
	int temp = 20;
	int s = w->fsize;
	int minX = p.x-(w->width/s/2)+temp;
	int maxX = minX+(w->width/s)-temp*2;
	int minY = p.y-(w->height/s/2)+temp;
	int maxY = minY+(w->height/s)-temp*2;
	int centreX = w->width/s/2;
	int centreY = w->width/s/2;
	int i, j;
	Element *e;
	for(i = minX; i < maxX; i++){
		for(j = minY; j < maxY; j++){
			e = getElement(m, i, j);
			if(!e->defined)
				generate(m, i, j);
			if(e->value)
				setColor(w, 0x000);
			else
				setColor(w, 0xFFF);
			drawRect(w, (centreX+i)*s, (centreY+j)*s, s, s);
		}
	}
}

void generate(Grid g, const int x, const int y){
	setGrid(g, x, y, rand()%2);
}
