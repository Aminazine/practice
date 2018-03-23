#pragma once



class BatleField
{
private:
	const int width = 20;
	const int height = 20;
	char wallSymbol = '@';

public:

	BatleField();
	void setBoarder();
	void setWall();
	void setTank();
	void setGold();

};

