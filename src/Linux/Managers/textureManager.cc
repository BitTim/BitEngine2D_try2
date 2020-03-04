#include "../../lib/Managers/textureManager.hh"

SDL_Texture* TextureManager::loadTexture(const char* path)
{
  SDL_Surface* surface = IMG_Load(path);
  Logger::log("loadTexture", "Loaded image into surface");
  SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
  Logger::log("loadTexture", "Converted Surface to Texture");

  SDL_FreeSurface(surface);
  Logger::log("loadTexture", "Freed up surface");

  return texture;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip)
{
  SDL_RenderCopyEx(Game::renderer, tex, &src, &dst, 0, NULL, flip);
  Logger::log("draw", "Renderered texture");
}