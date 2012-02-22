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

typedef struct s_sprite_node {
    sprite *sprite;
    struct s_sprite_node *previous;
    struct s_sprite_node *next;
} sprite_node;

sprite *load_sprite(char *filename, int width, int height, int x, int y, int frame_count);
void update_sprite(sprite *spr);
void teardown_sprite(sprite *spr);

sprite_node *first_sprite;
sprite_node *last_sprite;

sprite_node *create_node(sprite *spr);
void stack_remove(sprite_node *node);
void stack_push(sprite_node *node);
#endif

