#include "stdafx.h"
#include <iostream>
#include "BatleField.h"


void BatleField::setBoarder()
{
	system("cls");
	for (int i = 0; i < width + 1; i++)
		std::cout << wallSymbol;
	std::cout << std::endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				std::cout << wallSymbol;
}

void BatleField::setWall()
{
}

void BatleField::setTank()
{
}

void BatleField::setGold()
{
}
