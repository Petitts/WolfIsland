#pragma once
#include <iostream>
#include <ctime>
#include<stdlib.h>
class WolfF
{
private:
	int posx;
	int posy;
	float fat;
public:
	WolfF() :fat(1) {};
	int getX();
	int getY();
	void setPosX(int x);
	void setPosY(int y);
	void move(int** mapa,bool** plot,int rozmiar);
	void porzarcie();
	bool zdychanie();
};

