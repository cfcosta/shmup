#include "graphics.h"

int create_display() {
  u32 flags = SDL_HWSURFACE | SDL_DOUBLEBUF;
  SDL_Init(SDL_INIT_EVERYTHING);

  display = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, flags);

  load_background();
  load_spaceship();

  return 1;
}

void teardown_display() {
  teardown_sprite(ship);

  SDL_FreeSurface(bg1->image);
  free(bg1);
}

void load_spaceship() {
  ship = load_sprite("resources/sprite.png", 48, 48, 0, 0, 3);
  move_sprite(ship, 100, 100);
  first_sprite = create_node(ship);
}

void update_spaceship() {
  i8 tile_size = 48;
  if (pressed_keys->right) {
    ship->clip_rect.y = pressed_keys->up ? tile_size * 3 : tile_size;
  } else if (pressed_keys->left) {
    ship->clip_rect.y = pressed_keys->up ? tile_size * 4 : tile_size * 2;
  } else {
    ship->clip_rect.y = pressed_keys->up ? tile_size * 5 : 0;
  }
}

void load_background() {
  bg1 = malloc(sizeof(background));
  bg1->image = IMG_Load("resources/galaxy.png");
  bg1->rect.x = 0;
  bg1->rect.y = 0;
}

void update_display() {
  sprite_node *current = first_sprite;

  SDL_FillRect(display, NULL, SDL_MapRGB(display->format, 0, 0, 0));
  SDL_BlitSurface(bg1->image, NULL, display, &bg1->rect);

  update_spaceship();

  do {
    update_sprite(current->sprite);
  } while ((current = current->next));

  SDL_Flip(display);
}
