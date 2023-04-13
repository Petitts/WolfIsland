#include "WolfF.h"

int WolfF::getX() {
	return posx;
}

int WolfF::getY() {
	return posy;
}

void WolfF::setPosX(int x) {
	posx = x;
}

void WolfF::setPosY(int y) {
	posy = y;
}


void WolfF::move(int** mapa, bool** plot,int rozmiar) {
	//int g;
	//if (plot) {
	//	g = 15;
	//}
	//else {
	//	g = 20;
	//}
	//poscig za krolikiem



	if (this->getX() != rozmiar-1) {
		if (mapa[this->getX() + 1][this->getY()] == 3 && !plot[posx+1][posy]) {
			posx = this->getX() + 1;
			return;
		}
	}
	if (this->getY() != rozmiar - 1) {
		if (mapa[this->getX()][this->getY() + 1] == 3 && !plot[posx][posy+1]) {
			posy = this->getY() + 1;
			fat -= 0.1;
			return;
		}
	}
	if (this->getX() != rozmiar - 1 && this->getY() != rozmiar - 1) {
		if (mapa[this->getX() + 1][this->getY() + 1] == 3 && !plot[posx + 1][posy+1]) {
			posx = this->getX() + 1;
			posy = this->getY() + 1;
			fat -= 0.1;
			return;
		}
	}
	if (this->getY() != 0 && this->getX() != 0) {
		if (mapa[this->getX() - 1][this->getY() - 1] == 3 && !plot[posx -1][posy-1]) {
			posx = this->getX() - 1;
			posy = this->getY() - 1;
			fat -= 0.1;
			return;
		}
	}
	if (this->getX() != 0) {
		if (mapa[this->getX() - 1][this->getY()] == 3 && !plot[posx - 1][posy]) {
			posx = this->getX() - 1;
			fat -= 0.1;
			return;
		}
	}
	if (this->getY() != 0) {
		if (mapa[this->getX()][this->getY() - 1] == 3 && !plot[posx][posy-1]) {
			posy = this->getY() - 1;
			fat -= 0.1;
			return;
		}
	}
	if (this->getX() != rozmiar - 1 && this->getY() != 0) {
		if (mapa[this->getX() + 1][this->getY() - 1] == 3 && !plot[posx + 1][posy-1]) {
			posx = this->getX() + 1;
			posy = this->getY() - 1;
			fat -= 0.1;
			return;
		}
	}
	if (this->getY() != rozmiar - 1 && this->getX() != 0) {
		if (mapa[this->getX() - 1][this->getY() + 1] == 3 && !plot[posx - 1][posy+1]) {
			posx = this->getX() - 1;
			posy = this->getY() + 1;
			fat -= 0.1;
			return;
		}
	}
	//zwyk³y ruch
	if (posx == rozmiar - 1) {
		do {
			posx += rand() % 2 - 1;
		} while (plot[posx][posy]);
		fat -= 0.1;
	}
	else if (posx <= 0) {
		do {
			posx += rand() % 2;
		} while (plot[posx][posy]);
		fat -= 0.1;
	}
	else {
		do{
		posx += rand() % 3 - 1;
		} while (plot[posx][posy]);
		fat -= 0.1;
	}

	if (posy == rozmiar - 1) {
		do{
		posy += rand() % 2 - 1;
		} while (plot[posx][posy]);
		fat -= 0.1;
	}
	else if (posy <= 0) {
		do{
		posy += rand() % 2;
		} while (plot[posx][posy]);
		fat -= 0.1;
	}
	else {
		do{
		posy += rand() % 3 - 1;
		} while (plot[posx][posy]);
		fat -= 0.1;
	}
}

void WolfF::porzarcie() {
	fat += 1;
}
bool WolfF::zdychanie() {
	
	if (fat <= 0) {
		return true;
	}
	else {
		return false;
	}
}