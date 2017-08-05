#include "input.h"

void catch_signal(int signal) { quit = true; }

void setup_input() {
  max_speed = 3;

  accel = malloc(sizeof(directions));
  speed = malloc(sizeof(directions));
  pressed_keys = malloc(sizeof(keys));

  pressed_keys->up = false;
  pressed_keys->down = false;
  pressed_keys->left = false;
  pressed_keys->right = false;

  accel->up = 0;
  accel->down = 0;
  accel->left = 0;
  accel->right = 0;

  speed->up = 0;
  speed->down = 0;
  speed->left = 0;
  speed->right = 0;
}

void teardown_input(void) {
  free(accel);
  free(speed);
  free(pressed_keys);
}

void update_input() {
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    case SDL_KEYDOWN:
      handle_keypress(event.key.keysym.sym);
      break;
    case SDL_KEYUP:
      handle_keyup(event.key.keysym.sym);
      break;
    }
  }

  if (accel->up > 0)
    accel->up--;
  if (accel->down > 0)
    accel->down--;
  if (accel->left > 0)
    accel->left--;
  if (accel->right > 0)
    accel->right--;

  if (speed->up > 0)
    speed->up--;
  if (speed->down > 0)
    speed->down--;
  if (speed->left > 0)
    speed->left--;
  if (speed->right > 0)
    speed->right--;

  if (pressed_keys->up)
    accel->up = 2;
  if (pressed_keys->down)
    accel->down = 2;
  if (pressed_keys->left)
    accel->left = 2;
  if (pressed_keys->right)
    accel->right = 2;

  speed->up += accel->up;
  speed->down += accel->down;
  speed->left += accel->left;
  speed->right += accel->right;

  if (speed->up > max_speed)
    speed->up = max_speed;
  if (speed->down > max_speed)
    speed->down = max_speed;
  if (speed->left > max_speed)
    speed->left = max_speed;
  if (speed->right > max_speed)
    speed->right = max_speed;

  ship->rect.x += (speed->right - speed->left);
  ship->rect.y += (speed->down - speed->up);
}

void handle_keypress(SDLKey key) {
  switch (key) {
  case SDLK_f:
    toggle_fullscreen();
    break;
  case SDLK_ESCAPE:
    quit = true;
    break;
  case SDLK_UP:
    pressed_keys->up = true;
    break;
  case SDLK_DOWN:
    pressed_keys->down = true;
    break;
  case SDLK_LEFT:
    pressed_keys->left = true;
    break;
  case SDLK_RIGHT:
    pressed_keys->right = true;
    break;
  default:
    break;
  }
}

void handle_keyup(SDLKey key) {
  switch (key) {
  case SDLK_UP:
    pressed_keys->up = false;
    break;
  case SDLK_DOWN:
    pressed_keys->down = false;
    break;
  case SDLK_LEFT:
    pressed_keys->left = false;
    break;
  case SDLK_RIGHT:
    pressed_keys->right = false;
    break;
  default:
    break;
  }
}
