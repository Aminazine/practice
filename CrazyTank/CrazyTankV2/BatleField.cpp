#include "stdafx.h"
#include <iostream>
#include "BatleField.h"
#include "Management.h"
#include <ctime>
BatleField::BatleField()
{
	map = new char*[height];
	for (int i = 0; i < height; i++) {
		map[i] = new char[width];
		for (int j = 0; j < width; j++) {
			map[i][j] = ' ';
		}
	}
	player.coord.X = width/2;
	player.coord.Y = height-2;
	player.symbol = '1';
	map[player.coord.Y][player.coord.X] = player.symbol;
	generateWalls();
	
}

BatleField::~BatleField()
{
	//for (int i = 0; i < height; i++) {
	//	delete[] map[i];
	//}
	//delete[] map;
}

void BatleField::setBoarder()
{
	system("cls");
	for (int i = 0; i < width + 1; i++) {
		map[0][i] = wallSymbol;
		//std::cout << wallSymbol;
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1 || i == height-1) {
				//std::cout << wallSymbol;
				map[i][j] = wallSymbol;
			}
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
				std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
	
}
//void BatleField::setWall()
//{
//}

void BatleField::setTank()
{
}

void BatleField::setGold()
{
}
void BatleField::clearTank(Tank tank)
{
	SetConsoleCursorPosition(h, tank.coord);
	std::cout << " ";
	map[tank.coord.Y][tank.coord.X] = ' ';
}
void BatleField::printTank(Tank tank,int X,int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(h, coord);
	std::cout << tank.symbol;
	map[Y][X] = tank.symbol;
}
void BatleField::generateWalls()
{
	// n % p  -   0 ... p-1
	for (int i = 0; i < 30;) {
		int X = rand() % 18 + 1;
		int Y = rand() % 18 + 1;
		if (map[Y][X] == ' ') {
			map[Y][X] = '#';
			i++;
		}
	}
}
void BatleField::playerMove() {
	eMovement direction =  player.move.Control();
	int X = player.coord.X;
	int Y = player.coord.Y;
	if (direction == UP) {
		if (Y > 1 && map[Y - 1][X] == ' ') {
			clearTank(player);
			player.coord.Y--;
			printTank(player,X, Y - 1);
			return;
		}
	}
	if (direction == DOWN) {
		if (Y < height - 1 && map[Y + 1][X] == ' ') {
			clearTank(player);
			player.coord.Y++;
			printTank(player, X, Y + 1);
			return;
		}
	}
	if (direction == LEFT) {
		if (X > 1 && map[Y][X - 1] == ' ') {
			clearTank(player);
			player.coord.X--;
			printTank(player, X-1, Y);
			return;
		}
	}
	if (direction == RIGHT) {
		if (X < width - 1 && map[Y][X+1] == ' ') {
			clearTank(player);
			player.coord.X++;
			printTank(player, X+1, Y);
			return;
		}
	}

}
