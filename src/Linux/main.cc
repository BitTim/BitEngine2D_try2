#include <iostream>
#include <SDL2/SDL.h>

#include "../lib/game.hh"

Game* game = nullptr;

const int targetFPS = 60;
const int targetFrameDelay = 1000 / targetFPS;
Uint32 frameStart;
int frameTime;

int main()
{
  game = new Game();
  game->init("Bit Engine 2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, false);

  while(game->isRunning())
  {
    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;
    if(targetFrameDelay > frameTime) SDL_Delay(targetFrameDelay - frameTime);
  }

  game->terminate();
  return 0;
}