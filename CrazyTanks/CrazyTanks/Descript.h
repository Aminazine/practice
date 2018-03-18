#pragma once

#include "Tank.h"
#include "Management.h"
#include "BtlField.h"

class object_descript
{
public:
	object_descript();
	Movement init_mov;
	Position pos;
	void prnt();
};

class billet_descript 
{
public:
	Position pos;
	Direct dir;
};
class Descript
{
public:
	Position curr_pos;
	void init(ID, ID);
	ID player_id, enemy_id;
	void refrsh_descript();
	void prnt_descript();
 };