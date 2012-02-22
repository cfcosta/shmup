#ifndef H_ANIMATION
#define H_ANIMATION

#include "common.h"

typedef struct s_sprite {
    SDL_Surface *image;
    SDL_Rect rect;

    int current_frame;
    int frame_count;
    int start_position;
} sprite;

sprite *load_sprite(char *filename, int width, int height, int x, int y, int frame_count);
void update_sprite(sprite *spr);
void teardown_sprite(sprite *spr);

#endif
