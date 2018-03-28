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
	
	gold.coord.X = width / 2;
	gold.coord.Y = height - 2;
	gold.symbol = '*';
	map[gold.coord.Y][gold.coord.X] = gold.symbol;

	enemy = new Tank[enemyCount];
	setPlayer();
	setEnemy();
	generateWalls();

}

BatleField::~BatleField()
{
	//for (int i = 0; i < height; i++) {
	//	delete[] map[i];
	//}
	//delete[] map;
}

void BatleField::printScores()
{
}

void BatleField::printLife()
{
}

void BatleField::setBoarder()
{
//	system("cls");
	for (int i = 0; i < width + 1; i++) {
		map[0][i] = boarderSymbol;
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1 || i == height - 1) {
				map[i][j] = boarderSymbol;
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

//void BatleField::setGold()
//{
//	gold.coord.X = width / 2;
//	gold.coord.Y = height - 2;
//	gold.symbol = '*';
//	map[gold.coord.Y][gold.coord.X] = gold.symbol;
//}


void BatleField::setPlayer()
{
	player.coord.X = (width / 2) - 3;
	player.coord.Y = height - 2;
	player.symbol = '1';
	map[player.coord.Y][player.coord.X] = player.symbol;
}

void BatleField::setEnemy()
{
	for (int i = 0; i < enemyCount; i++) {
		enemy[i].coord.X = rand() % width;
		enemy[i].coord.Y = rand() % height;
		enemy[i].symbol = 'Z';
		map[enemy[i].coord.Y][enemy[i].coord.X] = enemy[i].symbol;
	}
}

void BatleField::clearTank(Tank tank)
{
	SetConsoleCursorPosition(h, tank.coord);
	std::cout << " ";
	map[tank.coord.Y][tank.coord.X] = ' ';
}
void BatleField::printTank(Tank tank, int X, int Y)
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
		int X = (rand() % 18) + 1;
		int Y = (rand() % 18) + 1;
		if (map[Y][X] == ' ') {
			map[Y][X] = wallSymbol;
			i++;
		}
	}
}

void BatleField::tankMove(Tank & tank,Direction  dir ) {
	
	int X = tank.coord.X;
	int Y = tank.coord.Y;
	if (dir == UP) {
		if (Y > 1 && map[Y - 1][X] == ' ') {
			clearTank(tank);
			tank.coord.Y--;
			printTank(tank, X, Y - 1);
			return;
		}
	}
	if (dir == DOWN) {
		if (Y < height - 1 && map[Y + 1][X] == ' ') {
			clearTank(tank);
			tank.coord.Y++;
			printTank(tank, X, Y + 1);
			return;
		}
	}
	if (dir == LEFT) {
		if (X > 1 && map[Y][X - 1] == ' ') {
			clearTank(tank);
			tank.coord.X--;
			printTank(tank, X - 1, Y);
			return;
		}
	}
	if (dir == RIGHT) {
		if (X < width - 1 && map[Y][X + 1] == ' ') {
			clearTank(tank);
			tank.coord.X++;
			printTank(tank, X + 1, Y);
			return;
		}
	}

}

void BatleField::enemyMove() {
	int n;
	while (true) {
		n = rand() % enemyCount;
		if (enemy[n].life != 0)break;
	}
	int m = rand() % 4 + 1;
	Direction dir = (Direction)m;
	tankMove(enemy[n], dir);
}

void BatleField::playerMove()
{
	Direction dir = player.move.control();
	tankMove(player, dir);
}
