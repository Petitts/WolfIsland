#pragma once
#include "TextureManager.h"
#include "Krolik.h"
class Map
{
private:
	SDL_Rect src, dest;
	SDL_Texture* wolfM;
	SDL_Texture* wolfF;
	SDL_Texture* rabbit;
	SDL_Texture* grass;
	SDL_Texture* plot;
	int** mapa;
	int rozmiar;
public:
	Map();
	~Map();
	void LoadMap(int** mapa,int roz);
	void DrawMap(bool** plotT);
};

