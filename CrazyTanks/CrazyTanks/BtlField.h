#pragma once

#include "Management.h"

class Field
{
public:


	Field();

	void set_objects();
	char get_element(int x, int y) const;
	char get_element(Position pos) const;
	bool check_symbl(int x, int y, char sumbl) const;
	bool check_symbl(Position pos, char symbl) const;
	void set_element(int x, int y, char locat);
	void set_element(Position pos, char locat);

	~Field();
};

