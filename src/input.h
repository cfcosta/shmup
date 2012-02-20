#ifndef H_INPUT
#define H_INPUT

#include "common.h"
#include "graphics.h"

#include <signal.h>

bool quit;
void catch_signal(int signal);

int max_speed;

typedef struct {
    int up;
    int down;
    int left;
    int right;
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
#endif
