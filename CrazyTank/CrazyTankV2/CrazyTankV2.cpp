// CrazyTankV2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <Windows.h>
#include "MainField.h"
#include "BatleField.h"



int main()
{
	srand(time(0));

	BatleField obj;
	obj.setBoarder();
	while (true) {

		obj.playerMove();
	}
    return 0;
}

