#pragma once
#include "Tank.h"
#include "Base.h"

class BatleField
{
};
class Map{
	int  map[50][50];
	Bullet * shot;
	int size;
public:
	Map() {
		Generate();
		shot = NULL;
	}
	void Generate();
	void Gen();
	void ShowMap();
	bool check(int key, Position start, Position end, Position barrel, int turn, int size = 3);
	void Fire(Position tShoot, int turn);
	void MoveShot(int i);
	int GetMap(int i);
	void ShowShot(int i);
	void ClearShot(int i);
	void Add(Position start, Position end, Position barrel, int turn, int number, bool die, int size = 3);
	void Clean(Position start, Position end, Position barrel, int turn, bool die, int size = 3);
	void Crash(int i);
	void SetSize(int s) {
		size = s;
		if (shot != NULL)delete shot;

		shot = new Bullet[s];
	}
	bool CheckForShot(Position barrel, int turn) {
		if (turn == UP) {
			COORD tmp;
			tmp.Y = barrel.GetY() - 1;
			tmp.X = barrel.GetX();
			while (tmp.Y>0) {
				if (map[tmp.Y][tmp.X] == 2)return true;
				else tmp.Y--;
			}
			return false;
		}
		else if (turn == DOWN) {
			COORD tmp;
			tmp.Y = barrel.GetY() + 1;
			tmp.X = barrel.GetX();
			while (tmp.Y<50) {
				if (map[tmp.Y][tmp.X] == 2)return true;
				else tmp.Y++;
			}
			return false;
		}
		else if (turn == LEFT) {
			COORD tmp;
			tmp.Y = barrel.GetY();
			tmp.X = barrel.GetX() - 1;
			while (tmp.X>0) {
				if (map[tmp.Y][tmp.X] == 2)return true;
				else tmp.X--;
			}
			return false;
		}
		else if (turn == RIGHT) {
			COORD tmp;
			tmp.Y = barrel.GetY();
			tmp.X = barrel.GetX() + 1;
			while (tmp.X<50) {
				if (map[tmp.Y][tmp.X] == 2)return true;
				else tmp.X++;
			}
			return false;
		}

	}
	int CheckTurnForShot(Position barrel, int turn) {
		if (turn == UP) {
			Position tmp;
			tmp.SetXY(barrel.GetX() - 1, barrel.GetY() + 1);
			if (CheckForShot(tmp, LEFT) == true)return 75;
			tmp.SetXY(barrel.GetX() + 1, barrel.GetY() + 1);
			if (CheckForShot(tmp, RIGHT) == true)return 77;
			tmp.SetXY(barrel.GetX(), barrel.GetY() + 2);
			if (CheckForShot(tmp, DOWN) == true)return 80;
			return 1;
		}
		else if (turn == DOWN) {
			Position tmp;
			tmp.SetXY(barrel.GetX() - 1, barrel.GetY() - 1);
			if (CheckForShot(tmp, 3) == true)return 75;
			tmp.SetXY(barrel.GetX() + 1, barrel.GetY() - 1);
			if (CheckForShot(tmp, 4) == true)return 77;
			tmp.SetXY(barrel.GetX(), barrel.GetY() - 2);
			if (CheckForShot(tmp, 1) == true)return 72;
			return 1;
		}
		else if (turn == LEFT) {
			Position tmp;
			tmp.SetXY(barrel.GetX() + 1, barrel.GetY() - 1);
			if (CheckForShot(tmp, 1) == true)return 72;
			tmp.SetXY(barrel.GetX() + 2, barrel.GetY());
			if (CheckForShot(tmp, 4) == true)return 77;
			tmp.SetXY(barrel.GetX() + 1, barrel.GetY() + 1);
			if (CheckForShot(tmp, 2) == true)return 80;
			return 1;
		}
		else if (turn == RIGHT) {
			Position tmp;
			tmp.SetXY(barrel.GetX() - 2, barrel.GetY());
			if (CheckForShot(tmp, 3) == true)return 75;
			tmp.SetXY(barrel.GetX() - 1, barrel.GetY() - 1);
			if (CheckForShot(tmp, 1) == true)return 72;
			tmp.SetXY(barrel.GetX() - 1, barrel.GetY() + 1);
			if (CheckForShot(tmp, 2) == true)return 80;
			return 1;
		}

	}
	int CheckForSpawn() {
		int c = 0;
		for (int i = 25; i<28; i++) {
			for (int j = 3; i<6; j++) {
				if (map[i][j] == 0)c++;

			}
		}
		if (c == 9)return 1;
		c = 0;
		for (int i = 46; i<49; i++) {
			for (int j = 46; j<49; j++) {
				if (map[i][j] == 0)c++;

			}
		}
		if (c == 9)return 2;
		c = 0;
		for (int i = 10; i<13; i++) {
			for (int j = 46; j<49; j++) {
				if (map[i][j] == 0)c++;

			}
		}
		if (c == 9)return 3;
		return -1;		
	}
	bool CheckForSpawn(int key) {
		int c = 0;
		if (key == 1) {
			for (int i = 25; i<28; i++) {
				for (int j = 3; j<6; j++) {
					if (map[i][j] == 0)c++;

				}
			}
			if (c == 9)return true;

		}
		else if (key == 2) {
			for (int i = 46; i<49; i++) {
				for (int j = 46; j<49; j++) {
					if (map[i][j] == 0)c++;

				}
			}
			if (c == 9)return true;
		}
		else if (key == 3) {
			for (int i = 10; i<13; i++) {
				for (int j = 46; j<49; j++) {
					if (map[i][j] == 0)c++;

				}
			}
			if (c == 9)return true;
		}
		return false;
	}
	void FullMap() {
		for (int i = 0; i < 49; i++) {
			for (int j = 0; j < 49; j++) {
				if (map[i][j] == 0)map[i][j] = 1;
			}
		}
		ShowMap();
	}
};



//private:
//	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//	const int width = 20;
//	const int height = 20;
//	char baseSymbol = '%';
//	char boarderSymbol = '@';
//	char wallSymbol = '#';
//	char ** map;
//	Base gold;
//	Tank player;
//	Tank * enemy;
//	int enemyCount = 5;
//
//public:
//	BatleField();
//	~BatleField();
//	void printScores();
//	void printLife();
//	void setBoarder();
//	void setBase();
//	void setGold();
//	/*void setPlayer();
//	void setEnemy();
//	void tankMove(Tank & tank, Direction  dir);
//	void enemyMove();
//	void playerMove();
//	void clearTank(Tank tank);
//	void printTank(Tank tank, int X, int Y);*/
//	void generateWalls();	
