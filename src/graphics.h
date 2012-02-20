#ifndef H_GRAPHICS
#define H_GRAPHICS
#include "input.h"
#include "common.h"

SDL_Surface *display;

typedef struct {
    SDL_Surface *image;
    SDL_Rect rect;
} sprite;

typedef struct {
    int speed;
    SDL_Surface *image;
    SDL_Rect rect;
} background;

sprite *ship;

background *bg1;
background *bg2;

int create_display();
void load_background();
void load_spaceship();

void update_display();
void update_background();
