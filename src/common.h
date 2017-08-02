#ifndef H_COMMON
#define H_COMMON

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <SDL.h>
#include <SDL_image.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>

typedef uint_fast8_t u8;
typedef uint_fast16_t u16;
typedef uint_fast32_t u32;
typedef uint_fast64_t u64;

typedef int_fast8_t i8;
typedef int_fast16_t i16;
typedef int_fast32_t i32;
typedef int_fast64_t i64;

SDL_Surface *display;
u32 *frame_count;
#endif
