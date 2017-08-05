#pragma once

#include "common.h"
#include "input.h"
#include "sprite.h"

typedef struct s_background {
  i8 speed;
  SDL_Surface *image;
  SDL_Rect rect;
} background;

background *bg1;
background *bg2;

int create_display();
void toggle_fullscreen();

void load_background();
void load_spaceship();

void update_display();
void update_background();
void update_ship();

void teardown_display();
