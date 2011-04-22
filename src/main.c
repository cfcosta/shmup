#include <stdio.h>

#include "graphics.h"

int main (int argc, char ** argv)
{
    if (!create_display()) {
      printf("Could not initialize the window.\n");
      printf("%s", SDL_GetError());
      return 1;
    }

    return 0;
}
