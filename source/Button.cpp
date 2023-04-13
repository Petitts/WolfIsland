#include "Button.h"
Button::Button(const char* nfile, const char* nafile,int w, int h,int nx,int ny,bool stan):file(nfile),afile(nafile), x(nx), y(ny), isSelected(stan)
{
	tex = TextureManager::LoadTexture(file);
	atex= TextureManager::LoadTexture(afile);
	srect.x = srect.y = 0;
	drect.x = x;
	drect.y = y;
	srect.w = drect.w = w;
	srect.h = drect.h = h;

	
}

Button::~Button() {
	SDL_DestroyTexture(tex);
	SDL_DestroyTexture(atex);
}

void Button::draw() {
	if(isSelected==false)
		TextureManager::Draw(tex, srect, drect);
	else {
		TextureManager::Draw(atex, srect, drect);
	}
	SDL_DestroyTexture(tex);
	SDL_DestroyTexture(atex);
}