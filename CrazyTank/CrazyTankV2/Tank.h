#pragma once
#include <iostream>
#include "Management.h"
#include <vector>


class Bullet {
public:
	char symbol;
	Direction dir;	
	COORD coord;


	Bullet();
	~Bullet();

		void move();
		//void printBoolet();
	
};

class Tank
{
public:
	Move move;	
	char symbol;
	COORD coord;
	//COORD prePos;
	std::vector<Bullet> bulletFlight;
	
	int score;
	int life = 3;


	//Tank(char symbol, char bulletSymbol, Position curPos, Position prePos);

	//void initTank(Tank tank, char symbol, Position nowPos);
	//void printBullet() {
	//	for (int i = 0; i < bulletFlight.size(); i++) {
	//		bulletFlight[i].printBoolet();
	//	}
	//}
	Tank(char symbol, char bulletSymbol, Position curPos, Position prePos);
	Tank() {};
	~Tank();
};