#include "stdafx.h"
#include "BtlField.h"


Field::Field()
{

}

void Field::set_objects()
{
	char symbl;

	for (int i = 0; i < width - 1; i++) {
		for (int j = 0; j < height - 1; j++) {
			if (symbl == 'P') {
				this->Player = Position(i, j);
			}
			if (symbl == 'E') {
				this->enemy1 = Position(i, j);
			}
			if (symbl == 'E') {
				this->Enemy2 = Position(i, j);
			}
			if (symbl == 'E') {
				this->Enemy3 = Position(i, j);
			}
			if (symbl == 'E') {
				this->Enemy4 = Position(i, j);
			}
		}
	}
	{

	}
}

char Field::get_element(int x, int y) const
{
	return this->field[x][y];
}

char Field::get_element(Position pos) const
{
	return this->get_element(pos.x, pos.y);
}

bool Field::check_symbl(int x, int y, char symbl) const
{
	return this->get_element(x,y)==symbl;
}

bool Field::check_symbl(Position pos, char symbl) const
{
	return this->get_element(pos) == symbl;
}

void Field::set_element(int x, int y, char locat)
{
	this ->~Field[x][y] = locat;
}

void Field::set_element(Position pos, char locat)
{
	this->set_element(pos.x, pos.y, locat);
}

Field::~Field()
{
}
