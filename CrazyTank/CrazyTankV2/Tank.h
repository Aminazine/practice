#pragma once
#include "Management.h"

class Bullet {
public:
	char symbol;
	bool visibleBoolet;

	Bullet() {
		visibleBoolet = false;
	}

	void move();
	void checkForCrash();
	bool checkForHit();
	void setVisibleBoolet() {
		visibleBoolet = true;
	}
	void refreshBoolet();
	void printBoolet() {
		
	}
};


class Tank
{
public:
	Move move;
	char symbol;
	COORD coord;

	Tank();
	~Tank();
};

