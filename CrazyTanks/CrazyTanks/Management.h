#pragma once

class ID {
	int get_id;
	char tank_symbl;
	char player_symbl;
};

class Direct
{
public:
	int x, y;
	
	Direct();
	Direct(int x, int y);
	Direct(int);
	

};

class Movement
{
public:
	Direct dir;

	Movement();
	Movement(int);


};

class Position 
{
public:
	int x, y;

	Position();
	Position(int x, int y);
};



