#ifndef WINDOW
#define WINDOW

#include <stdlib.h>
#include <SDL.h>

typedef struct Window{
	SDL_Surface *screen;
	Uint32 color;
	double alpha;
	int width;
	int height;
	int closed;
	int fsize;
	int FPS;
	SDL_Event events;
} Window;

typedef struct RGB{
	int red;
	int green;
	int blue;
} RGB;

void startSDL();

void endSDL(Window*);

Window* createWindow(int, int, char*, int);

RGB hexToRGB(const int hex);

void setAlpha(Window*, const double);

void setColor(Window*, const int);

void drawRect(Window*, int, int, int, int);

void checkForClose(Window*);

void update(Window*);

#endif //WINDOW