#ifndef H_SPRITE_STACK
#define H_SPRITE_STACK

#include "common.h"
#include "animation.h"

typedef struct s_sprite_node {
    sprite *sprite;
    struct s_sprite_node *previous;
    struct s_sprite_node *next;
} sprite_node;

sprite_node *first_sprite;
sprite_node *last_sprite;

sprite_node *create_node(sprite *spr);
void stack_remove(sprite_node *node);
void stack_push(sprite_node *node);
#endif
