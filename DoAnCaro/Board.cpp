#include "Board.h"

void DrawBoard()
{
	gotoXY(3, 3); cout << char(201);
	for (int i(1); i <= 47; i++)
	{
		if (i % 4 == 0)
		{
			cout << char(203);
			for (int j(4); j <= 27; j++)
			{
				if (j % 2 != 0) 
				{
					gotoXY(i - 1, j);
					cout << char(206);
				}
				else
				{
					gotoXY(i - 1, j);
					cout << char(186);
				}
			}
		}
		else cout << char(205);
	}
	cout << char(187);
	for (int i(4); i <= 27; i++) 
	{
		if (i % 2 != 0) 
		{ 
			gotoXY(3, i);
			cout << char(204); 
			for (int i(1); i <= 48; i++)
			{
				if (i % 4 == 0)cout << char(206);
				else cout << char(205);
			}
		}
		else { gotoXY(3, i); cout << char(186); }
		 
	}
	gotoXY(3, 27); cout << char(200);
	for (int i(1); i <= 47; i++)
	{
		if (i % 4 == 0)
		{
			cout << char(202);
		}
		else cout << char(205);
	}
	cout << char(188);
	for (int i(4); i <= 26; i++)
	{
		{
			if (i % 2 != 0)
			{
				gotoXY(51, i);
				cout << char(185);
			}
			else { gotoXY(51, i); cout << char(186); }

		}
	}
	gotoXY(8, 3);
	for (int i(1); i <= 43;i++)
	{
		if (i % 4 == 0) cout << char(203);
		else cout << char(205);
	}
	gotoXY(51, 3); cout << char(187);
	for (int i(4); i <= 26; i++)
	{
		if (i % 2 != 0)
		{
			gotoXY(47,i);
			cout << char(206);
		}
		else
		{
			gotoXY(47, i);
			cout << char(186);
		}
	}
	gotoXY(47, 3);
}