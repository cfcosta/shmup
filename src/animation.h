#ifndef H_ANIMATION
#define H_ANIMATION

#include "graphics.h"

sprite * load_sprite(char *filename, int width, int height, int x, int y, int frame_count);
void update_sprite(sprite* spr);
void teardown_sprite(sprite* spr);

#endif
