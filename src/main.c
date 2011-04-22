#include "common.h"
#include "graphics.h"
#include "input.h"

int main (int argc, char ** argv)
{
    const int frames_per_second = 30;
    const int skip_frames = 1000 / frames_per_second;

    Uint32 next_game_frame;
    Uint32 current_frame;

    signal(SIGTERM, catch_signal);
    signal(SIGINT, catch_signal);

    if (!create_display()) {
        printf("Could not initialize the window.\n");
        printf("%s", SDL_GetError());
        return 1;
    }

    SDL_WM_SetCaption("SDL Shmup", "SDL Shmup");

    current_frame = SDL_GetTicks();
    next_game_frame = current_frame;

    setbuf(stdout, NULL);

    quit = 0;
    while(!quit) {
        update_input();

        current_frame = SDL_GetTicks();

        if (current_frame < next_game_frame) {
            SDL_Delay(next_game_frame - current_frame);
        }

        next_game_frame = (current_frame + skip_frames);

        update_display();
    }

    SDL_Quit();
    return 0;
}
