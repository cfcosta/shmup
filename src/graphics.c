#include "graphics.h"

int create_display()
{
    Uint32 flags = SDL_HWSURFACE | SDL_DOUBLEBUF;
    SDL_Init(SDL_INIT_EVERYTHING);

    display = SDL_SetVideoMode(640, 480, 32, flags);

    load_background();
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

void load_background()
{
    bg1 = malloc(sizeof(background));
    bg1->image = IMG_Load("galaxy.png");
    bg1->rect.x = 0;
    bg1->rect.y = 0;
}

void update_display()
{
    SDL_FillRect(display, NULL, SDL_MapRGB(display->format, 0, 0, 0));
    update_background();

    SDL_BlitSurface(ship->image, NULL, display, &ship->rect);
    SDL_Flip(display);
}

void update_background()
{
    SDL_BlitSurface(bg1->image, NULL, display, &bg1->rect);
}
