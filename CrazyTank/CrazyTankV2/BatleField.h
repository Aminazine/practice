#pragma once
#include "Tank.h"


class BatleField
{
private:
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	const int width = 20;
	const int height = 20;
	char wallSymbol = '@';
	char ** map;
	Tank player;
	Tank * enemy;
public:

	BatleField();
	~BatleField();
	void setBoarder();
	void setTank();
	void setGold();
	void playerMove();
	void clearTank(Tank tank);
	void printTank(Tank tank,int X,int Y);
	void generateWalls();
};

