#include <time.h>
#include <math.h>

#include "window.h"
#include "grid.h"
#include "game.h"
#include "keyboard.h"

int main(int argc, char *argv[]){
	srand(time(NULL));
	Window *w = createWindow(800, 600, "Hashed Map!", 50);
	w->fsize = 10;

	Keyboard key = {0};

	Grid grid = createGrid(1);
	Player player = {0};

	while(!w->closed){
		while(SDL_PollEvent(&w->events)){
			setKeys(w->events, &key);
			checkForClose(w);
		}
		player.x += key.right-key.left;
		player.y += key.down-key.up;

		clrScreen(w);
		drawGrid(w, grid, player);
		drawPlayer(w, player);

		update(w);
	}
	freeGrid(grid);
	endSDL(w);
	return 0;
}
