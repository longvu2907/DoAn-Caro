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
				if (y < 11) { y++; gotoXY(x, y); } break;
			}
			break;
		case 13:
			if (y == 7)
			{
				int k1(0), k2(0), set(1);
				NewGame(k1, k2, set);
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


void NewGame(int k1, int k2 ,int set)
{
	int mode;
	mode = Mode();
	DrawBoard(k1,k2,set);
	resetBoard();
	Play(k1, k2, set, mode);
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
			Sleep(2000);
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
int Mode()
{
	int mode;
	system("cls");
	gotoXY(54, 8); cout << "BO1\n";
	gotoXY(54, 9); cout << "BO3\n";
	gotoXY(54, 10); cout << "BO5\n";
	int x(54), y(8);
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
				if (y > 8) { y--; gotoXY(x, y); } break;
			}
			else if (value == 80)
			{
				if (y < 10) { y++; gotoXY(x, y); } break;
			}
			break;
		case 13:
			if (y == 8) return 1; 
			else if (y == 9) return 3; 
			else if (y == 10) return 5;
		}
	}
}
