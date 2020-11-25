#include "checkTurn.h"

int initTurn()
{
	unsigned int initTurn;
	initTurn = rand() % 2 + 1;
	return initTurn;
}
int swapTurn(int turn)
{
	if (turn == 1) turn = 2;
	else turn = 1;
	return turn;
}
void oTurn(int x,int y,int turn, string p1, string p2)
{
	if (turn == 1)
	{
		AnConTro();
		gotoXY(9, 2);
		for (int i = 1; i <= 15; i++)
		{
			
			cout << " ";
		}
		Textcolor(Red);
		gotoXY(9, 2);
		cout << p1;
		gotoXY(x, y);
		HienConTro();
	}
	else
	{
		gotoXY(9, 2);
		for (int i = 1; i <= 15; i++)
		{
			cout << " ";
		}
		AnConTro();
		Textcolor(Blue);
		gotoXY(9, 2);
		cout << p2;
		gotoXY(x, y);
		HienConTro();
	}
}