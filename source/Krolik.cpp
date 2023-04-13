#include "Krolik.h"

int Krolik::getX() {
	return posx;
}

int Krolik::getY() {
	return posy;
}

void Krolik::setPosX(int x) {
	posx = x;
}

void Krolik::setPosY(int y) {
	posy = y;
}

void Krolik::move(int roz) {
	if (posx == roz-1) {
		posx += rand() % 2 - 1;
	}
	else if (posx == 0) {
		posx += rand() % 2;
	}
	else {
		posx += rand() % 3 - 1;
	}

	if (posy == roz-1) {
		posy += rand() % 2 - 1;
	}
	else if (posy == 0) {
		posy += rand() % 2;
	}
	else {
		posy += rand() % 3 - 1;
	}
}

Krolik Krolik::rozmnazanie() {
	Krolik nowy;
	nowy.setPosX(this->getX());
	nowy.setPosY(this->getY());
	return nowy;
}