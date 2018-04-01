#include "stdafx.h"
#include <iostream>
#include "BatleField.h"
#include "Management.h"
#include "Tank.h"
#include <ctime>
//
//
//BatleField::BatleField()
//{
//	map = new char*[height];
//	for (int i = 0; i < height; i++) {
//		map[i] = new char[width];
//		for (int j = 0; j < width; j++) {
//			map[i][j] = ' ';
//		}
//	}
//
//	enemy = new Tank[enemyCount];
//	setGold();
//	setBase();
//	//setPlayer();
//	//setEnemy();
//	generateWalls();
//}
//
//BatleField::~BatleField()
//{
//}
//
//void BatleField::printScores()
//{
//}
//
//void BatleField::printLife()
//{
//}
//
//void BatleField::setBoarder()
//{
//	system("cls");
//	for (int i = 0; i < width + 1; i++) {
//		map[0][i] = boarderSymbol;
//	}
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			if (j == 0 || j == width - 1 || i == height - 1) {
//				map[i][j] = boarderSymbol;
//			}
//		}
//	}
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			std::cout << map[i][j];
//		}
//		std::cout << std::endl;
//	}
//}
//
//void BatleField::setBase()
//{
//	map[17][9] = baseSymbol;
//	map[17][10] = baseSymbol;
//	map[17][11] = baseSymbol;
//	map[18][9] = baseSymbol;
//	map[18][11] = baseSymbol;
//}
//
//void BatleField::setGold()
//{
//	gold.coord.X = width / 2;
//	gold.coord.Y = height - 2;
//	gold.symbol = '*';
//	map[gold.coord.Y][gold.coord.X] = gold.symbol;
//}
//
////void BatleField::setPlayer()
////{
////	player.coord.X = (width / 2) - 3;
////	player.coord.Y = height - 2;
////	player.symbol = '1';
////	map[player.coord.Y][player.coord.X] = player.symbol;
////}
////
////void BatleField::setEnemy()
////{
////	for (int i = 0; i < enemyCount; i++) {
////		enemy[i].coord.X = rand() % width;
////		enemy[i].coord.Y = rand() % height;
////		enemy[i].symbol = 'Z';
////		map[enemy[i].coord.Y][enemy[i].coord.X] = enemy[i].symbol;
////	}
////}
////
////void BatleField::clearTank(Tank tank)
////{
////	SetConsoleCursorPosition(h, tank.coord);
////	std::cout << " ";
////	map[tank.coord.Y][tank.coord.X] = ' ';
////}
////
////void BatleField::printTank(Tank tank, int X, int Y)
////{
////	COORD coord;
////	coord.X = X;
////	coord.Y = Y;
////	SetConsoleCursorPosition(h, coord);
////	std::cout << tank.symbol;
////	map[Y][X] = tank.symbol;
////}
//
//void BatleField::generateWalls()
//{
//	for (int i = 0; i < 30;) {
//		int X = (rand() % 18) + 1;
//		int Y = (rand() % 18) + 1;
//		if (map[Y][X] == ' ') {
//			map[Y][X] = wallSymbol;
//			i++;
//		}
//	}
//}
//
////void BatleField::tankMove(Tank & tank,Direction  dir )
////{	
////	int X = tank.coord.X;
////	int Y = tank.coord.Y;
////	if (dir == UP) {
////		if (Y > 1 && map[Y - 1][X] == ' ') {
////			clearTank(tank);
////			tank.coord.Y--;
////			printTank(tank, X, Y - 1);
////			return;
////		}
////	}
////	if (dir == DOWN) {
////		if (Y < height - 1 && map[Y + 1][X] == ' ') {
////			clearTank(tank);
////			tank.coord.Y++;
////			printTank(tank, X, Y + 1);
////			return;
////		}
////	}
////	if (dir == LEFT) {
////		if (X > 1 && map[Y][X - 1] == ' ') {
////			clearTank(tank);
////			tank.coord.X--;
////			printTank(tank, X - 1, Y);
////			return;
////		}
////	}
////	if (dir == RIGHT) {
////		if (X < width - 1 && map[Y][X + 1] == ' ') {
////			clearTank(tank);
////			tank.coord.X++;
////			printTank(tank, X + 1, Y);
////			return;
////		}
////	}
////}
////
////void BatleField::enemyMove() 
////{
////	int n;
////	while (true) {
////		n = rand() % enemyCount;
////		if (enemy[n].life != 0)break;
////	}
////	int m = rand() % 4 + 1;
////	Direction dir = (Direction)m;
////	tankMove(enemy[n], dir);
////}
////
////void BatleField::playerMove()
////{
////	Direction dir = player.move.control();
////	tankMove(player, dir);
////}

void Map::Generate()
{
	for (int i = 0; i<50; i++) {
		for (int j = 0; j<50; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i<25; i++) {

		map[rand() % 46 + 3][rand() % 46 + 3] = 1;
	}
}

void Map::Gen()
{
	for (int i = 0; i<25; i++) {
		int x = rand() % 46 + 3;
		int y = rand() % 46 + 3;
		if (map[y][x] == 0)map[y][x] = 1;
	}
	ShowMap();
}

void Map::ShowMap()
{
	COORD tmp;
	tmp.X = 0;
	tmp.Y = 0;
	char s = 219;
	for (int i = 0; i<50; i++) {
		for (int j = 0; j<50; j++) {
			if (map[i][j] == 1) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << s;
			}
			/*else {
			SetConsoleCursorPosition(h,tmp);
			cout<<" ";
			}*/
			tmp.X++;
		}
		tmp.X = 0;
		tmp.Y++;
	}
}

bool Map::check(int key, Position start, Position end, Position barrel, int turn, int size){
	if (key == 72) {
		if (turn != UP)return true;
		int check = 0;
		int ty = barrel.GetY() - 1;
		int tx = barrel.GetX() - 1;
		for (int i = 0; i < size; i++) {
			if (map[ty][tx] == 0)check++;
			tx++;
		}
		if (check == size)return true;
		else return false;
	}
	if (key == 80) {
		if (turn != DOWN)return true;
		int check = 0;
		int y = barrel.GetY() + 1;
		int x = barrel.GetX() - 1;
		for (int i = 0; i<size; i++) {
			if (map[y][x] == 0)check++;
			x++;
		}
		if (check == size)return true;
		else return false;
	}
	if (key == 75) {
		if (turn != LEFT)return true;
		int check = 0;
		int y = barrel.GetY() - 1;
		int x = barrel.GetX() - 1;
		for (int i = 0; i<size; i++) {
			if (map[y][x] == 0)check++;
			y++;
		}
		if (check == size)return true;
		else return false;
	}
	if (key == 77) {
		if (turn != RIGHT)return true;
		int check = 0;
		int y = barrel.GetY() - 1;
		int x = barrel.GetX() + 1;
		for (int i = 0; i<size; i++) {
			if (map[y][x] == 0)check++;
			y++;
		}
		if (check == size)return true;
		else return false;
	}
}

void Map::Fire(Position tShoot, int turn)
{
	if (turn == UP) {
		COORD tmp;
		tmp.X = tShoot.GetX();
		tmp.Y = tShoot.GetY();
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.Y--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.Y--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.Y = tShoot.GetY();
		Sleep(50);
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.Y--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.Y--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
	}
	else if (turn == DOWN) {
		COORD tmp;
		tmp.X = tShoot.GetX();
		tmp.Y = tShoot.GetY();
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.Y++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.Y++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.Y = tShoot.GetY();
		Sleep(50);
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.Y++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.Y++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";

	}
	else if (turn == LEFT) {
		COORD tmp;
		tmp.X = tShoot.GetX();
		tmp.Y = tShoot.GetY();
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.X--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.X--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.X = tShoot.GetX();
		Sleep(50);
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.X--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.X--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
	}
	else if (turn == RIGHT) {
		COORD tmp;
		tmp.X = tShoot.GetX();
		tmp.Y = tShoot.GetY();
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.X++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.X++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.X = tShoot.GetX();
		Sleep(50);
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.X++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.X++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
	}
}

void Map::MoveShot(int i)
{
	if (shot[i].GetTurn() == 1)
	{
		shot[i].SetXY(shot[i].GetX(), shot[i].GetY() - 1);
	}
	else if (shot[i].GetTurn() == 2)
	{
		shot[i].SetXY(shot[i].GetX(), shot[i].GetY() + 1);
	}
	else if (shot[i].GetTurn() == 3)
	{
		shot[i].SetXY(shot[i].GetX() - 1, shot[i].GetY());
	}
	else if (shot[i].GetTurn() == 4)
	{
		shot[i].SetXY(shot[i].GetX() + 1, shot[i].GetY());
	}
}

int Map::GetMap(int i)
{
	if (shot[i].GetX()<0 || shot[i].GetY()<0 || shot[i].GetY()>49 || shot[i].GetX()>49) {

		return -1;
	}
	return map[shot[i].GetY()][shot[i].GetX()];
}

void Map::ShowShot(int i)
{
	if (shot[i].GetX()>0 && shot[i].GetY()>0) {
		COORD tmp;
		tmp.X = shot[i].GetX();
		tmp.Y = shot[i].GetY();
		SetConsoleCursorPosition(h, tmp);
		std::cout << char(253);
	}
}

void Map::ClearShot(int i)
{
	if (shot[i].GetX()>0 && shot[i].GetY()>0) {
		COORD tmp;
		tmp.X = shot[i].GetX();
		tmp.Y = shot[i].GetY();
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
	}
	if (shot[i].GetX()<0 || shot[i].GetX()>49 || shot[i].GetY()<0 || shot[i].GetY()>49) {

	}
}

void Map::Add(Position start, Position end, Position barrel, int turn, int number, bool die, int size)
{
	if (die == false) {
		if (turn == UP) {
			int x = start.GetX();
			int y = start.GetY() - 1;
			for (int i = 0; i<size; i++) {
				for (int j = 0; j<size; j++) {
					map[y][x] = number;
					x++;
				}
				y++;
				x = start.GetX();
			}		
		}
		if (turn == DOWN) {
			int x = start.GetX();
			int y = start.GetY();
			for (int i = 0; i<size; i++) {
				for (int j = 0; j<size; j++) {
					map[y][x] = number;
					x++;
				}
				y++;
				x = start.GetX();
			}		
		}
		if (turn == LEFT) {
			int x = start.GetX() - 1;
			int y = start.GetY();
			for (int i = 0; i<size; i++) {
				for (int j = 0; j<size; j++) {
					map[y][x] = number;
					x++;
				}
				y++;
				x = start.GetX() - 1;
			}
		}
		if (turn == RIGHT) {
			int x = start.GetX();
			int y = start.GetY();
			for (int i = 0; i<size; i++) {
				for (int j = 0; j<size; j++) {
					map[y][x] = number;
					x++;
				}
				y++;
				x = start.GetX();
			}
		}
	}
}

void Map::Clean(Position start, Position end, Position barrel, int turn, bool die, int size)
{
	if (die == false) {
		if (turn == UP) {
			int x = start.GetX();
			int y = start.GetY() - 1;
			for (int i = 0; i<size; i++) {
				for (int j = 0; j<size; j++) {
					map[y][x] = 0;
					x++;
				}
				y++;
				x = start.GetX();
			}
		}
		if (turn == DOWN) {
			int x = start.GetX();
			int y = start.GetY();
			for (int i = 0; i<size; i++) {
				for (int j = 0; j<size; j++) {
					map[y][x] = 0;
					x++;
				}
				y++;
				x = start.GetX();
			}
		}
		if (turn == LEFT) {
			int x = start.GetX() - 1;
			int y = start.GetY();
			for (int i = 0; i<size; i++) {
				for (int j = 0; j<size; j++) {
					map[y][x] = 0;
					x++;
				}
				y++;
				x = start.GetX() - 1;
			}
		}
		if (turn == RIGHT) {
			int x = start.GetX();
			int y = start.GetY();
			for (int i = 0; i<size; i++) {
				for (int j = 0; j<size; j++) {
					map[y][x] = 0;
					x++;
				}
				y++;
				x = start.GetX();
			}
		}
	}
}

void Map::Crash(int i)
{
	if (shot[i].GetTurn() == 1) {
		map[shot[i].GetY()][shot[i].GetX() - 1] = 0;
		map[shot[i].GetY()][shot[i].GetX()] = 0;
		map[shot[i].GetY()][shot[i].GetX() + 1] = 0;
		COORD tmp;
		tmp.Y = shot[i].GetY();
		tmp.X = shot[i].GetX() - 1;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.X++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.X++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";

		Sleep(100);
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.X--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.X--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";

	}
	else if (shot[i].GetTurn() == 2) {
		map[shot[i].GetY()][shot[i].GetX() - 1] = 0;
		map[shot[i].GetY()][shot[i].GetX()] = 0;
		map[shot[i].GetY()][shot[i].GetX() + 1] = 0;
		COORD tmp;
		tmp.Y = shot[i].GetY();
		tmp.X = shot[i].GetX() - 1;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.X++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.X++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";

		Sleep(100);
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.X--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.X--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";

	}
	else if (shot[i].GetTurn() == 3) {
		map[shot[i].GetY() - 1][shot[i].GetX()] = 0;
		map[shot[i].GetY()][shot[i].GetX()] = 0;
		map[shot[i].GetY() + 1][shot[i].GetX()] = 0;
		COORD tmp;
		tmp.Y = shot[i].GetY() - 1;
		tmp.X = shot[i].GetX();
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.Y++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.Y++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";

		Sleep(100);
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.Y--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.Y--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";

	}
	else if (shot[i].GetTurn() == 4) {
		map[shot[i].GetY() - 1][shot[i].GetX()] = 0;
		map[shot[i].GetY()][shot[i].GetX()] = 0;
		map[shot[i].GetY() + 1][shot[i].GetX()] = 0;
		COORD tmp;
		tmp.Y = shot[i].GetY() - 1;
		tmp.X = shot[i].GetX();
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.Y++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		tmp.Y++;
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";

		Sleep(100);
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.Y--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
		tmp.Y--;
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";

	}
}
