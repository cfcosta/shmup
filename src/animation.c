#include "animation.h"

sprite *load_sprite(char *filename, int width, int height, int x, int y, int frame_count)
{
    sprite *result = malloc(sizeof(sprite));
    result->image = IMG_Load(filename);

    result->current_frame = 0;
    result->frame_count = frame_count;

    result->rect.w = width;
    result->rect.h = height;

    result->start_position = x;
    result->rect.x = x;
    result->rect.y = y;

    return result;
}

void update_sprite(sprite *spr)
{
    if (spr->current_frame < spr->frame_count) {
        spr->rect.x = (spr->rect.x + spr->rect.w);
        spr->current_frame++;
    } else {
        spr->rect.x = spr->start_position;
        spr->current_frame = 0;
    }
}

void teardown_sprite(sprite *spr)
{
    SDL_FreeSurface(spr->image);
    free(spr);
}
