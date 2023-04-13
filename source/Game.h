#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include "TextureManager.h"
#include "Map.h"
#include "Krolik.h"
#include "WolfF.h"
#include "WolfM.h"
#include "Button.h"
#include "TextRender.h"
class Game
{
private:
	int rozmiar;
	bool startClick;
	bool zywoplot;
	bool isRunning;
	SDL_Window* window;
	int** mapa;
	bool firstStart;
	int m_wolfM;
	int m_wolfF;
	int m_rabbit;
	std::vector<Krolik> kroliki;
	std::vector<WolfF> wilczyce;
	std::vector<WolfM> wilki;
	std::vector<WolfM> doDodania;
	bool** zywoplotTable;

	std::string cwilki();
	std::string cwilczyce();
	std::string ckroliki();
	std::string crozmiar();
	void render();
	int** getMap();
	void ruchK(int** mapa);
	void ruchWF(int** mapa);
	void ruchWM(int** mapa);
	void rozmnarzanieK(int** mapa);
	int rozmnarzanieW(int** mapa, int x, int y);
	void insertZywoplot();
	void initZywoplot();
public:
	Game();
	static SDL_Renderer* renderer;
	void clean();
	void update();
	void handleEvent();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	bool running() { return isRunning; };
};

