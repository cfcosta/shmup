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
        }
    }
}
