#include "Menu.h"

void FixConsoleWindow()
{

	HWND consoleWindow = GetConsoleWindow();

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);

	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Menu()
{
	FixConsoleWindow();
	int x(30), y(5);
	gotoXY(x, y); cout << "New Game";
	gotoXY(x, y + 1); cout << "Load Game";
	gotoXY(x, y + 2); cout << "About";
	gotoXY(x, y + 3); cout << "Exit";
	char k;
	int value;
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
				if (y > 5) { y--; gotoXY(x, y); } break;
			}
			else if (value == 80)
			{
				if (y < 8) { y++; gotoXY(x, y); } break;
			}
			break;
		case 13:
			if (y == 5)
			{
				system("cls");
				gotoXY(30, 9); cout << "0 %";
				gotoXY(75, 9); cout << "100 %";
				gotoXY(30, 10);
				for (int i(1); i <= 50; i++)
				{
					cout << char(219);
					Sleep(100);
				}
				gotoXY(30, 12); cout << "Intitalizing";
				k = 0;
				while (1)
				{
					gotoXY(42, 12);
					for (int i(1); i <= 5; i++)
					{
						cout << ".";
						Sleep(100);
					}
					gotoXY(42, 12);
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
						return;
					}
				}
			}
			else if (y == 6)
			{
				system("cls");
				gotoXY(30, 9); cout << "0 %";
				gotoXY(75, 9); cout << "100 %";
				gotoXY(30, 10);
				for (int i(1); i <= 50; i++)
				{
					cout << char(219);
					Sleep(100);
				}
				gotoXY(30, 12); cout << "Intitalizing";
				k = 0;
				while (1)
				{
					gotoXY(42, 12);
					for (int i(1); i <= 5; i++)
					{
						cout << ".";
						Sleep(100);
					}
					gotoXY(42, 12);
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
						return;
					}
				}
			}
			else if (y == 7)
			{
				system("cls");

				gotoXY(53, 3); cout << "About";


				gotoXY(48, 7); cout << "Nguyen Long Vu";
				gotoXY(52, 8); cout << "20CTT3";
				gotoXY(48, 9); cout << "MSSV: 20120405";
				gotoXY(45, 10); cout << "Giao vien huong dan:";
				gotoXY(47, 11); cout << "Truong Toan Thinh";

			}
			else if (y == 8)
			{
				exit(0);
			}
		}
	}
}