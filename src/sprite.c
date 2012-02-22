#include "sprite.h"

sprite *load_sprite(char *filename, int width, int height, int x, int y, int frame_count)
{
    sprite *result = malloc(sizeof(sprite));
    result->image = IMG_Load(filename);

    result->current_frame = 0;
    result->frame_count = frame_count;

    result->rect.x = x;
    result->rect.y = y;

    result->clip_rect.w = width;
    result->clip_rect.h = height;

    result->start_position = x;

    return result;
}

void move_sprite(sprite *spr, int x, int y) {
    spr->rect.x = x;
    spr->rect.y = y;
}

void update_sprite(sprite *spr)
{
    if (spr->current_frame < spr->frame_count) {
        spr->clip_rect.x = (spr->clip_rect.x + spr->clip_rect.w);
        spr->current_frame++;
    } else {
        spr->clip_rect.x = spr->start_position;
        spr->current_frame = 0;
    }

    SDL_BlitSurface(spr->image, &spr->clip_rect, display, &spr->rect);
}

void teardown_sprite(sprite *spr)
{
    SDL_FreeSurface(spr->image);
    free(spr);
}

sprite_node *create_node(sprite *spr) {
    sprite_node *sprn = malloc(sizeof(sprite_node));
    sprn->sprite = spr;
    sprn->previous = NULL;
    sprn->next = NULL;

    if (last_sprite) {
        stack_push(sprn);
    } else {
        last_sprite = sprn;
    }

    return sprn;
}

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
    node->next = NULL;
    last_sprite = node;
}
