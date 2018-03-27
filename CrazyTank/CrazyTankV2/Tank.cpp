#include "stdafx.h"
#include "Tank.h"

Tank::Tank(char symbol, char bulletSymbol, Position curPos, Position prePos)
{
	this->symbol = symbol;
	/*this->bulletSymbol = bulletSymbol;
	this->curPos = curPos;
	this->prePos = prePos;*/
}

//void Tank::initTank(Tank tank)
//{
//	this->symbol = tank.symbol;
//	this->curPos = nowPos;
//	this->prePos = this->curPos;
//}

Bullet::Bullet()
{
}

void Bullet::move()
{

}

Bullet::~Bullet()
{
}

//void Bullet::printBoolet()
//{
//}

//void Bullet::move()
//{
//
//}
//
//void Bullet::checkForCrash()
//{
//}
//
//bool Bullet::checkForHit()
//{
//	return false;
//}
//
//void Bullet::clearBoolet(Tank bullet)
//{
//	(h, bullet.coord);
//	std::cout << " ";
//	map[bullet.coord.Y][bullet.coord.X] = ' ';
//}
//
//void Bullet::printBoolet()
//{
//}



Tank::~Tank()
{
}