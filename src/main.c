#include <stdio.h>

#include "graphics.h"

int main (int argc, char ** argv)
{
    const int frames_per_second = 60;
    const int skip_frames = 1000 / frames_per_second;
    const int max_frameskip = 10;

    Uint32 next_game_frame = SDL_GetTick();
    int loops = 0;

    if (!create_display()) {
      printf("Could not initialize the window.\n");
      printf("%s", SDL_GetError());
      return 1;
    }

    SDL_WM_SetCaption("SDL Shmup", "SDL Shmup");

    while(1) {
        while (SDL_GetTick() > next_game_frame && loops > max_frameskip) {

          next_game_frame += skip_frames;
          loops++;
        }

        update_display();
    }

    SDL_Quit();
    return 0;
}
