#include "input.h"

void catch_signal(int signal)
{
    quit = true;
}

void setup_input() {
  max_speed = 4;

  accel = malloc(sizeof(directions));
  speed = malloc(sizeof(directions));

  accel->up = 0;
  accel->down = 0;
  accel->left = 0;
  accel->right = 0;

  speed->up = 0;
  speed->down = 0;
  speed->left = 0;
  speed->right = 0;
}

void update_input()
{
    if (SDL_PollEvent(&event)) {
        switch(event.type) {
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

    speed->up--;
    speed->down--;
    speed->left--;
    speed->right--;

    if (pressed_up) accel->up = 2;
    if (pressed_down) accel->down = 2;
    if (pressed_left) accel->left = 2;
    if (pressed_right) accel->right = 2;

    speed->up += accel->up;
    speed->down += accel->down;
    speed->left += accel->left;
    speed->right += accel->right;

    if (speed->up > max_speed) speed->up = max_speed;
    if (speed->down > max_speed) speed->down = max_speed;
    if (speed->left > max_speed) speed->left = max_speed;
    if (speed->right > max_speed) speed->right = max_speed;

    if (speed->up < 0) speed->up = 0;
    if (speed->down < 0) speed->down = 0;
    if (speed->left < 0) speed->left = 0;
    if (speed->right < 0) speed->right = 0;

    ship->rect.x += (speed->right + (speed->left * -1));
    ship->rect.y += (speed->down + (speed->up * -1));
}

void handle_keypress(SDLKey key)
{
    switch(key) {
        case SDLK_ESCAPE:
            quit = true;
            break;
        case SDLK_UP:
            pressed_up = true;
            break;
        case SDLK_DOWN:
            pressed_down = true;
            break;
        case SDLK_LEFT:
            pressed_left = true;
            break;
        case SDLK_RIGHT:
            pressed_right = true;
            break;
        default:
            break;
    }
}

void handle_keyup(SDLKey key)
{
    switch(key) {
        case SDLK_UP:
            pressed_up = false;
            break;
        case SDLK_DOWN:
            pressed_down = false;
            break;
        case SDLK_LEFT:
            pressed_left = false;
            break;
        case SDLK_RIGHT:
            pressed_right = false;
            break;
        default:
            break;
    }
}
