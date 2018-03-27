#pragma once
#include "Tank.h"



class BatleField
{
private:
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	const int width = 20;
	const int height = 20;
	char boarderSymbol = '@';
	char wallSymbol = '#';
	char ** map;
	Tank player;
	Tank * enemy;
	int enemyCount = 5;

public:

	BatleField();
	~BatleField();
	void printScores();
	void printLife();
	void setBoarder();
//	void setBase(Base base, int X, int Y);
	void setPlayer();
	void setEnemy();
	void tankMove(Tank & tank, Direction  dir);
	void enemyMove();
	void playerMove();
	void clearTank(Tank tank);
	void printTank(Tank tank, int X, int Y);
	void generateWalls();
	
};