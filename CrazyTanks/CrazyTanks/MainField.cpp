#include "stdafx.h"
#include <iostream>
#include "MainField.h"
#include "Tank.h"


MainField::MainField()
{
	game_over = false;
	this->BtlField.set_objects();
}

void MainField::prnt_scores()
{
	this->BtlField.Player(score);
	std::cout << "Score:" << score << std::endl;
}

void MainField::prnt_life()
{
	this->Tank.player(life);
	std::cout << "Life:" << life << std::endl;
}

void MainField::bullet_mov()
{
	player.bullet_mov();
}

void MainField::get_player_mov()
{
}

void MainField::tank_mov()
{
}

void MainField::check_objects()
{
}

void MainField::check_bullets()
{
}

void MainField::refrsh_field()
{
}

void MainField::end_game()
{
}


MainField::~MainField()
{
}
