#include <iostream>
#include <SDL2/SDL.h>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

bool running = true;

void init()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("Bit Engine 2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
}

void terminate()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void update()
{
  SDL_WaitEvent(&event);
  if(event.type == SDL_QUIT) running = false;
}

void draw()
{
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(renderer);

  SDL_Rect sample = {10, 10, 150, 150};
  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(renderer, &sample);

  SDL_RenderPresent(renderer);
}

int main()
{
  init();

  while(running)
  {
    update();
    draw();
  }

  terminate;

  return 0;
}