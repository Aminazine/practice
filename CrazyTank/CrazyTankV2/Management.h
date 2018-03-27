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
public:
	int X, Y;
};



