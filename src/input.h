#include "common.h"
#include "graphics.h"

#include <signal.h>

int quit;
void catch_signal(int signal);

int move_x;
int move_y;

SDL_Event event;
void setup_input();
void update_input();
void handle_keypress(SDLKey key);
void handle_keyup(SDLKey key);
