#include "sprite_stack.h"

void stack_remove(sprite_node *node)
{
    if (node->previous == NULL) {
        first = node->next;
    } else {
        node->previous->next = node->next;
    }

    if (node->next == NULL) {
        last = node->previous;
    } else {
        node->next->previous = node->previous;
    }

    SDL_FreeSurface(node->sprite->image);
    free(node);
}

void stack_push(sprite_node *node)
{
    last->next = node;
    node->previous = last;
    last = node;
}
