#include "common.h"
#include "graphics.h"

#include <signal.h>

int quit;
void catch_signal(int signal);

int speed_up;
int speed_down;
int speed_left;
int speed_right;

int pressed_up;
int pressed_down;
int pressed_left;
int pressed_right;

SDL_Event event;
void update_input();
void handle_keypress(SDLKey key);
void handle_keyup(SDLKey key);
