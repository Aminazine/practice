#pragma once

#include <Windows.h>
#include <conio.h>
enum eMovement { STOP = 0, UP, DOWN, LEFT, RIGHT };

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
	
	eMovement move;
	
	bool gameOver;

	eMovement Control() {
		int key = _getch();

		if (key == 224) {
			key = _getch();
			if (key == 72) {
				move = UP;
				return move;
			}
			if (key == 80) {
				move = DOWN;
				return move;
			}
			if (key == 75) {
				move = LEFT;
				return move;
			}
			if (key == 77) {
				move = RIGHT;
				return move;
			}
			if (key == 113) {
				gameOver = true;
				return move;
			}
		}
	}
};

class Position
{
public:
	int playerX, playerY, enemyX, enemyY;
	COORD position;

};



