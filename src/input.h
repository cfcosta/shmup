#include "common.h"
#include "graphics.h"

#include <signal.h>

bool quit;
void catch_signal(int signal);

bool pressed_up;
bool pressed_down;
bool pressed_left;
bool pressed_right;

int max_speed;
int accel_up;
int accel_down;
int accel_left;
int accel_right;
int speed_up;
int speed_down;
int speed_left;
int speed_right;

SDL_Event event;
void setup_input();
void update_input();
void handle_keypress(SDLKey key);
void handle_keyup(SDLKey key);
