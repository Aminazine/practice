#pragma once
#include <iostream>
#include "Management.h"
#include <vector>

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

class Bullet {
	Position Shoot;
	int turn;
	bool inAction;
public:	
	char symbol;
	Direction dir;	
	COORD coord;

	Bullet() {
		inAction = true;
	}

	void Add(Position cord, int turn) {
		Shoot.SetXY(cord.GetX(), cord.GetY());
		this->turn = turn;
	}
	bool getInAction() { 
		return inAction; 
	}
	void SetinAction(bool a) { 
		inAction = a; 
	}
	int GetTurn() { 
		return turn; 
	}
	void MoveUp() { 
		Shoot.MoveUp(); 
	}
	void MoveDown() { 
		Shoot.MoveDown(); }
	void MoveLeft() { Shoot.MoveLeft();
	}
	void MoveRight() { 
		Shoot.MoveRight(); 
	}
	int& GetX() { 
		return Shoot.GetX();
	}
	int& GetY() {
		return Shoot.GetY(); 
	}
	void SetXY(int tx, int ty) { 
		Shoot.SetXY(tx, ty); 
	}
};

void Turn(int &sx, int &sy, int &ex, int &ey, int newturn, int lastturn);
class Tank
{
protected:
	Position start;
	Position end;
	Position barrel;
	Move move;	
	char symbol;
	COORD coord;
	int turn;
	bool die;
	int score;
	int life;
	int dmg;
public:
	Tank() {
		start.SetXY(0, 0);
		end.SetXY(1, 2);
		barrel.SetXY(2, 1);
		turn = RIGHT;
		die = false;	
		life = 3;
		dmg = 1;
	}
	Tank(int m, int h, int d, int turn = RIGHT) {
		start.SetXY(0, 0);
		end.SetXY(1, 2);
		barrel.SetXY(2, 1);
		this->turn = turn;
		die = false;
		life = h;
		dmg = d;
	}
	bool SetPStart(int x, int y) {
		start.SetXY(x, y);
		return true;
	}
	bool SetPEnd(int _x, int _y) {
		end.SetXY(_x, _y);
		return true;
	}
	void Print(int level);
	void Clean();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	Position Start() { return start; }
	Position End() { return end; }
	Position Barrel() { return barrel; }
	void ChangeTurn(int i) { turn = i; }
	int Turn1() { return turn; }
	void Die() { die = true; }
	bool RDie() { return die; }
	Position Shoot(Position tShoot);
	void TakeDmg(int d) {
		life -= d;
	}
	int Dmg() { return dmg; }
	int Life() { return life; }
	void Live() { die = false; }
	void SetBarrel(int _x, int _y) {
		barrel.SetXY(_x, _y);
	}
	void SetDmg(int dmg) { this->dmg = dmg; }
	~Tank();
};
void Turn(int &sx, int &sy, int &ex, int &ey, int newturn, int lastturn) {
	if (newturn == 1) {
		if (lastturn == 3) {
			sx--;
			sy++;
		}
		if (lastturn == 4) {
			sy++;
			ex++;
		}
		if (lastturn == 2) {
			sy++;
			ey++;
		}
	}
	else if (newturn == 2) {
		if (lastturn == 3) {
			ey--;
			sx--;
		}
		if (lastturn == 4) {
			ex++;
			ey--;
		}
		if (lastturn == 1) {
			sy--;
			ey--;
		}
	}
	else if (newturn == 3) {
		if (lastturn == 4) {
			ex++;
			sx++;
		}
		if (lastturn == 1) {
			sx++;
			sy--;
		}
		if (lastturn == 2) {
			sx++;
			ey++;
		}
	}
	else if (newturn == 4) {
		if (lastturn == 3) {
			ex--;
			sx--;
		}
		if (lastturn == 1) {
			sy--;
			ex--;
		}
		if (lastturn == 2) {
			ey++;
			ex--;
		}
	}
}