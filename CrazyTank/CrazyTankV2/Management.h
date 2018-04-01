#pragma once

#include <Windows.h>
#include <conio.h>

enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };

class Move
{
public:	
	Direction move;
	Direction control();
	
};

class Position
{
	int x, y;
public:
	void SetXY(int tx, int ty) {
		x = tx;
		y = ty;
	}
	int& GetX() { return x; }
	int& GetY() { return y; }
	bool MoveUp() {
		if (y == 0)return false;
		y--;
		return true;
	}
	bool MoveDown() {
		if (y == 49)return false;
		y++;
		return true;
	}
	bool MoveLeft() {
		if (x == 0)return false;
		x--;
		return true;
	}
	bool MoveRight() {
		if (x == 49)return false;
		x++;
		return true;
	}
};



