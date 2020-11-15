#include "Start.h"

int a[60][60] = {};

void Play(int& k1, int& k2,int & set, int mode,int turn)
{
	HienConTro();
	char k;
	int value;
	int x(5), y(4);
	gotoXY(x, y); 
	while (1)
	{
		oTurn(x,y,turn);
		k = _getch();
		value = k;
		if (value == -32 )
		{
			value = _getch();
			switch (value)
			{
			case 72:
			case 119:
				if (y > 4) y -= 2;
				gotoXY(x, y);
				break;
			case 75:
			case 97:
				if (x > 5) x -= 4;
				gotoXY(x, y);
				break;
			case 77:
			case 100:
				if (x < 49) x += 4;
				gotoXY(x, y);
				break;
			case 80:
			case 115:
				if (y < 26) y += 2;
				gotoXY(x, y);
				break;
			}
		}
		else if (value == 115 || value == 97 || value == 100 || value == 119)
		{
			switch (value)
			{
			case 119:
				if (y > 4) y -= 2;
				gotoXY(x, y);
				break;
			case 97:
				if (x > 5) x -= 4;
				gotoXY(x, y);
				break;
			case 100:
				if (x < 49) x += 4;
				gotoXY(x, y);
				break;
			case 115:
				if (y < 26) y += 2;
				gotoXY(x, y);
				break;
			}
		}
		else if (value == 13)
		{
			tickXO(x, y, turn);
			gotoXY(x, y);
			if (checkXO() == 1)
			{
				k1++;
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				if (k1 == mode)
				{
					system("cls");
					AnConTro();
					gotoXY(47, 7);
					Textcolor(Red);
					cout << "PLAYER X WIN !!!!";
					Textcolor(White);
					x = 47;
					y = 10;
					while (1)
					{
						if (y == 10)
						{
							Textcolor(Cyan);
							gotoXY(47, 10); cout << "MAIN MENU";
							Textcolor(White);
							gotoXY(47, 11); cout << "PLAY AGAIN";
							gotoXY(47, 12); cout << "QUIT GAME";
						}
						else if (y == 11)
						{							
							gotoXY(47, 10); cout << "MAIN MENU";
							Textcolor(Cyan);
							gotoXY(47, 11); cout << "PLAY AGAIN";
							Textcolor(White);
							gotoXY(47, 12); cout << "QUIT GAME";
						}
						else if (y == 12)
						{					
							gotoXY(47, 10); cout << "MAIN MENU";					
							gotoXY(47, 11); cout << "PLAY AGAIN";
							Textcolor(Cyan);
							gotoXY(47, 12); cout << "QUIT GAME";
							Textcolor(White);
						}
						gotoXY(x, y);
						k = _getch();
						value = k;
						switch (value)
						{
						case -32:
							value = _getch();
							if (value == 72)
							{
								if (y > 10) { y--; gotoXY(x, y); } break;
							}
							else if (value == 80)
							{
								if (y < 12) { y++; gotoXY(x, y); } break;
							}
							break;
						case 119:
							if (y > 10) { y--; gotoXY(x, y); }
							break;
						case 115:
								if (y < 12) { y++; gotoXY(x, y); } 
							break;
						case 13:
							if (y == 10) Start();
							else if (y == 11) NewGame(0, 0, 1);
							else if (y == 12) exit(0);
						}
					}
				}
				
				set++;
				DrawBoard(k1, k2, set, mode);
				resetBoard();
				Play(k1, k2, set, mode,turn);
			}
			else if (checkXO() == 2)
			{
				k2++;
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				if (k2 == mode)
				{
					system("cls");
					AnConTro();
					gotoXY(47, 7);
					Textcolor(Blue);
					cout << "PLAYER O WIN !!!!";
					Textcolor(White);
					x = 47;
					y = 10;
					while (1)
					{
						if (y == 10)
						{
							Textcolor(Cyan);
							gotoXY(47, 10); cout << "MAIN MENU";
							Textcolor(White);
							gotoXY(47, 11); cout << "PLAY AGAIN";
							gotoXY(47, 12); cout << "QUIT GAME";
						}
						else if (y == 11)
						{
							gotoXY(47, 10); cout << "MAIN MENU";
							Textcolor(Cyan);
							gotoXY(47, 11); cout << "PLAY AGAIN";
							Textcolor(White);
							gotoXY(47, 12); cout << "QUIT GAME";
						}
						else if (y == 12)
						{
							gotoXY(47, 10); cout << "MAIN MENU";
							gotoXY(47, 11); cout << "PLAY AGAIN";
							Textcolor(Cyan);
							gotoXY(47, 12); cout << "QUIT GAME";
							Textcolor(White);
						}
						gotoXY(x, y);
						k = _getch();
						value = k;
						switch (value)
						{
						case -32:
							value = _getch();
							if (value == 72)
							{
								if (y > 10) { y--; gotoXY(x, y); } break;
							}
							else if (value == 80)
							{
								if (y < 12) { y++; gotoXY(x, y); } break;
							}
							break;
						case 119:
							if (y > 10) { y--; gotoXY(x, y); }
							break;
						case 115:
							if (y < 12) { y++; gotoXY(x, y); }
							break;
						case 13:
							if (y == 10) Start();
							else if (y == 11) NewGame(0, 0, 1);
							else if (y == 12) exit(0);
						}
					}
				}
				
				set++;
				DrawBoard(k1, k2, set, mode);
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
		Textcolor(Red);
		cout << "X";
		turn = swapTurn(turn);
	}
	else if (turn== 2)
	{
		a[x][y] = 2;
		Textcolor(Blue);
		cout << "O";
		turn = swapTurn(turn);
	}
	Textcolor(White);
}
int checkXO()
{
	int check;
	for (int i(5); i <= 49; i += 4)
	{
		for (int j(4); j <= 26; j += 2)
		{
			if (a[i][j] == 1 && a[i + 4][j] == 1 && a[i + 8][j] == 1 && a[i + 12][j] == 1 && a[i + 16][j] == 1)
			{
				AnConTro();
				for (int k(1); k <= 10; k++)
				{
					gotoXY(i, j); cout << " ";
					gotoXY(i + 4, j); cout << " ";
					gotoXY(i + 8, j); cout << " ";
					gotoXY(i + 12, j); cout << " ";
					gotoXY(i + 16, j); cout << " ";
					Sleep(100);
					gotoXY(i, j); cout << "X";
					gotoXY(i + 4, j); cout << "X";
					gotoXY(i + 8, j); cout << "X";
					gotoXY(i + 12, j); cout << "X";
					gotoXY(i + 16, j); cout << "X";
					Sleep(100);
				}
				HienConTro();
				return 1;
			}
			else if (a[i][j] == 1 && a[i][j + 2] == 1 && a[i][j + 4] == 1 && a[i][j + 6] == 1 && a[i][j + 8] == 1) 
			{
				AnConTro();
				for (int k(1); k <= 10; k++)
				{
					gotoXY(i, j); cout << " ";
					gotoXY(i, j + 2); cout << " ";
					gotoXY(i, j + 4); cout << " ";
					gotoXY(i, j + 6); cout << " ";
					gotoXY(i, j + 8); cout << " ";
					Sleep(100);
					gotoXY(i, j); cout << "X";
					gotoXY(i, j + 2); cout << "X";				
					gotoXY(i, j + 4); cout << "X";
					gotoXY(i, j + 6); cout << "X";
					gotoXY(i, j + 8); cout << "X";	
					Sleep(100);
				}
				HienConTro();
				return 1;
			}
			else if (a[i][j] == 1 && a[i + 4][j + 2] == 1 && a[i + 8][j + 4] == 1 && a[i + 12][j + 6] == 1 && a[i + 16][j + 8] == 1)
			{
				AnConTro();
				for (int k(1); k <= 10; k++)
				{
					gotoXY(i, j); cout << " ";	
					gotoXY(i + 4, j + 2); cout << " ";
					gotoXY(i + 8, j + 4); cout << " ";
					gotoXY(i + 12, j + 6); cout << " ";
					gotoXY(i + 16, j + 8); cout << " ";
					Sleep(100);
					gotoXY(i, j); cout << "X";
					gotoXY(i + 4, j + 2); cout << "X";;
					gotoXY(i + 8, j + 4); cout << "X";
					gotoXY(i + 12, j + 6); cout << "X";				
					gotoXY(i + 16, j + 8); cout << "X";
					Sleep(100);
				}
				HienConTro();
				return 1;
			}
			else if (a[i][j] == 1 && a[i + 4][j - 2] == 1 && a[i + 8][j - 4] == 1 && a[i + 12][j - 6] == 1 && a[i + 16][j - 8] == 1) 
			{
				AnConTro();
				for (int k(1); k <= 10; k++)
				{
					gotoXY(i, j); cout << " ";	
					gotoXY(i + 4, j - 2); cout << " ";	
					gotoXY(i + 8, j - 4); cout << " ";
					gotoXY(i + 12, j - 6); cout << " ";
					gotoXY(i + 16, j - 8); cout << " ";
					Sleep(100);
					gotoXY(i, j); cout << "X";
					gotoXY(i + 4, j - 2); cout << "X";
					gotoXY(i + 8, j - 4); cout << "X";
					gotoXY(i + 12, j - 6); cout << "X";
					gotoXY(i + 16, j - 8); cout << "X";
					Sleep(100);
				}
				HienConTro();
				return 1;
			}
			else if (a[i][j] == 2 && a[i + 4][j] == 2 && a[i + 8][j] == 2 && a[i + 12][j] == 2 && a[i + 16][j] == 2)
			{
				AnConTro();
				for (int k(1); k <= 5; k++)
				{
					gotoXY(i, j); cout << " ";
					gotoXY(i + 4, j); cout << " ";
					gotoXY(i + 8, j); cout << " ";
					gotoXY(i + 12, j); cout << " ";
					gotoXY(i + 16, j); cout << " ";
					Sleep(100);
					gotoXY(i, j); cout << "O";
					gotoXY(i + 4, j); cout << "O";
					gotoXY(i + 8, j); cout << "O";
					gotoXY(i + 12, j); cout << "O";
					gotoXY(i + 16, j); cout << "O";
					Sleep(100);
				}
				HienConTro();
				return 2;
			}
			else if (a[i][j] == 2 && a[i][j + 2] == 2 && a[i][j + 4] == 2  && a[i][j + 6] == 2 && a[i][j + 8] == 2) 
			{
				AnConTro();
				for (int k(1); k <= 5; k++)
				{
					gotoXY(i, j); cout << " ";
					gotoXY(i, j + 2); cout << " ";
					gotoXY(i, j + 4); cout << " ";
					gotoXY(i, j + 6); cout << " ";
					gotoXY(i, j + 8); cout << " ";
					Sleep(100);
					gotoXY(i, j); cout << "O";
					gotoXY(i, j + 2); cout << "O";
					gotoXY(i, j + 4); cout << "O";
					gotoXY(i, j + 6); cout << "O";
					gotoXY(i, j + 8); cout << "O";
					Sleep(100);
				}
				HienConTro();
				return 2;
			}
			else if (a[i][j] == 2 && a[i + 4][j + 2] == 2 && a[i + 8][j + 4] == 2 && a[i + 12][j + 6] == 2 && a[i + 16][j + 8] == 2) 
			{
				AnConTro();
				for (int k(1); k <= 5; k++)
				{
					gotoXY(i, j); cout << " ";
					gotoXY(i + 4, j + 2); cout << " ";
					gotoXY(i + 8, j + 4); cout << " ";
					gotoXY(i + 12, j + 6); cout << " ";
					gotoXY(i + 16, j + 8); cout << " ";
					Sleep(100);
					gotoXY(i, j); cout << "O";
					gotoXY(i + 4, j + 2); cout << "O";;
					gotoXY(i + 8, j + 4); cout << "O";
					gotoXY(i + 12, j + 6); cout << "O";
					gotoXY(i + 16, j + 8); cout << "O";
					Sleep(100);
				}
				HienConTro();
				return 2;
			}
			else if (a[i][j] == 2 && a[i + 4][j - 2] == 2 && a[i + 8][j - 4] == 2 && a[i + 12][j - 6] == 2 && a[i + 16][j - 8] == 2) 
			{
				AnConTro();
				for (int k(1); k <= 5; k++)
				{
					gotoXY(i, j); cout << " ";
					gotoXY(i + 4, j - 2); cout << " ";
					gotoXY(i + 8, j - 4); cout << " ";
					gotoXY(i + 12, j - 6); cout << " ";
					gotoXY(i + 16, j - 8); cout << " ";
					Sleep(100);
					gotoXY(i, j); cout << "O";
					gotoXY(i + 4, j - 2); cout << "O";
					gotoXY(i + 8, j - 4); cout << "O";
					gotoXY(i + 12, j - 6); cout << "O";
					gotoXY(i + 16, j - 8); cout << "O";
					Sleep(100);
				}
				HienConTro();
				return 2;
			}
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
	for (int i(1); i <= 3;i++)
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
	if (turn == 1) first = "X";
	else if (turn == 2) first = "O";
	gotoXY(46, 8); cout << "PLAYER " << first << " GO FIRST";
	Sleep(1500);
}
void AnConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HienConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}