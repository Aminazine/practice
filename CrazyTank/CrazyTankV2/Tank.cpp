#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "Tank.h"

void Tank::Print(int level)
{
	if (die == false) {
		if (turn == UP) {
			COORD tmp;
			tmp.X = start.GetX();
			tmp.Y = start.GetY() - 1;
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << char(254);
				tmp.Y++;
			}
			tmp.X = end.GetX();
			tmp.Y = end.GetY() - 2;
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << char(254);
				tmp.Y++;
			}
			tmp.X = barrel.GetX();
			tmp.Y = barrel.GetY();
			SetConsoleCursorPosition(h, tmp);
			std::cout << '|';
			tmp.Y++;
			SetConsoleCursorPosition(h, tmp);
			if (level == 10) {
				SetConsoleTextAttribute(h, 12);
				std::cout << char(30);
			}
			else std::cout << char(219);

		}
		else if (turn == DOWN) {
			COORD tmp;
			tmp.X = start.GetX();
			tmp.Y = start.GetY();
			for (int i = 0; i < 3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << char(254);
				tmp.Y++;
			}
			COORD tmp;
			tmp.X = start.GetX();
			tmp.Y = start.GetY();
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << char(254);
				tmp.Y++;
			}
			tmp.X = end.GetX();
			tmp.Y = end.GetY() - 1;
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << char(254);
				tmp.Y++;
			}
			tmp.X = barrel.GetX();
			tmp.Y = barrel.GetY();
			SetConsoleCursorPosition(h, tmp);
			std::cout << '|';
			tmp.Y--;
			SetConsoleCursorPosition(h, tmp);
			if (level == 10) {
				SetConsoleTextAttribute(h, 12);
				std::cout << char(31);
			}
			else std::cout << char(219);

		}
		else if (turn == LEFT) {
			COORD tmp;
			tmp.X = start.GetX() - 1;
			tmp.Y = start.GetY();
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << char(254);
				tmp.X++;
			}
			tmp.X = end.GetX() - 2;
			tmp.Y = end.GetY();
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << char(254);
				tmp.X++;
			}
			tmp.X = barrel.GetX();
			tmp.Y = barrel.GetY();
			SetConsoleCursorPosition(h, tmp);
			std::cout << '-';
			tmp.X++;
			SetConsoleCursorPosition(h, tmp);
			if (level == 10) {
				SetConsoleTextAttribute(h, 12);
				std::cout << char(17);
			}
			else std::cout << char(219);
		}
		else if (turn == RIGHT) {
			COORD tmp;
			tmp.X = start.GetX();
			tmp.Y = start.GetY();
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << char(254);
				tmp.X++;
			}
			tmp.X = end.GetX() - 1;
			tmp.Y = end.GetY();
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << char(254);
				tmp.X++;
			}
			tmp.X = barrel.GetX();
			tmp.Y = barrel.GetY();
			SetConsoleCursorPosition(h, tmp);
			std::cout << '-';
			tmp.X--;
			SetConsoleCursorPosition(h, tmp);
			if (level == 10) {
				SetConsoleTextAttribute(h, 12);
				std::cout << char(16);
			}
			else std::cout << char(219);
		}
	}
}

void Tank::Clean()
{
	if (die == false) {
		//Clean(start.GetX(),start.GetY(),end.GetX(),end.GetY(),turn);
		if (turn == UP) {
			COORD tmp;
			tmp.X = start.GetX();
			tmp.Y = start.GetY() - 1;
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << " ";
				tmp.Y++;
			}
			tmp.X = end.GetX();
			tmp.Y = end.GetY() - 2;
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << " ";
				tmp.Y++;
			}
			tmp.X = barrel.GetX();
			tmp.Y = barrel.GetY();
			SetConsoleCursorPosition(h, tmp);
			std::cout << " ";
			tmp.Y++;
			SetConsoleCursorPosition(h, tmp);
			std::cout << " ";

		}
		else if (turn == DOWN) {
			COORD tmp;
			tmp.X = start.GetX();
			tmp.Y = start.GetY();
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << " ";
				tmp.Y++;
			}
			tmp.X = end.GetX();
			tmp.Y = end.GetY() - 1;
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << " ";
				tmp.Y++;
			}
			tmp.X = barrel.GetX();
			tmp.Y = barrel.GetY();
			SetConsoleCursorPosition(h, tmp);
			std::cout << " ";
			tmp.Y--;
			SetConsoleCursorPosition(h, tmp);
			std::cout << " ";

		}
		else if (turn == LEFT) {
			COORD tmp;
			tmp.X = start.GetX() - 1;
			tmp.Y = start.GetY();
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << " ";
				tmp.X++;
			}
			tmp.X = end.GetX() - 2;
			tmp.Y = end.GetY();
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << " ";
				tmp.X++;
			}
			tmp.X = barrel.GetX();
			tmp.Y = barrel.GetY();
			SetConsoleCursorPosition(h, tmp);
			std::cout << " ";
			tmp.X++;
			SetConsoleCursorPosition(h, tmp);
			std::cout << " ";
		}
		else if (turn == RIGHT) {
			COORD tmp;
			tmp.X = start.GetX();
			tmp.Y = start.GetY();
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << " ";
				tmp.X++;
			}
			tmp.X = end.GetX() - 1;
			tmp.Y = end.GetY();
			for (int i = 0; i<3; i++) {
				SetConsoleCursorPosition(h, tmp);
				std::cout << " ";
				tmp.X++;
			}
			tmp.X = barrel.GetX();
			tmp.Y = barrel.GetY();
			SetConsoleCursorPosition(h, tmp);
			std::cout << " ";
			tmp.X--;
			SetConsoleCursorPosition(h, tmp);
			std::cout << " ";
		}
	}
}

void Tank::MoveUp()
{
	if (die == false) {
		if (start.GetY()>0 && end.GetY()>0 && turn == UP && barrel.GetY() != 0) {
			//clean();
			barrel.MoveUp();
			start.MoveUp();
			end.MoveUp();
			// Print();
		}
		else {
			//clean();
			Turn(start.GetX(), start.GetY(), end.GetX(), end.GetY(), UP, turn);
			barrel.SetXY(start.GetX() + 1, start.GetY() - 1);
			turn = UP;
			//Print();
		}
	}
}

void Tank::MoveDown()
{
	if (die == false) {
		if (start.GetY()<49 && end.GetY()<49 && turn == DOWN && barrel.GetY() != 49) {
			//clean();
			barrel.MoveDown();
			start.MoveDown();
			end.MoveDown();

			//Print();
		}
		else {
			//clean();
			Turn(start.GetX(), start.GetY(), end.GetX(), end.GetY(), DOWN, turn);
			barrel.SetXY(end.GetX() - 1, end.GetY() + 1);
			turn = DOWN;
			//Print();
		}
	}
}

void Tank::MoveLeft()
{
	if (die == false) {
		if (start.GetX()>0 && end.GetX()>0 && barrel.GetX()>0 && turn == LEFT) {
			//	clean();
			barrel.MoveLeft();
			start.MoveLeft();
			end.MoveLeft();


			//Print();	
		}
		else {
			//clean();
			Turn(start.GetX(), start.GetY(), end.GetX(), end.GetY(), LEFT, turn);
			barrel.SetXY(start.GetX() - 1, start.GetY() + 1);
			turn = LEFT;
			//Print();
		}
	}
}

void Tank::MoveRight()
{
	if (die == false) {
		if (start.GetX()<49 && end.GetX()<49 && turn == RIGHT && barrel.GetX() != 49) {
			//clean();
			barrel.MoveRight();
			start.MoveRight();
			end.MoveRight();

			//Print();
		}
		else {
			//clean();
			Turn(start.GetX(), start.GetY(), end.GetX(), end.GetY(), RIGHT, turn);
			barrel.SetXY(end.GetX() + 1, end.GetY() - 1);
			turn = RIGHT;
			//Print();
		}
	}
}

Position Tank::Shoot(Position tShoot)
{
	if (turn == 1)
	{
		tShoot.SetXY(tShoot.GetX(), tShoot.GetY() - 1);
	}
	else if (turn == 2)
	{
		tShoot.SetXY(tShoot.GetX(), tShoot.GetY() + 1);
	}
	else if (turn == 3)
	{
		tShoot.SetXY(tShoot.GetX() - 1, tShoot.GetY());
	}
	else if (turn == 4)
	{
		tShoot.SetXY(tShoot.GetX() + 1, tShoot.GetY());
	}
	if (tShoot.GetX()>0 && tShoot.GetY()>0) {
		COORD tmp;
		tmp.X = tShoot.GetX();
		tmp.Y = tShoot.GetY();
		SetConsoleCursorPosition(h, tmp);
		std::cout << "*";
		Sleep(30);
		tmp.X = tShoot.GetX();
		tmp.Y = tShoot.GetY();
		SetConsoleCursorPosition(h, tmp);
		std::cout << " ";
	}	

	return tShoot;
}

Tank::~Tank()
{
}
