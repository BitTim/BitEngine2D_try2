#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "logger.hh"

class Game
{
public:
  Game();

  void init(const char* title, int x, int y, int w, int h, bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void terminate();

  ~Game();

  bool isRunning() { return running; }

  static SDL_Renderer* renderer;
  static SDL_Event event;

private:
  SDL_Window* window;
  bool running = true;
};