#ifndef KEYBOARD
#define KEYBOARD

#include <SDL.h>

typedef struct Keyboard{
	int up;
	int down;
	int left;
	int right;
} Keyboard;

void setKeys(const SDL_Event, Keyboard*);

#endif //KEYBOARD