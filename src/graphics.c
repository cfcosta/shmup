#include "graphics.h"

SDL_Surface *display;
int create_display()
{
    int flags = SDL_HWSURFACE | SDL_DOUBLEBUF;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return 0;
    }

    if (display = SDL_SetVideoMode(640, 480, 32, flags)) {
        return 1;
    }

    return 0;
}