#include "stdafx.h"
#include "Tank.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "MainField.h"


Tank::Tank(char symbl, 
	char bullet_symbl, 
	Position curr_pos, 
	Position prev_pos, 
	bool is_dead)
{
	this->symbl = symbl;
	this->bullet_symbl = bullet_symbl;
	this->curr_pos = curr_pos;
	this->prev_pos = prev_pos;
	this->is_dead = is_dead;

}

void Tank::init(int get_id,
	char symbl,
	Position init_pos,
	char player_symbl,
	Position player_pos)

{

}


bool Tank::Player::is_killed(Tank &t)
{

}

bool Tank::Player::is_kill(Tank t)
{
	
}

void Tank::Player::set_is_dead()
{
}

void Tank::Player::refrsh_player(Field & BtlField)
{
}

void Bullet::movement()
{
}

void Bullet::check_bullet(Field & BtlField)
{
}

bool Bullet::check_hit(Field & BtlField)
{
	return false;
}

void Bullet::refrsh_bullet(Field & BtlField)
{
}
