#define SDL_MAIN_HANDLED
#include <SDL.h>

auto main() -> int {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 100, 200, SDL_ALPHA_OPAQUE);
    while (true) {
        SDL_Event event;
        auto should_close = false;
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
            case SDL_QUIT: should_close = true; break;
            }
        }
        if (should_close) {
            break;
        }
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
