#pragma once

#include "common.h"
#include "input.h"
#include "sprite.h"

typedef struct {
  i8 speed;
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

void teardown_display();
