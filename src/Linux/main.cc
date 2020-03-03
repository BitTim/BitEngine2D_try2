#include <iostream>
#include <SDL2/SDL.h>

#include "../lib/game.hh"

Game* game;

int main()
{
  game = new Game("Bit Engine 2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, false);

  while(Game::running)
  {
    game->handleEvents();
    game->update();
    game->render();
  }

  game->terminate();
  return 0;
}