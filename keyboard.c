#include "keyboard.h"

void setKeys(const SDL_Event e, Keyboard *k){
	if(e.type == SDL_KEYDOWN){
		switch(e.key.keysym.sym){
			case SDLK_UP:
				k->up = 1;
				break;
			case SDLK_DOWN:
				k->down = 1;
				break;
			case SDLK_RIGHT:
				k->right = 1;
				break;
			case SDLK_LEFT:
				k->left = 1;
				break;
		}
	}else if(e.type == SDL_KEYUP){
		switch(e.key.keysym.sym){
			case SDLK_UP:
				k->up = 0;
				break;
			case SDLK_DOWN:
				k->down = 0;
				break;
			case SDLK_RIGHT:
				k->right = 0;
				break;
			case SDLK_LEFT:
				k->left = 0;
				break;
		}
	}
}