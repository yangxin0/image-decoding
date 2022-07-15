#include "image_viewer.h"

// void show_raw_image(RawImage *image)
// {
//     SDL_Window *win;
//     SDL_Renderer *renderer;
//     SDL_Surface *surface;
//     SDL_Texture *texture;

//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         fprintf(stderr, "SDL2 init failed\n");
//         exit(-1);
//     }

//     surface = loader(image_path);
//     if (surface == NULL) {
//         fprintf(stderr,"create surface failed\n");
//         return;
//     }
//     win = SDL_CreateWindow(image_path,
//                            SDL_WINDOWPOS_CENTERED,
//                            SDL_WINDOWPOS_CENTERED,
//                            surface->w, surface->h, 0);
//     renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
//     texture = SDL_CreateTextureFromSurface(renderer, surface);
//     SDL_FreeSurface(surface);

//     while (1) {
//         SDL_Event e;

//         if (SDL_PollEvent(&e)) {
//             if (e.type == SDL_QUIT)
//                 break;
//             else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
//                 break;
//         }

//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, texture, NULL, NULL);
//         SDL_RenderPresent(renderer);
//     }

//     SDL_DestroyTexture(texture);
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(win);
// }
