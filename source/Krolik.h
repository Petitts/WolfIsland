#pragma once
#include <iostream>
class Krolik
{
private:
	int posx=0;
	int posy=0;

public:
	int getX();
	int getY();
	void setPosX(int x);
	void setPosY(int y);
	void move(int roz);
	Krolik rozmnazanie();
};