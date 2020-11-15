#include "mainMenu.h"


char k;
int value;
char name1, name2;

void mainMenu()
{
	system("cls");
	int x(51), y(7);
	AnConTro();	
	gotoXY(x, y);
	while (1)
	{
		if (y == 7)
		{
			Textcolor(Cyan);
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			Textcolor(White);
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			gotoXY(x, 9); cout << "LOAD GAME";
			gotoXY(x, 10); cout << "ABOUT";
			gotoXY(x, 11); cout << "EXIT";
		}
		if (y == 8)
		{
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			Textcolor(Cyan);
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			Textcolor(White);
			gotoXY(x, 9); cout << "LOAD GAME";
			gotoXY(x, 10); cout << "ABOUT";
			gotoXY(x, 11); cout << "EXIT";
		}
		if (y == 9)
		{
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			Textcolor(Cyan);
			gotoXY(x, 9); cout << "LOAD GAME";
			Textcolor(White);
			gotoXY(x, 10); cout << "ABOUT";
			gotoXY(x, 11); cout << "EXIT";
		}
		if (y == 10)
		{
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			gotoXY(x, 9); cout << "LOAD GAME";
			Textcolor(Cyan);
			gotoXY(x, 10); cout << "ABOUT";
			Textcolor(White);
			gotoXY(x, 11); cout << "EXIT";
		}
		if (y == 11)
		{
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			gotoXY(x, 9); cout << "LOAD GAME";
			gotoXY(x, 10); cout << "ABOUT";
			Textcolor(Cyan);
			gotoXY(x, 11); cout << "EXIT";
			Textcolor(White);
		}
		k = _getch();
		value = k;
		switch (value)
		{
		case 119:
			if (y > 7) { y--; gotoXY(x, y); }
			break;
		case 115:
			if (y < 11) { y++; gotoXY(x, y); }
			break;
		case -32:
			value = _getch();
			if (value == 72)
			{
				if (y > 7) { y--; gotoXY(x, y); } 
				break;
			}
			else if (value == 80)
			{
				if (y < 11) { y++; gotoXY(x, y); } 
				break;
			}
			break;
		case 13:
			if (y == 7)
			{
				int k1(0), k2(0), set(1);
				NewGame(k1, k2, set);
				break;
			}
			else if (y == 8||y == 9)
			{
				LoadGame();
			}
			else if (y == 10)
			{
				About();
			}
			else if (y == 11)
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
	int turn = initTurn();
	init(turn);
	DrawBoard(k1, k2, set, mode);
	resetBoard();
	Play(k1, k2, set, mode,turn);
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
		if (i == 25) Sleep(3000);
		Sleep(100);
	}
	system("cls");
	gotoXY(48, 15);
	cout << "Tinh nang dang phat trien.";
	if (_getch()) mainMenu();
}
void NLV()
{
	gotoXY(53, 3); cout << "CONTACT FOR WORK:";
	gotoXY(48, 7); cout << "NGUYEN LONG VU";
	gotoXY(48, 8); cout << "PHONE: 0356436545";
	gotoXY(48, 9); cout << "GMAIL: longvu2907@gmail.com";
	gotoXY(48, 10); cout << "FB: fb.com/longvu2907"; 
	
}
void TTT()
{
	gotoXY(53, 3); cout << "CONTACT FOR WORK:";
	gotoXY(48, 7); cout << "TRUONG TOAN THINH";
	gotoXY(48, 8); cout << "PHONE: ";
	gotoXY(48, 9); cout << "GMAIL: ttthinh@fit.hcmus.edu.vn";
	gotoXY(48, 10); cout << "FB: ";

}
void About()
{
	system("cls");
	int x(48), y(7);
	while (1)
	{
		if (y == 7)
		{
			gotoXY(53, 3); cout << "ABOUT";
			Textcolor(Cyan);
			gotoXY(48, 7); cout << "NGUYEN LONG VU";
			Textcolor(White);
			gotoXY(52, 8); cout << "20CTT3";
			gotoXY(48, 9); cout << "MSSV: 20120405";
			gotoXY(46, 10); cout << "GIAO VIEN HUONG DAN ";
			gotoXY(47, 11); cout << "TRUONG TOAN THINH";
			gotoXY(53, 15); cout << "BACK";
		}
		else if (y == 11)
		{
			gotoXY(53, 3); cout << "ABOUT";
			gotoXY(48, 7); cout << "NGUYEN LONG VU";
			gotoXY(52, 8); cout << "20CTT3";
			gotoXY(48, 9); cout << "MSSV: 20120405";
			gotoXY(46, 10); cout << "GIAO VIEN HUONG DAN ";
			Textcolor(Cyan);
			gotoXY(47, 11); cout << "TRUONG TOAN THINH";
			Textcolor(White);
			gotoXY(53, 15); cout << "BACK";
		}
		else if (y == 15)
		{
			gotoXY(53, 3); cout << "ABOUT";
			gotoXY(48, 7); cout << "NGUYEN LONG VU";
			gotoXY(52, 8); cout << "20CTT3";
			gotoXY(48, 9); cout << "MSSV: 20120405";
			gotoXY(46, 10); cout << "GIAO VIEN HUONG DAN ";
			gotoXY(47, 11); cout << "TRUONG TOAN THINH";
			Textcolor(Cyan);
			gotoXY(53, 15); cout << "BACK";
			Textcolor(White);
		}
		gotoXY(x, y);
		k = _getch();
		value = k;
		switch (value)
		{
		case 119:
			if (y > 7) { y -= 4; gotoXY(x, y); }
			break;
		case 115:
			if (y < 15) { y += 4; gotoXY(x, y); }
			break;
		case -32:
			value = _getch();
			if (value == 72)
			{
				if (y > 7) { y -= 4; gotoXY(x, y); }
				break;
			}
			else if (value == 80)
			{
				if (y < 15) { y += 4; gotoXY(x, y); }
				break;
			}
			break;
		case 13:
			if (y == 7)
			{
				system("cls");
				NLV();
				while (_getch())
				{
					About();
				}
			}
			if (y == 11)
			{
				system("cls");
				TTT();
				while (_getch())
				{
					About();
				}
			}
			if (y == 15)
			{
				mainMenu();
			}
		}
	}
}
int Mode()
{
	int mode;	
	int x(54), y(8);
	system("cls");
	gotoXY(x, y);
	while (1)
	{
		if (y == 8)
		{
			Textcolor(Cyan);
			gotoXY(54, 8); cout << "BO1\n";
			Textcolor(White);
			gotoXY(54, 9); cout << "BO3\n";
			gotoXY(54, 10); cout << "BO5\n";
		}
		if (y == 9)
		{
			gotoXY(54, 8); cout << "BO1\n";
			Textcolor(Cyan);
			gotoXY(54, 9); cout << "BO3\n";
			Textcolor(White);
			gotoXY(54, 10); cout << "BO5\n";
		}
		if (y == 10)
		{
			gotoXY(54, 8); cout << "BO1\n";
			gotoXY(54, 9); cout << "BO3\n";
			Textcolor(Cyan);
			gotoXY(54, 10); cout << "BO5\n";
			Textcolor(White);
		}
		k = _getch();
		value = k;
		switch (value)
		{
		case -32:
			value = _getch();
			if (value == 72)
			{
				if (y > 8) { y--; gotoXY(x, y); } 
				break;
			}
			else if (value == 80)
			{
				if (y < 10) { y++; gotoXY(x, y); }
				break;
			}
			break;
		case 119:
			if (y > 8) { y--; gotoXY(x, y); }
			break;
		case 115:
			if (y < 10) { y++; gotoXY(x, y); }
			break;
		case 13:
			if (y == 8) return 1; 
			else if (y == 9) return 3; 
			else if (y == 10) return 5;
		}
	}
}
