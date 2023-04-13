#pragma once
#include <SDL_ttf.h>
#include "Game.h"
class TextRender {
private:
	SDL_Surface* textS;
	SDL_Color color;
	const char* text;
	TTF_Font* font;
	SDL_Texture* tex;
	SDL_Rect drect;
	int x;
	int y;
public:
	TextRender(const char* ntekst,int nx,int ny);
	~TextRender();
	void draw();
};