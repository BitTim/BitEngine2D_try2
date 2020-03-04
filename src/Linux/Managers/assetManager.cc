#include "../../lib/Managers/assetManager.hh"

void AssetManager::addTexture(std::string id, std::string path)
{ textures.emplace(id, TextureManager::loadTexture(path)); }

SDL_Texture* AssetManager::getTexture(std::string id) { return textures[id]; }

void AssetManager::addFont(std::string id, std::string path, int fontSize)
{ fonts.emplace(id, TTF_OpenFont(path.c_str(), fontSize)); }

TTF_Font* AssetManager::getFont(std::string id) { return fonts[id]; }