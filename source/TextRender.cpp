#include "TextRender.h"

TextRender::TextRender(const char* ntekst,int nx,int ny):text(ntekst),x(nx),y(ny)
{
	font = TTF_OpenFont("OpenSans-Regular.ttf",10);
	color = {0,0,0};
	textS = TTF_RenderText_Solid(font, text, color);
	tex = SDL_CreateTextureFromSurface(Game::renderer, textS);
	drect.x = x;
	drect.y = y;
	drect.w = 130;
	drect.h = 60;
	SDL_FreeSurface(textS);
}

TextRender::~TextRender() {
	TTF_CloseFont(font);
	SDL_DestroyTexture(tex);
}

void TextRender::draw() {
	SDL_RenderCopy(Game::renderer, tex, NULL, &drect);
}