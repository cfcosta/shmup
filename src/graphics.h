#include "common.h"

SDL_Surface *display;

#ifndef S_SPRITE
    #define S_SPRITE
    typedef struct {
        SDL_Surface *image;
        SDL_Rect rect;
    } sprite;
#endif

sprite *ship;
int create_display();
void load_spaceship();

void update_display();
