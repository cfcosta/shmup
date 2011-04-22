#include "input.h"

void catch_signal(int signal)
{
    quit = 1;
}

void update_input()
{
    if (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                quit = 1;
                break;
            case SDL_KEYDOWN:
                handle_keypress(event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                handle_keyup(event.key.keysym.sym);
                break;
        }
    }

    if (!pressed_up) speed_up--;
    if (!pressed_down) speed_down--;
    if (!pressed_left) speed_left--;
    if (!pressed_right) speed_right--;

    if (speed_up > 3) speed_up = 3;
    if (speed_down > 3) speed_down = 3;
    if (speed_left > 3) speed_left = 3;
    if (speed_right > 3) speed_right = 3;

    if (speed_up < 0) speed_up = 0;
    if (speed_down < 0) speed_down = 0;
    if (speed_left < 0) speed_left = 0;
    if (speed_right < 0) speed_right = 0;

    ship_rect.y += speed_up;
    ship_rect.y -= speed_down;
    ship_rect.x += speed_right;
    ship_rect.x -= speed_left;
}

void handle_keypress(SDLKey key)
{
    switch(key) {
        case SDLK_ESCAPE:
            quit = 1;
            break;
        case SDLK_UP:
            pressed_up = 1;
            speed_up++;
            speed_down--;
        case SDLK_DOWN:
            pressed_down = 1;
            speed_down++;
            speed_up--;
        case SDLK_LEFT:
            pressed_left = 1;
            speed_left++;
            speed_right--;
        case SDLK_RIGHT:
            pressed_right = 1;
            speed_right++;
            speed_left--;
        default:
            break;
    }
}

void handle_keyup(SDLKey key)
{
    switch(key) {
        case SDLK_UP:
            pressed_up = 0;
        case SDLK_DOWN:
            pressed_down = 0;
        case SDLK_LEFT:
            pressed_left = 0;
        case SDLK_RIGHT:
            pressed_right = 0;
        default:
            break;
    }
}
