#include "sprite_stack.h"

void stack_remove(sprite_node *node)
{
    if (node->previous == NULL) {
        first_sprite = node->next;
    } else {
        node->previous->next = node->next;
    }

    if (node->next == NULL) {
        last_sprite = node->previous;
    } else {
        node->next->previous = node->previous;
    }

    SDL_FreeSurface(node->sprite->image);
    free(node);
}

void stack_push(sprite_node *node)
{
    last_sprite->next = node;
    node->previous = last_sprite;
    last_sprite = node;
}
