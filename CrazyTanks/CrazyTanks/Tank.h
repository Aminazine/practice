#pragma once
#include <iostream>
#include "BtlField.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "MainField.h"

class Bullet 
{
public:
	char symbl;
	Direct curr_dir;
	Position curr_pos, prev_pos;
	bool end_of_dir;

	Bullet()
	{
		end_of_dir = false;
	}
	void movement();
	void check_bullet(Field & BtlField);
	bool check_hit(Field & BtlField);
	void set_end_of_dir() {
		end_of_dir = true;
	}
	void refrsh_bullet(Field & BtlField);
	void prnt_bullet()
	{
		curr_dir.prnt();
		std::cout << "";
		curr_pos.prnt();
		std::cout << "";
		prev_pos.prnt();
		std::cout << "" << end_of_dir << std::endl;
	}
};


class Tank
{
public:

	class Player {
	public:
		bool is_dead;
		char symbl;
		Position pos;

		Player() {
			is_dead = false;
		}
		bool is_killed(Tank &e);
		bool is_kill(Tank e);
		void set_is_dead();
		void refrsh_player(Field & BtlField);

	};

	char symbl;
	ID id;
	Player player;
	char bullet_symbl;
	Movement next_mov;
	bool is_dead;	
	Position curr_pos, prev_pos;
	int score = 0;
	int life = 3;
	
	Tank() {};

	Tank (char symbl, 
		char bullet_symbl, 
		Position curr_pos, 
		Position prev_pos, 
		bool is_dead= false);

	void init (int get_id, char symbl, Position init_pos, char player_symbl, Position player_pos);
	void bullet_prnt()
	{
		
	}
	

	~Tank()
	{
	}
};

