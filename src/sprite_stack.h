#ifndef H_SPRITE_STACK
#define H_SPRITE_STACK

#include "graphics.h"

typedef struct s_sprite_node {
    sprite *sprite;
    s_sprite_node *previous;
    s_sprite_node *next;
} sprite_node;

sprite_node *first_sprite;
sprite_node *last_sprite;

void stack_remove(sprite_node *node);
void stack_push(sprite_node *node);
#endif
