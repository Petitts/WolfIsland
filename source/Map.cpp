#include "Map.h"



Map::Map() {
	wolfM = TextureManager::LoadTexture("wolfM.png");
	wolfF = TextureManager::LoadTexture("wolfF.png");
	rabbit = TextureManager::LoadTexture("rabbit.png");
	grass = TextureManager::LoadTexture("grass.png");
	plot = TextureManager::LoadTexture("plot.png");
	src.y = src.x = 0;
	dest.x = dest.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
};
Map::~Map() {
	for (int h = 0; h < rozmiar; h++) // loop variable wasn't declared
	{
		delete[] mapa[h];
	}
	delete[] mapa;
	mapa = 0;
	SDL_DestroyTexture(wolfM);
	SDL_DestroyTexture(wolfF);
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(rabbit);
	SDL_DestroyTexture(plot);
}

void Map::LoadMap(int** arr,int roz) {
	rozmiar = roz;
	mapa = new int* [rozmiar];
	for (int row = 0; row < rozmiar; row++) {
		mapa[row] = new int[rozmiar];
		for (int column = 0; column < rozmiar; column++) {
			mapa[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap(bool** plotT) {
	int type = 0;
	int kratka = 640 / rozmiar;
	for (int row = 0; row < rozmiar; row++) {
		for (int column = 0; column < rozmiar; column++) {
			type = mapa[row][column];
			dest.w = dest.h = kratka;
			dest.x = column * kratka;
			dest.y = row * kratka;

			switch (type) {
			case 0:
				if (plotT[row][column]) {
					TextureManager::Draw(plot, src, dest);
				}
				else {
					TextureManager::Draw(grass, src, dest);
				}
				break;
			case 1:
				TextureManager::Draw(wolfM, src, dest);
				break;
			case 2:
				TextureManager::Draw(wolfF, src, dest);
				break;
			case 3:
				TextureManager::Draw(rabbit, src, dest);
				break;
			default:
				break;
			}
		}
	}
}