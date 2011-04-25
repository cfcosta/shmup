#include "input.h"

void catch_signal(int signal)
{
    quit = 1;
}

void setup_input() {
    move_x = 0;
    move_y = 0;
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

    ship->rect.x += move_x;
    ship->rect.y += move_y;
}

void handle_keypress(SDLKey key)
{
    switch(key) {
        case SDLK_ESCAPE:
            quit = 1;
            break;
        case SDLK_UP:
            move_y = -2;
            break;
        case SDLK_DOWN:
            move_y = 2;
            break;
        case SDLK_LEFT:
            move_x = -2;
            break;
        case SDLK_RIGHT:
            move_x = 2;
            break;
        default:
            break;
    }
}

void handle_keyup(SDLKey key)
{
    switch(key) {
        case SDLK_UP:
            if (move_y < 0) move_y = 0;
            break;
        case SDLK_DOWN:
            if (move_y > 0) move_y = 0;
            break;
        case SDLK_LEFT:
            if (move_x < 0) move_x = 0;
            break;
        case SDLK_RIGHT:
            if (move_x > 0) move_x = 0;
            break;
        default:
            break;
    }
}
