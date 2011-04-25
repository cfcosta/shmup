#include "input.h"

void catch_signal(int signal)
{
    quit = true;
}

void setup_input() {
  max_speed = 4;
  accel_up = 0;
  accel_down = 0;
  accel_left = 0;
  accel_right = 0;
  speed_up = 0;
  speed_down = 0;
  speed_left = 0;
  speed_right = 0;
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

    speed_up--;
    speed_down--;
    speed_left--;
    speed_right--;

    if (pressed_up) accel_up = 2;
    if (pressed_down) accel_down = 2;
    if (pressed_left) accel_left = 2;
    if (pressed_right) accel_right = 2;

    speed_up += accel_up;
    speed_down += accel_down;
    speed_left += accel_left;
    speed_right += accel_right;

    if (speed_up > max_speed) speed_up = max_speed;
    if (speed_down > max_speed) speed_down = max_speed;
    if (speed_left > max_speed) speed_left = max_speed;
    if (speed_right > max_speed) speed_right = max_speed;

    if (speed_up < 0) speed_up = 0;
    if (speed_down < 0) speed_down = 0;
    if (speed_left < 0) speed_left = 0;
    if (speed_right < 0) speed_right = 0;

    ship->rect.x += (speed_right + (speed_left * -1));
    ship->rect.y += (speed_down + (speed_up * -1));
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
