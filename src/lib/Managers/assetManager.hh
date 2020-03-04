#pragma once
#include <map>
#include <SDL2/SDL_ttf.h>

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

  //Color Management
  void addColor(std::string id, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  SDL_Color getColor(std::string id);

private:
  std::map<std::string, SDL_Texture*> textures;
  std::map<std::string, TTF_Font*> fonts;
  std::map<std::string, SDL_Color> colors;
};
