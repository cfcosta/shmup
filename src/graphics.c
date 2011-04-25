#include "graphics.h"

int create_display()
{
    Uint32 flags = SDL_HWSURFACE | SDL_DOUBLEBUF;
    SDL_Init(SDL_INIT_EVERYTHING);

    display = SDL_SetVideoMode(640, 480, 32, flags);

    load_spaceship();

    return 1;
}

void load_spaceship()
{
    ship = malloc(sizeof(sprite));
    ship->image = IMG_Load("spaceship.png");
    ship->rect.x = 100;
    ship->rect.y = 100;
}

}

void update_display()
{
    SDL_FillRect(display, NULL, SDL_MapRGB(display->format, 0, 0, 0));

    SDL_BlitSurface(ship->image, NULL, display, &ship->rect);
    SDL_Flip(display);
}
