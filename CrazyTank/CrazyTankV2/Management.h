#pragma once

#include <Windows.h>

class Init
{
public:
	int player_no;
	char playerSymbol;
	char enemyStmbol;
	char booletSymbol;
};

class Move
{
public:
	enum eMovement { STOP = 0, UP, DOWN, LEFT, RIGHT };
	eMovement move;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool gameOver;

	void Control() {
		int key = _getch();

		if (key == 224) {
			key = _getch();
			if (key == 72) {
				move = UP;
				return;
			}
			if (key == 80) {
				move = DOWN;
				return;
			}
			if (key == 75) {
				move = LEFT;
				return;
			}
			if (key == 77) {
				move = RIGHT;
				return;
			}
			if (key == 113) {
				gameOver = true;
				return;
			}
		}
	}
};

class Position
{
public:
	int playerX, playerY, enemyX, enemyY;
	COORD position;

}



};