#include "Board.h"

void DrawBoard(int k1, int k2, int set, int mode, string p1, string p2)
{
	system("cls");
	gotoXY(51, 7);
	if (k1 == (mode - 1) || k2 == (mode - 1))
	{
		cout << "MATCH POINT";
		Sleep(1000);
		system("cls");
	}
	else
	{
		cout << "MATCH " << set;
		Sleep(1000);
		system("cls");
	}
	//Top Line
	gotoXY(3, 3); cout << char(201);
	Sleep(10);
	for (int i(1); i <= 47; i++)
	{
		if (i % 4 == 0)
		{
			cout << char(203);
			Sleep(10);
		}
		else cout << char(205);
	}
	cout << char(187);
	Sleep(1);
	//Right Line
	for (int i(4); i <= 26; i++)
	{
		if (i % 2 != 0)
		{
			gotoXY(51, i);
			cout << char(185);
		}
		else { gotoXY(51, i); cout << char(186); }
		Sleep(10);
	}
	gotoXY(51, 27);
	cout << char(188);
	Sleep(1);
	//Bot Line
	for (int i(50), k(1); i > 3; i--, k++)
	{
		if (k == 4)
		{
			gotoXY(i, 27);
			cout << char(202);
			k = 0;
			Sleep(10);
			continue;
		}
		gotoXY(i, 27);
		cout << char(205);
		Sleep(10);
	}
	gotoXY(3, 27);
	cout << char(200);
	Sleep(1);
	//Left Line
	for (int i(26); i > 3; i--)
	{
		if (i % 2 != 0)
		{
			gotoXY(3, i);
			cout << char(204);
		}
		else
		{
			gotoXY(3, i);
			cout << char(186);
		}
		Sleep(30);
	}
	//Inside
	for (int i(4); i <= 26; i++)
	{
		if (i % 2 == 1)
		{
			for (int j(4), k(1); j < 51; j++, k++)
			{
				gotoXY(j, i);
				if (k == 4)
				{
					cout << char(206);
					k = 0;
				}
				else cout << char(205);
			}
		}
		else
		{
			for (int j(7); j < 48; j += 4)
			{
				gotoXY(j, i);
				cout << char(186);
			}
		}
	}
	//print CARO
	int x = 65, y =4;
	Textcolor(DarkBlue);
	gotoXY(x, y);				  cout << "oooooo";
	gotoXY(x - 3, y + 1);	   cout << "ooooooooo";
	gotoXY(x - 5, y + 2);    cout << "ooooooooooo";
	gotoXY(x - 6, y + 3);  cout << "oooooo";
	gotoXY(x - 7, y + 4); cout << "oooooo";
	gotoXY(x - 8, y + 5); cout << "oooooo";
	gotoXY(x - 8, y + 6); cout << "oooooo";	
	gotoXY(x - 8, y + 7); cout << "oooooo";
	gotoXY(x - 7, y + 8); cout << "oooooo";
	gotoXY(x - 6, y + 9);  cout << "oooooooooooo";
	gotoXY(x - 5, y + 10);   cout << "ooooooooooo";
	gotoXY(x - 3, y + 11);		cout << "ooooooooo";
	Textcolor(DarkRed);
	gotoXY(x - 9 + 22, y );					cout << "ooooooo";
	gotoXY(x - 9 + 22 - 2, y + 1);		  cout << "oooooooooo";
	gotoXY(x - 9 + 22 - 3, y + 2);		 cout << "oooooooooooo";
	gotoXY(x - 9 + 22 - 3, y + 3);		 cout << "oooooooooooo";
	gotoXY(x - 9 + 22 - 3, y + 4);		 cout << "oooo    oooo";
	gotoXY(x - 9 + 22 - 3, y + 5);		 cout << "oooo    oooo";
	gotoXY(x - 9 + 22 - 3, y + 6);		 cout << "oooo    oooo";
	gotoXY(x - 9 + 22 - 3, y + 7);		 cout << "oooooooooooo";
	gotoXY(x - 9 + 22 - 3, y + 8);		 cout << "oooo    oooo";
	gotoXY(x - 9 + 22 - 3, y + 9);		 cout << "oooo    oooo";
	gotoXY(x - 9 + 22 - 3, y + 10);		 cout << "oooo    oooo";
	gotoXY(x - 9 + 22 - 3, y + 11);		 cout << "oooo    oooo";
	Textcolor(DarkBlue);
	gotoXY(x + 26, y );			    cout << "ooo  oooo";
	gotoXY(x + 26, y + 1);			cout << "oooooooooo";
	gotoXY(x + 26, y + 2);			cout << "ooooooooooo";
	gotoXY(x + 26, y + 3);			cout << "oooooooooooo";
	gotoXY(x + 1 + 26, y + 4);		 cout << "oooo   oooo";
	gotoXY(x + 1 + 26, y + 5);		 cout << "oooo   oooo";
	gotoXY(x + 1 + 26, y + 6);		 cout << "oooo";
	gotoXY(x + 1 + 26, y + 7);		 cout << "oooo";
	gotoXY(x + 1 + 26, y + 8);		 cout << "oooo";
	gotoXY(x + 1 + 26, y + 9);		 cout << "oooo";
	gotoXY(x + 1 + 26, y + 10);	     cout << "oooo";
	gotoXY(x + 1 + 26, y + 11);	     cout << "oooo";
	Textcolor(DarkRed);
	gotoXY(x + 57 - 13, y);				   cout << "oooooo";
	gotoXY(x + 57 - 15, y + 1);			 cout << "oooooooooo";
	gotoXY(x + 57 - 16, y + 2);			 cout << "oooooooooooo";
	gotoXY(x + 57 - 16, y + 3);			 cout << "oooooooooooo";
	gotoXY(x + 57 - 16, y + 4);			 cout << "oooo    oooo";
	gotoXY(x + 57 - 16, y + 5);			 cout << "oooo    oooo";
	gotoXY(x + 57 - 16, y + 6);			 cout << "oooo    oooo";
	gotoXY(x + 57 - 16, y + 7);			 cout << "oooo    oooo";
	gotoXY(x + 57 - 16, y + 8);			 cout << "oooooooooooo";
	gotoXY(x + 57 - 16, y + 9);			 cout << "oooooooooooo";
	gotoXY(x + 57 - 15, y + 10);		 cout <<  "oooooooooo";
	gotoXY(x + 57 - 13, y + 11);			cout << "oooooo";

	Textcolor(DarkGreen);
	gotoXY(x, y + 15); cout << "W A S D: MOVE";
	gotoXY(x, y + 16); cout << "ENTER: TICK";
	gotoXY(x, y + 17); cout << "ESC: PAUSE GAME";

	gotoXY(30, 2);
	Textcolor(Red);
	cout << p1 << " ";
	cout << k1;
	Textcolor(White);
	cout << " - ";
	Textcolor(Blue);
	cout << k2;
	cout << " "<< p2;
	Textcolor(White);
	gotoXY(3, 2); cout << "Turn: ";
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}