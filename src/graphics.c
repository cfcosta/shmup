#include "graphics.h"

int create_display()
{
    Uint32 flags = SDL_HWSURFACE | SDL_DOUBLEBUF;
    SDL_Init(SDL_INIT_EVERYTHING);

    display = SDL_SetVideoMode(640, 480, 32, flags);

    ship = IMG_Load("spaceship.png");

    ship_rect.x = 100;
    ship_rect.y = 100;

    SDL_Flip(display);

    return 1;
}

void update_display()
{
    SDL_BlitSurface(ship, NULL, display, &ship_rect);
    SDL_Flip(display);
}
