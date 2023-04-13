#include "Game.h"
SDL_Renderer* Game::renderer = nullptr;

Game::Game():rozmiar(25), m_wolfF(0), m_wolfM(0), m_rabbit(0), startClick(false), zywoplot(true), firstStart(false) {};

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	if (TTF_Init() == -1)
	{
		isRunning = false;
	}
	srand(time(0));
	mapa = getMap();
	initZywoplot();
}

void Game::update() {
	if (startClick == false) {
		render();
		return;
	}

	ruchWM(mapa);
	ruchWF(mapa);
	ruchK(mapa);
	rozmnarzanieK(mapa);
	if (m_wolfM == 0 && m_wolfF == 0 && m_rabbit == 0) {
		startClick = false;
		firstStart = false;
		//rozmiar = 25;
	}
}

void Game::render() {
	SDL_RenderClear(renderer);
	Map m;
	Button start("b_start.png", "b_start_hover.png",60,60, 0, 640, startClick), wm_plus("b_plus.png","b_plus_block.png",60,30, 60, 640, firstStart), wm_minus("b_minus.png","b_minus_block.png",60,30, 60, 670, firstStart), wf_plus("b_plus.png", "b_plus_block.png",60,30, 250, 640, firstStart), wf_minus("b_minus.png", "b_minus_block.png",60,30, 250, 670, firstStart), r_plus("b_plus.png", "b_plus_block.png", 60,30,460, 640, firstStart), r_minus("b_minus.png", "b_minus_block.png", 60,30,460, 670, firstStart),b_plot("b_plot_f.png","b_plot_t.png",60,60,0,700, zywoplot), rozm_plus("b_plus.png", "b_plus_block.png", 60, 30, 250, 700, firstStart), rozm_minus("b_minus.png", "b_minus_block.png", 60, 30, 250, 730, firstStart);
	TextRender wilk_text(cwilki().c_str(), 120, 640), wilczyca_text(cwilczyce().c_str(), 330, 640), kroliki_text(ckroliki().c_str(), 520, 640),plot_text("Zywoplot",60,700),rozm_text(crozmiar().c_str(), 310, 700);
	start.draw();

	m.LoadMap(mapa,rozmiar);
	m.DrawMap(zywoplotTable);
	start.draw();
	wm_plus.draw();
	wm_minus.draw();
	wilk_text.draw();
	wf_plus.draw();
	wf_minus.draw();
	wilczyca_text.draw();
	r_plus.draw();
	r_minus.draw();
	kroliki_text.draw();
	b_plot.draw();
	plot_text.draw();
	rozm_plus.draw();
	rozm_minus.draw();
	rozm_text.draw();
	SDL_RenderPresent(renderer);
}

void Game::handleEvent() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		int x, y;
		SDL_GetMouseState(&x, &y);
		if (x > 0 && x<60) //Start
		{
			if (y > 640 && y < 700) {
				if (startClick == false && (m_wolfM > 0 || m_wolfF > 0 || m_rabbit > 0)) {
					if (firstStart==false ) {
						mapa = getMap();
						firstStart = true;
					}
					startClick = true;
				}
				else {
					startClick = false;
				}
			}
		}
		if (x>60&&x<120&&y>640&&y<670&&startClick==false&&firstStart==false)//plus wilk
		{
			m_wolfM++;
		}
		if (x > 60 && x < 120 && y>670 && y < 700&&startClick==false && firstStart == false)//minus wilk
		{
			if (m_wolfM > 0)
			{
				m_wolfM--;
			}
		}
		if (x > 250 && x < 310 && y>640 && y < 670 && startClick == false && firstStart == false)//plus wilczyca
		{
			m_wolfF++;

		}
		if (x > 250 && x < 310 && y>670 && y < 700 && startClick == false && firstStart == false)//minus wilczyca
		{
			if (m_wolfF > 0)
			{
				m_wolfF--;
			}
		}
		if (x > 460 && x < 520 && y>640 && y < 670 && startClick == false && firstStart == false)//plus krolik
		{
			m_rabbit++;
		}
		if (x > 460 && x < 520 && y>670 && y < 700 && startClick == false && firstStart == false)//minus krolik
		{
			if (m_rabbit > 0)
			{
				m_rabbit--;
			}
		}
		if (x > 0 &&x<60 && y>700 && y<760 && firstStart==false)//zywoplot
		{
			if (zywoplot) {
				zywoplot = false;
			}
			else {
				zywoplot = true;
			}
		}
		if (x > 250 && x < 310 && y>700 && y < 730 && startClick == false && firstStart == false)//plus rozmiar
		{
			if (rozmiar < 25)
			{
				rozmiar++;
				delete[] zywoplotTable;
				mapa = getMap();
				initZywoplot();
			}
				
		}
		if (x > 250 && x < 310 && y>730 && y < 760 && startClick == false && firstStart == false)//minus rozmiar
		{
			if (rozmiar > 10)
			{
				rozmiar--;
				delete[] zywoplotTable;
				mapa = getMap();
				initZywoplot();
				
			}
		}
		if (x < 640 && y < 640 && zywoplot) {
			int zx, zy;
			zx = x / (640 / rozmiar);
			zy = y /(640 / rozmiar);
			if (zywoplotTable[zy][zx]) {
				zywoplotTable[zy][zx] = false;
			}
			else {
				zywoplotTable[zy][zx] = true;
			}
		}
	}

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


int** Game::getMap() {
	//int g;
	//if (zywoplot) {
	//	g = 15;
	//}
	//else {
	//	g = 20;
	//}

	int wolfM = m_wolfM;
	int wolfF = m_wolfF;
	int rabbit = m_rabbit;
	int** map;
	map = new int* [rozmiar];
	int losh, losw;
	for (int h = 0; h < rozmiar; h++) {
		map[h] = new int[rozmiar];
		for (int w = 0; w < rozmiar; w++) {
			map[h][w] = 0;
		}
	}
	for (int i = 0; i < wolfM; i++) {
		do {
			losh = rand() % rozmiar;
			losw = rand() % rozmiar;
		} while (zywoplotTable[losh][losw]);
		map[losh][losw] = 1;
		WolfM* nowy = new WolfM;
		nowy->setPosX(losh);
		nowy->setPosY(losw);
		wilki.push_back(*nowy);
	}
	for (int i = 0; i < wolfF; i++) {
		do {
			losh = rand() % rozmiar;
			losw = rand() % rozmiar;
		} while (zywoplotTable[losh][losw]);
		map[losh][losw] = 2;
		WolfF* nowy = new WolfF;
		nowy->setPosX(losh);
		nowy->setPosY(losw);
		wilczyce.push_back(*nowy);;
	}
	for (int i = 0; i < rabbit; i++) {
		losh = rand() % rozmiar;
		losw = rand() % rozmiar;
		map[losh][losw] = 3;
		Krolik* nowy = new Krolik;
		nowy->setPosX(losh);
		nowy->setPosY(losw);
		kroliki.push_back(*nowy);
	}
	return map;
}

void Game::ruchK(int** mapa) {
	int powrotX;
	int powrotY;
	for (auto ik = begin(kroliki); ik != end(kroliki); ++ik) {
		powrotX = ik->getX();
		powrotY = ik->getY();
		mapa[ik->getX()][ik->getY()] = 0;
		ik->move(rozmiar);
		if (mapa[ik->getX()][ik->getY()] != 0) {
			ik->setPosX(powrotX);
			ik->setPosY(powrotY);
		}
		mapa[ik->getX()][ik->getY()] = 3;
		render();
		handleEvent();
	}
}

void Game::ruchWF(int** mapa) {
	int powrotX;
	int powrotY;
	for (auto i = begin(wilczyce); i != end(wilczyce);) {
		powrotX = i->getX();
		powrotY = i->getY();
		mapa[i->getX()][i->getY()] = 0;
		i->move(mapa,zywoplotTable,rozmiar);
		if (mapa[i->getX()][i->getY()] == 2) {
			i->setPosX(powrotX);
			i->setPosY(powrotY);
			mapa[i->getX()][i->getY()] = 2;
			i++;
			continue;
		}
		//zjadadnie krolikow
		if (mapa[i->getX()][i->getY()] == 3) {
			int posx = i->getX();
			int posy = i->getY();
			int licz = 0;
			for (int j = 0; j < kroliki.size(); j++) {
				if (kroliki[j].getX() == posx && kroliki[j].getY() == posy) {
					i->porzarcie();
					kroliki[j] = kroliki.back();
					kroliki.pop_back();
					m_rabbit--;
				}
			}
		}
		mapa[i->getX()][i->getY()] = 2;
		//zdychanie
		if (i->zdychanie()) {
			mapa[i->getX()][i->getY()] = 0;
			i = wilczyce.erase(i);
			m_wolfF--;
		}
		else {
			++i;
		}
		render();
		handleEvent();
	}
}

void Game::ruchWM(int** mapa) {
	int powrotX;
	int powrotY;
	for (auto i = begin(wilki); i != end(wilki);) {
		powrotX = i->getX();
		powrotY = i->getY();
		mapa[i->getX()][i->getY()] = 0;
		i->move(mapa, zywoplotTable,rozmiar);
		if (mapa[i->getX()][i->getY()] == 1 || zywoplotTable[i->getY()][i->getX()]) {
			i->setPosX(powrotX);
			i->setPosY(powrotY);
			mapa[i->getX()][i->getY()] = 1;
			i++;
			continue;
		}
		//zjadanie krolikow
		if (mapa[i->getX()][i->getY()] == 3) {
			int posx = i->getX();
			int posy = i->getY();
			int licz = 0;
			std::vector<int> zabiteM;
			for (int j = 0; j < kroliki.size(); j++) {
				if (kroliki[j].getX() == posx && kroliki[j].getY() == posy) {
					zabiteM.push_back(j);
					i->porzarcie();
					kroliki[j]=kroliki.back();
					kroliki.pop_back();
					m_rabbit--;
				}
			}
		}
		//zdychanie
		if (i->zdychanie()) {
			mapa[i->getX()][i->getY()] = 0;
			i = wilki.erase(i);
			m_wolfM--;
			continue;
		}
		//rozmnazanie
		if (mapa[i->getX()][i->getY()] == 2 && i->getRozm()==0) {
			int plec;
			plec=rozmnarzanieW(mapa, i->getX(), i->getY());
			i->setRozm(1);
		}
		else if(i->getRozm()>0) {
			i->setRozm((i->getRozm())-1);
		}

		if (i->getX() > 0 && i->getY() > 0) {
			mapa[i->getX()][i->getY()] = 1;
		}
		
		i++;

		render();
		handleEvent();
	}
	//dodanie nowych wilkow
	wilki.insert(wilki.end(), doDodania.begin(), doDodania.end());
	doDodania.clear();

}

void Game::rozmnarzanieK(int** mapa) {
	int rozmn;
	int ilosc = kroliki.size();
	for (int i = 0; i < ilosc;i++) {
		int x = kroliki[i].getX();
		int y = kroliki[i].getY();
		//if (m_rabbit < 300)
		//{
			if (x != 0 && x != rozmiar-1 && y != 0 && y != rozmiar-1)
			{
				if (!(mapa[x + 1][y] == 3 && mapa[x - 1][y] == 3 && mapa[x][y + 1] == 3 && mapa[x][y - 1] == 3 && mapa[x + 1][y + 1] == 3 && mapa[x + 1][y - 1] == 3 && mapa[x - 1][y + 1] == 3 && mapa[x - 1][y - 1] == 3)) {
					rozmn = rand() % 10;
					if (rozmn == 4 || rozmn == 2) {
						kroliki.push_back(kroliki[i].rozmnazanie());
						m_rabbit++;
					}
				}
			}
		//}

	}
}

int Game::rozmnarzanieW(int** mapa, int x,int y) {
	
	int plec = rand() % 2;
	if (plec == 1) {
		WolfM nowy;
		nowy.setPosX(x);
		nowy.setPosY(y);
		doDodania.push_back(nowy);
		m_wolfM++;
		return 1;
	}
	else {
		WolfF nowy;
		nowy.setPosX(x);
		nowy.setPosY(y);
		wilczyce.push_back(nowy);
		m_wolfF++;
		return 0;
	}
}

std::string Game::cwilki() {
	std::string wynik= "Wilki: ";
	char liczba[4];
	_itoa(m_wolfM, liczba, 10);
	wynik += liczba;
	return wynik;
}
std::string Game::cwilczyce() {
	std::string wynik = "Wilczyce: ";
	char liczba[4];
	_itoa(m_wolfF, liczba, 10);
	wynik += liczba;
	return wynik;
}
std::string Game::ckroliki() {
	std::string wynik = "Kroliki: ";
	char liczba[4];
	_itoa(m_rabbit, liczba, 10);
	wynik += liczba;
	return wynik;
}
std::string Game::crozmiar() {
	std::string wynik = "Rozmiar planszy ";
	char liczba[4];
	_itoa(rozmiar, liczba, 10);
	wynik += liczba;
	return wynik;
}


void Game::initZywoplot() {
	zywoplotTable = new bool* [rozmiar];
	int losh, losw;
	for (int h = 0; h < rozmiar; h++) {
		zywoplotTable[h] = new bool[rozmiar];
		for (int w = 0; w < rozmiar; w++) {
			zywoplotTable[h][w] = 0;
		}
	}
}

