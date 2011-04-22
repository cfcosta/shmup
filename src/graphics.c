#include "graphics.h"

int create_display()
{
    Uint32 flags = SDL_HWSURFACE | SDL_DOUBLEBUF;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return 0;
    }

    if ((display = SDL_SetVideoMode(640, 480, 32, flags)) != NULL) {
        return 1;
    }

    return 0;
}

void update_display()
{
    SDL_Flip(display);
}
