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

typedef struct {
  int up;
  int down;
  int left;
  int right;
} movement;

movement *accel;
movement *speed;

SDL_Event event;
void setup_input();
void update_input();
void handle_keypress(SDLKey key);
void handle_keyup(SDLKey key);
