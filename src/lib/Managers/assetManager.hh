#pragma once
#include <map>

#include "../game.hh"
#include "textureManager.hh"

class AssetManager
{
public:
  AssetManager() { }
  ~AssetManager() { }

  //Texture Management
  void addTexture(std::string id, std::string path);
  SDL_Texture* getTexture(std::string id);

  //Font Management
  void addFont(std::string id, std::string path, int fontSize);
  TTF_Font* getFont(std::string id);

private:
  std::map<std::string, SDL_Texture*> textures;
  std::map<std::string, TTF_Font*> fonts;
  std::map<std::string, SDL_Color> colors;
};
