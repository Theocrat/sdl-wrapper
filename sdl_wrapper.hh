#include <SDL.h>
#include <stdexcept>

namespace sdlw {
    class  SDLWindow {
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
        bool running;

        char *title;
        int height;
        int width;
        
        public:

        SDLWindow(int height, int width, std::string title="SDL Window") {
            this->height = height;
            this->width = width;
            this->title = (char *) title.c_str();

            if (SDL_Init(SDL_INIT_VIDEO) != 0) {
                SDL_Log("SDL_Init Error: %s", SDL_GetError());
                throw std::runtime_error("Cannot initialize SDL.");
            }

            this->window = SDL_CreateWindow(
                this->title,
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, 
                this->width, 
                this->height, 
                SDL_WINDOW_SHOWN
            );

            if (!this->window) {
                SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
                SDL_Quit();
                throw std::runtime_error("Cannot initialize SDL window.");
            }

            this->renderer = SDL_CreateRenderer(window, -1,
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if (!this->renderer) {
                SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
                SDL_DestroyWindow(window);
                SDL_Quit();
                throw std::runtime_error("Cannot initialize SDL renderer.");
            }

            this->running = true;
        }

        ~SDLWindow() {
            SDL_DestroyRenderer(this->renderer);
            SDL_DestroyWindow(this->window);
            SDL_Quit();
        }

        bool isRunning() {
            while (SDL_PollEvent(&(this->event))) {
                if (this->event.type == SDL_QUIT) {
                    this->running = false;
                }
            }
            return this->running;
        }

        void setColor(int red, int green, int blue, int alpha=255) {
            SDL_SetRenderDrawColor(this->renderer, red, green, blue, alpha);
        }
            
        void clear() {
            SDL_RenderClear(this->renderer);
        }

        void drawPoint(int x, int y) {
            SDL_RenderDrawPoint(this->renderer, x, y);
        }

        void render() {
            SDL_RenderPresent(this->renderer);
        }
    };
}