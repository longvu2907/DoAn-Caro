#include "Start.h"

int a[60][60] = {};

void Play(int& k1, int& k2,int & set, int mode,int turn)
{
	char k;
	int value;
	int x(5), y(4);
	gotoXY(x, y); 
	while (1)
	{
		oTurn(x,y,turn);
		k = _getch();
		value = k;
		if (value == -32)
		{
			value = _getch();
			switch (value)
			{
			case 72:
				if (y > 4) y -= 2;
				gotoXY(x, y);
				break;
			case 75:
				if (x > 5) x -= 4;
				gotoXY(x, y);
				break;
			case 77:
				if (x < 49) x += 4;
				gotoXY(x, y);
				break;
			case 80:
				if (y < 26) y += 2;
				gotoXY(x, y);
				break;
			}
		}
		else if (value == 13)
		{
			tickXO(x, y, turn);
			gotoXY(x, y);
			if (checkXO()==1)
			{
				k1++;
				Sleep(1000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				if (k1 == mode)
				{
					system("cls");
					gotoXY(47, 3);
					cout << "PLAYER X WIN !!!!";
					gotoXY(47, 6); cout << "MAIN MENU";
					gotoXY(47, 7); cout << "PLAY AGAIN";
					gotoXY(47, 8); cout << "QUIT GAME";
					x = 47;
					y = 6;
					while (1)
					{
						gotoXY(x, y);
						k = _getch();
						value = k;
						switch (value)
						{
						case -32:
							value = _getch();
							if (value == 72)
							{
								if (y > 6) { y--; gotoXY(x, y); } break;
							}
							else if (value == 80)
							{
								if (y < 8) { y++; gotoXY(x, y); } break;
							}
							break;
						case 13:
							if (y == 6) Start();
							else if (y == 7) NewGame(0, 0, 1);
							else if (y == 8) exit(0);
						}
					}
				}
				
				set++;
				DrawBoard(k1, k2, set);
				resetBoard();
				Play(k1, k2, set, mode,turn);
			}
			else if (checkXO() == 2)
			{
				k2++;
				Sleep(1000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				if (k2 == mode)
				{
					system("cls");
					gotoXY(47, 3);
					cout << "PLAYER O WIN !!!!";
					gotoXY(47, 6); cout << "MAIN MENU";
					gotoXY(47, 7); cout << "PLAY AGAIN";
					gotoXY(47, 8); cout << "QUIT GAME";
					x = 47;
					y = 6;
					while (1)
					{
						gotoXY(x, y);
						k = _getch();
						value = k;
						switch (value)
						{
						case -32:
							value = _getch();
							if (value == 72)
							{
								if (y > 6) { y--; gotoXY(x, y); } break;
							}
							else if (value == 80)
							{
								if (y < 8) { y++; gotoXY(x, y); } break;
							}
							break;
						case 13:
							if (y == 6) Start();
							else if (y == 7) NewGame(0, 0, 1);
							else if (y == 8) exit(0);
						}
					}
				}
				
				set++;
				DrawBoard(k1, k2, set);
				resetBoard();
				Play(k1, k2, set, mode,turn);
			}
		}
	}
}
void tickXO(int x, int y, int& turn)
{

	if (a[x][y] == 1 || a[x][y] == 2) return;
	else if (turn == 1)
	{
		a[x][y] = 1;
		cout << "X";
		turn = swapTurn(turn);
	}
	else if (turn== 2)
	{
		a[x][y] = 2;
		cout << "O";
		turn = swapTurn(turn);
	}
	
}
int checkXO()
{
	int check;
	for (int i(5); i <= 49; i += 4)
	{
		for (int j(4); j <= 26; j += 2)
		{
			if (a[i][j] == 1 && a[i + 4][j] == 1 && a[i + 8][j] == 1 && a[i + 12][j] == 1 && a[i + 16][j] == 1) return 1;
			else if (a[i][j] == 1 && a[i][j + 2] == 1 && a[i][j + 4] == 1 && a[i][j + 6] == 1 && a[i][j + 8] == 1) return 1;
			else if (a[i][j] == 1 && a[i + 4][j + 2] == 1 && a[i + 8][j + 4] == 1 && a[i + 12][j + 6] == 1 && a[i + 16][j + 8] == 1) return 1;
			else if (a[i][j] == 1 && a[i + 4][j - 2] == 1 && a[i + 8][j - 4] == 1 && a[i + 12][j - 6] == 1 && a[i + 16][j - 8] == 1) return 1;
			if (a[i][j] == 2 && a[i + 4][j] == 2 && a[i + 8][j] == 2 && a[i + 12][j] == 2 && a[i + 16][j] == 2) return 2;
			else if (a[i][j] == 2 && a[i][j + 2] == 2 && a[i][j + 4] == 2  && a[i][j + 6] == 2 && a[i][j + 8] == 2) return 2;
			else if (a[i][j] == 2 && a[i + 4][j + 2] == 2 && a[i + 8][j + 4] == 2 && a[i + 12][j + 6] == 2 && a[i + 16][j + 8] == 2) return 2;
			else if (a[i][j] == 2 && a[i + 4][j - 2] == 2 && a[i + 8][j - 4] == 2 && a[i + 12][j - 6] == 2 && a[i + 16][j - 8] == 2) return 2;
			else check = 0;
		}
	}
	return check;
}

void resetBoard()
{
	for (int i(5); i <= 49; i += 4)
	{
		for (int j(4); j <= 26; j += 2)
		{
			a[i][j] = 0;
		}
	}
}
void init(int turn)
{
	string first;
	system("cls");
	gotoXY(46, 8); cout << "Initializing ";
	for (int i(1); i <= 5;i++)
	{
		gotoXY(58, 8);
		for (int i(1); i <= 5; i++)
		{
			cout << ".";
			Sleep(100);
		}
		gotoXY(58, 8);
		for (int i(1); i <= 5; i++)
		{
			cout << " ";
		}
	}
	system("cls");
	if (initTurn() == 1) first = "X";
	else if (initTurn() == 2) first = "O";
	gotoXY(46, 8); cout << "PLAYER " << first << " GO FIRST";
	Sleep(2000);
}