#include "Board.h"

void DrawBoard(int k1, int k2, int set,int mode)
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
	for (int i(50),k(1); i >3; i--,k++)
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
	for (int i(26); i >3; i--) 
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
	gotoXY(25, 2); 
	Textcolor(Red);
	cout << k1;
	Textcolor(White);
	cout << " - ";
	Textcolor(Blue);
	cout<< k2;
	Textcolor(White);
	gotoXY(3, 2); cout << "Turn: ";
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}