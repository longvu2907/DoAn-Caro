#include "mainMenu.h"


char k;
int value;

void mainMenu()
{
	int x(51), y(7);

	gotoXY(x, y); cout << "NEW GAME";
	gotoXY(x, y + 1); cout << "LOAD GAME";
	gotoXY(x, y + 2); cout << "ABOUT";
	gotoXY(x, y + 3); cout << "EXIT";
	
	gotoXY(x, y);
	while (1)
	{
		k = _getch();
		value = k;
		switch (value)
		{
		case -32:
			value = _getch();
			if (value == 72)
			{
				if (y > 7) { y--; gotoXY(x, y); } break;
			}
			else if (value == 80)
			{
				if (y < 10) { y++; gotoXY(x, y); } break;
			}
			break;
		case 13:
			if (y == 7)
			{
				NewGame();
				break;
			}
			else if (y == 8)
			{
				LoadGame();
			}
			else if (y == 9)
			{
				About();
			}
			else if (y == 10)
			{
				system("cls");
				exit(0);
			}
		}
	}
}

void NewGame()
{
	system("cls");
	DrawBoard();
	Play();
}
void LoadGame()
{
	system("cls");
	gotoXY(35, 9); cout << "0 %";
	gotoXY(80, 9); cout << "100 %";
	gotoXY(35, 10);
	for (int i(1); i <= 50; i++)
	{
		cout << char(219);
		Sleep(100);
	}
	gotoXY(35, 12); cout << "Intitalizing";
	k = 0;
	while (1)
	{
		gotoXY(47, 12);
		for (int i(1); i <= 5; i++)
		{
			cout << ".";
			Sleep(100);
		}
		gotoXY(47, 12);
		for (int i(1); i <= 5; i++)
		{
			cout << " ";
		}
		k++;
		if (k == 20)
		{
			system("cls");
			gotoXY(48, 15);
			cout << "Tinh nang dang phat trien.";
			gotoXY(0, 30);
			exit(0);
		}
	}
}
void About()
{
	system("cls");

	gotoXY(53, 3); cout << "ABOUT";


	gotoXY(48, 7); cout << "NGUYEN LONG VU";
	gotoXY(52, 8); cout << "20CTT3";
	gotoXY(48, 9); cout << "MSSV: 20120405";
	gotoXY(45, 10); cout << "GIAO VIEN HUONG DAN:";
	gotoXY(47, 11); cout << "TRUONG TOAN THINH";


	gotoXY(53, 15); cout << "BACK";
	while (1)
	{
		value = _getch();
		if (value != 13) gotoXY(53, 15);
		else if (value == 13)
		{
			system("cls");
			mainMenu();
		}
	}
}

