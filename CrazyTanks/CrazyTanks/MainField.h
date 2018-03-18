#pragma once

#include "Tank.h"
#include "BtlField.h"

class MainField
{
public:

	Field BtlField;
	Tank player, tank;
	bool game_over;

	MainField();
	void prnt_scores();
	void prnt_life();
	void bullet_mov();
	void get_player_mov();
	void tank_mov();
	void check_objects();
	void check_bullets();
	void refrsh_field();
	void end_game();


	~MainField();
};

