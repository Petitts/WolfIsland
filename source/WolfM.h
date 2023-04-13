#pragma once
#include <iostream>
#include <ctime>
#include<stdlib.h>
class WolfM
{
private:
	int posx;
	int posy;
	float fat;
	int rozm;
	
public:
	WolfM() :fat(1), rozm(0) {};
	int getX();
	int getY();
	void setPosX(int x);
	void setPosY(int y);
	void move(int** mapa,bool** plot,int rozmiar);
	void porzarcie();
	bool zdychanie();
	int getRozm();
	void setRozm(int x);
};

