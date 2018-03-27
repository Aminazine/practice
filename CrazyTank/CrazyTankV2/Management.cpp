#include "stdafx.h"
#include "conio.h"
#include "Management.h"

Direction Move::control()
{
	int key = _getch();

	if (key == 224) {
		key = _getch();
		if (key == 72) {
			move = UP;
			return move;
		}
		if (key == 80) {
			move = DOWN;
			return move;
		}
		if (key == 75) {
			move = LEFT;
			return move;
		}
		if (key == 77) {
			move = RIGHT;
			return move;
		}
//		if (key == 32) {
//			gameOver = true;	*/		
//		}
	}		
};
