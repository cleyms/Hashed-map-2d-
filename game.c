#include "game.h"

void drawCase(Window *w, const Player p, const int x, const int y){
	int xCase = w->width/w->fsize;
	int yCase = w->height/w->fsize;
	drawRect(w, (x-p.x+xCase/2)*w->fsize, (y-p.y+yCase/2)*w->fsize, w->fsize, w->fsize);
}

void clrScreen(Window *w){
	setColor(w, 0x555);
	drawRect(w, 0, 0, w->width, w->height);
}

void drawPlayer(Window *w, const Player p){
	setAlpha(w, 1);
	setColor(w, 0x352e24);
	drawCase(w, p, p.x, p.y);
}

void drawChunk(Window *w, const int i, const int j, int *chunk, const int size, const Player p){
	int x, y;
	for(x = 0; x < size; x++){
		for(y = 0; y < size; y++){
			setColor(w, chunk[x+y*size]);
			drawCase(w, p, size*i+x, size*j+y);
		}
	}
}

void drawAllGrid(Window *w, Grid g, const Player p){
	int i = 0;
	Element *e = NULL;
	for(; i < g.max; i++){
		e = g.e+i;
		while(e->defined){
			drawChunk(w, e->x, e->y, e->chunk, g.size, p);
			e = e->next;
			if(e == NULL)
				break;
		}
	}
}

void drawGrid(Window *w, Grid g, const Player p){
	setAlpha(w, 0.5);
	drawAllGrid(w, g, p);
	int around = 9, i, j, x = p.x/g.size, y = p.y/g.size;
	Element *e = NULL;
	setAlpha(w, 1);
	for(i = x-around; i <= x+around; i++){
		for(j = y-around; j <= y+around; j++){
			e = getElement(g, i, j);
			if(!e->defined){
				generate(g, i, j);
				e->defined = 1;
			}
			drawChunk(w, i, j, e->chunk, g.size, p);
		}
	}
}

void generate(Grid g, const int x, const int y){
	Element *e = getElement(g, x, y);
	int i, j;
	float xoff = 0;
	for(i = 0; i < g.size; i++){
		float yoff = 0;
		for(j = 0; j < g.size; j++){
			float noise = perlin2d(x*g.size+xoff, y*g.size+yoff, 0.05, 8);
			int color;
			if(noise < 0.25)
				color = 0x11C;
			else if(noise < 0.7)
				color = 0x464;
			else
				color = 0x999;
			e->chunk[i+g.size*j] = color;
			yoff += 0.5;
		}
		xoff += 0.5;
	}
}
