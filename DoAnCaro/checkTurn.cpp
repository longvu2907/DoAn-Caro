#include "checkTurn.h"

int initTurn()
{
	unsigned int initTurn;
	srand(time(NULL));
	initTurn = rand() % 2 + 1;
	return initTurn;
}
int swapTurn(int turn)
{
	if (turn == 1) turn = 2;
	else turn = 1;
	return turn;
}
void oTurn(int x,int y,int turn)
{
	if (turn == 1)
	{
		gotoXY(9, 2);
		cout << " ";
		gotoXY(9, 2);
		cout << "X";
		gotoXY(x, y);
	}
	else
	{
		gotoXY(9, 2);
		cout << " ";
		gotoXY(9, 2);
		cout << "O";
		gotoXY(x, y);
	}
}