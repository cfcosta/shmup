#include "common.h"

#include <signal.h>

int quit;
void catch_signal(int signal);

SDL_Event event;
void update_input();
void handle_keypress(SDLKey key);
