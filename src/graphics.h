#include "common.h"

SDL_Surface *display;

#ifndef S_SPRITE
    #define S_SPRITE
    typedef struct {
        SDL_Surface *image;
        SDL_Rect rect;
    } sprite;
#endif

#ifndef S_BACKGROUND
    #define S_BACKGROUND
    typedef struct {
        int speed;
        SDL_Surface *image;
        SDL_Rect rect;
    } background;
#endif

sprite *ship;

background *bg1;
background *bg2;

int create_display();
void load_background();
void load_spaceship();

void update_display();
void update_background();
