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

void teardown_display()
{
    SDL_FreeSurface(ship->image);
    SDL_FreeSurface(bg1->image);
    /*SDL_FreeSurface(bg2->image);*/

    free(ship);
    free(bg1);
    free(bg2);
}

void load_spaceship()
{
    ship = malloc(sizeof(sprite));
    ship->image = IMG_Load("sprite.png");

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
    int ship_x, ship_y, ship_h;

    if (pressed_keys->left) {
        ship_x = 0;
    } else if (pressed_keys->right) {
        ship_x = 82;
    } else {
        ship_x = 40;
    }

    if (pressed_keys->up) {
        if (*frame_count % 2 == 0) {
            ship_y = 40;
            ship_h = 46;
        } else {
            ship_y = 86;
            ship_h = 46;
        }
    } else {
        ship_y = 0;
        ship_h = 42;
    }

    SDL_Rect *clip = malloc(sizeof(SDL_Rect));
    clip->x = ship_x;
    clip->y = ship_y;
    clip->w = 40;
    clip->h = ship_h;

    SDL_FillRect(display, NULL, SDL_MapRGB(display->format, 0, 0, 0));
    update_background();

    SDL_BlitSurface(ship->image, clip, display, &ship->rect);
    SDL_Flip(display);

    free(clip);
}

void update_background()
{
    SDL_BlitSurface(bg1->image, NULL, display, &bg1->rect);
}
