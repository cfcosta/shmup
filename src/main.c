#define SDL_main main

#include <stdio.h>

#include "graphics.h"

int main (int argc, char const* argv[])
{
    if (!create_display()) {
      printf("Could not initialize the window.\n");
      printf("%s", SDL_GetError());
      return 1;
    }

    return 0;
}
