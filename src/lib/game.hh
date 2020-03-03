#pragma once
#include <SDL2/SDL.h>

class Game
{
public:
  Game(const char* title, int x, int y, int w, int h, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void terminate();

  ~Game();

  static SDL_Renderer* renderer;
  static SDL_Event event;
  static bool running;

private:
  SDL_Window* window;
};