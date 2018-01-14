#include <stdio.h>
#include "libsdl.h"
#include "hash.h"
#include "grid.h"
#include "game.h"
#include "keyboard.h"
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]){
	srand(time(NULL));
	
	startSDL();
	Window *w = createWindow(500, 500, "Hashed Map!");
	w->fsize = 10;

	Keyboard key = {0};

	Grid map = createGrid(10000);
	Player player = {0};

	while(!w->closed){
		while(SDL_PollEvent(&w->events)){
			setKeys(w->events, &key);
			checkForClose(w);
		}

		if(key.up){
			player.y -= 1;
		}
		if(key.down){
			player.y += 1;
		}
		if(key.right){
			player.x += 1;
		}
		if(key.left){
			player.x -= 1;
		}

		clrScreen(w);
		drawMap(w, map, player);
		drawPlayer(w, player);

		SDL_Flip(w->screen);
		SDL_Delay(200);
	}

	freeGrid(map);
	endSDL(w);
	return 0;
}
