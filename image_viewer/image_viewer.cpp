#include <SDL.h>
#include <SDL_image.h>
#include <cstring>
#include "image_viewer.h"


void rendering_init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL2: init failed\n");
        exit(-1);
    }
}


int rendering_image(const char *caption, RawImage *img)
{
    SDL_Window *win;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;

    if (img->type == IMG_BGR24) {
        // reverse RGB
        surface = SDL_CreateRGBSurface(SDL_SWSURFACE, img->width, img->height, 24,
                                     B, G, R, 0);
    } else {
        // RGB
        surface = SDL_CreateRGBSurface(SDL_SWSURFACE, img->width, img->height, 24,
                                     R, G, B, 0);
    }
    memcpy(surface->pixels, img->blob.get(), img->size);

    if (surface == NULL) {
        fprintf(stderr,"SDL2: create surface failed\n");
        return IMG_ERR;
    }

    win = SDL_CreateWindow(caption, SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED, surface->w, surface->h, 0);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    while (1) {
        SDL_Event e;

        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                break;
            else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
                break;
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    return IMG_OK;
}
