#ifndef H_SPRITE_STACK
#define H_SPRITE_STACK

#include "graphics.h"

struct sprite_node {
    sprite *sprite;
    struct sprite_node *previous;
    struct sprite_node *next;
};
typedef struct sprite_node sprite_node;

sprite_node *first;
sprite_node *last;

void stack_remove(sprite_node *node);
void stack_push(sprite_node *node);
#endif
