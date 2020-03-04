#include "../../lib/Managers/assetManager.hh"
#include "../../lib/Managers/textureManager.hh"

//Texture Management
void AssetManager::addTexture(std::string id, std::string path)
{
  textures.emplace(id, TextureManager::loadTexture(path));
  Logger::log("addTexture", "Loaded Texture");
}

SDL_Texture* AssetManager::getTexture(std::string id) { return textures[id]; }

//Font Management
void AssetManager::addFont(std::string id, std::string path, int fontSize)
{
  fonts.emplace(id, TTF_OpenFont(path.c_str(), fontSize));
  Logger::log("addFont", "Loaded Font");
}

TTF_Font* AssetManager::getFont(std::string id) { return fonts[id]; }

//Color Management
void AssetManager::addColor(std::string id, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  SDL_Color color = {r, g, b, a};
  colors.emplace(id, color);
  Logger::log("addColor", "Created color");
}

SDL_Color AssetManager::getColor(std::string id) { return colors[id]; }