#include "../lib/game.hh"

SDL_Renderer* Game::renderer;
SDL_Event Game::event;

Game::Game() { }

void Game::init(const char* title, int x, int y, int w, int h, bool fullscreen)
{
  Logger::initLogPath();
  Logger::log("init", "Initialized LogPath");

  SDL_Init(SDL_INIT_EVERYTHING);
  Logger::log("init", "Initialized SDL");

  window = SDL_CreateWindow(title, x, y, w, h, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
  Logger::log("init", "Creatde Window");
  renderer = SDL_CreateRenderer(window, -1, 0);
  Logger::log("init", "Created Renderer");
}

void Game::handleEvents()
{
  SDL_WaitEvent(&event);
  Logger::log("handleEvents", "Received Event");
  if(event.type == SDL_QUIT)
  {
    Logger::log("handleEvents", "-> Received event was SDL_QUIT");
    running = false;
  }
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
  Logger::log("terminate", "Destroyed Renderer");
  SDL_DestroyWindow(window);
  Logger::log("terminate", "Destroyed Window");

  SDL_Quit();
  Logger::log("terminate", "Quitted SDL");
}

Game::~Game() { }