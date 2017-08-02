#pragma once

#include "common.h"

typedef struct s_sprite {
  SDL_Surface *image;
  SDL_Rect rect;
  SDL_Rect clip_rect;

  i64 current_frame;
  i64 frame_count;
  i8 start_position;
} sprite;

typedef struct s_sprite_node {
  sprite *sprite;
  struct s_sprite_node *previous;
  struct s_sprite_node *next;
} sprite_node;

sprite *load_sprite(char *filename, u16 width, u16 height, u16 x, u16 y,
                    u8 frame_count);
void move_sprite(sprite *spr, u16 x, u16 y);
void update_sprite(sprite *spr);
void teardown_sprite(sprite *spr);

sprite_node *first_sprite;
sprite_node *last_sprite;

sprite_node *create_node(sprite *spr);
void stack_remove(sprite_node *node);
void stack_push(sprite_node *node);
