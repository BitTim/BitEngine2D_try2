#include "../lib/game.hh"

SDL_Renderer* Game::renderer;
SDL_Event Game::event;

Game::Game() { }

void Game::init(const char* title, int x, int y, int w, int h, bool fullscreen)
{
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow(title, x, y, w, h, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
}

void Game::handleEvents()
{
  SDL_WaitEvent(&event);
  if(event.type == SDL_QUIT) running = false;
}

void Game::update()
{

}

void Game::render()
{
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(renderer);

  SDL_Rect sample = {10, 10, 150, 150};
  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(renderer, &sample);

  SDL_RenderPresent(renderer);
}

void Game::terminate()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

Game::~Game() { }