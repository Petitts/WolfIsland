#pragma once

#include "TextureManager.h"
class Button
{
private:
	SDL_Texture* tex;
	SDL_Texture* atex;
	SDL_Rect srect,drect;
	bool isSelected = false;
	const char* file;
	const char* afile;
	int x;
	int y;
	
public:
	Button(const char* nfile, const char* nafile, int w, int h, int nx, int ny, bool stan);
	~Button();
	void draw();
};

