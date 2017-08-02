#pragma once

#include "common.h"
#include "graphics.h"

#include <signal.h>

bool quit;
void catch_signal(int signal);

u8 max_speed;

typedef struct {
  u8 up;
  u8 down;
  u8 left;
  u8 right;
} directions;

directions *accel;
directions *speed;

typedef struct {
  bool up;
  bool down;
  bool left;
  bool right;
} keys;

keys *pressed_keys;

SDL_Event event;
void setup_input();
void update_input();
void teardown_input();
void handle_keypress(SDLKey key);
void handle_keyup(SDLKey key);
