#include "../lib/util.hh"
#include "../lib/game.hh"

void Util::iSDL_SetRenderDrawColor(SDL_Color color)
{
  SDL_SetRenderDrawColor(Game::renderer, color.r, color.g, color.b, color.a);
}