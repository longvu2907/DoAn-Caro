#include "Start.h"

int a[60][60] = {};

void Play(int& k1, int& k2, int& set, int mode, int turn, int color, int sfx, string p1, string p2)
{
	
	char k;
	int value;
	int x(5), y(4);
	while (1)
	{	
		HienConTro();
		gotoXY(5, 4); 
		oTurn(x,y,turn,p1,p2);
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
			tickXO(x, y, turn, sfx);
			gotoXY(x, y);
			if (checkXO(sfx) == 1)
			{
				k1++;
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				if (k1 == mode)
				{
					system("cls");
					AnConTro();
					gotoXY(47, 7);
					Textcolor(Red);
					cout << p1 <<" WIN !!!!";
					Textcolor(White);
					x = 47;
					y = 10;
					while (1)
					{
						if (y == 10)
						{
							Textcolor(color);
							gotoXY(47, 10); cout << "MAIN MENU";
							Textcolor(White);
							gotoXY(47, 11); cout << "PLAY AGAIN";
							gotoXY(47, 12); cout << "QUIT GAME";
						}
						else if (y == 11)
						{							
							gotoXY(47, 10); cout << "MAIN MENU";
							Textcolor(color);
							gotoXY(47, 11); cout << "PLAY AGAIN";
							Textcolor(White);
							gotoXY(47, 12); cout << "QUIT GAME";
						}
						else if (y == 12)
						{					
							gotoXY(47, 10); cout << "MAIN MENU";					
							gotoXY(47, 11); cout << "PLAY AGAIN";
							Textcolor(color);
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
							else if (y == 11) NewGame(0, 0, 1, mode);
							else if (y == 12) exit(0);
						}
					}
				}
				
				set++;
				DrawBoard(k1, k2, set, mode, p1, p2);
				resetBoard();
				Play(k1, k2, set, mode, turn, color, sfx, p1, p2);
			}
			else if (checkXO(sfx) == 2)
			{
				k2++;
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				if (k2 == mode)
				{
					system("cls");
					AnConTro();
					gotoXY(47, 7);
					Textcolor(Blue);
					cout << p2 << " WIN !!!!";
					Textcolor(White);
					x = 47;
					y = 10;
					while (1)
					{
						if (y == 10)
						{
							Textcolor(color);
							gotoXY(47, 10); cout << "MAIN MENU";
							Textcolor(White);
							gotoXY(47, 11); cout << "PLAY AGAIN";
							gotoXY(47, 12); cout << "QUIT GAME";
						}
						else if (y == 11)
						{
							gotoXY(47, 10); cout << "MAIN MENU";
							Textcolor(color);
							gotoXY(47, 11); cout << "PLAY AGAIN";
							Textcolor(White);
							gotoXY(47, 12); cout << "QUIT GAME";
						}
						else if (y == 12)
						{
							gotoXY(47, 10); cout << "MAIN MENU";
							gotoXY(47, 11); cout << "PLAY AGAIN";
							Textcolor(color);
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
							else if (y == 11) NewGame(0, 0, 1, mode);
							else if (y == 12) exit(0);
						}
					}
				}			
				set++;
				DrawBoard(k1, k2, set, mode, p1, p2);
				resetBoard();
				Play(k1, k2, set, mode, turn, color, sfx, p1, p2);
			}
			else if (checkXO(sfx) == 3)
			{
			k2++;
			k1++;
			system("cls");
			AnConTro();
			for (int i(1); i <= 5; i++)
			{
				gotoXY(50, 7);
				Textcolor(Pink);
				cout << "DRAW";
				Textcolor(White);
				Sleep(100);
				gotoXY(50, 7);
				Textcolor(Black);
				cout << "DRAW";
				Textcolor(White);
				Sleep(100);
			}
			if (k2 == mode && k1 == mode)
			{
				system("cls");
				AnConTro();
				gotoXY(50, 7);
				Textcolor(Pink);
				cout << "DRAW";
				Textcolor(White);
				x = 47;
				y = 10;
				while (1)
				{
					if (y == 10)
					{
						Textcolor(color);
						gotoXY(47, 10); cout << "MAIN MENU";
						Textcolor(White);
						gotoXY(47, 11); cout << "PLAY AGAIN";
						gotoXY(47, 12); cout << "QUIT GAME";
					}
					else if (y == 11)
					{
						gotoXY(47, 10); cout << "MAIN MENU";
						Textcolor(color);
						gotoXY(47, 11); cout << "PLAY AGAIN";
						Textcolor(White);
						gotoXY(47, 12); cout << "QUIT GAME";
					}
					else if (y == 12)
					{
						gotoXY(47, 10); cout << "MAIN MENU";
						gotoXY(47, 11); cout << "PLAY AGAIN";
						Textcolor(color);
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
						else if (y == 11) NewGame(0, 0, 1, mode);
						else if (y == 12) exit(0);
					}
				}
			}
			set++;
			DrawBoard(k1, k2, set, mode, p1 ,p2);
			resetBoard();
			Play(k1, k2, set, mode, turn, color, sfx, p1, p2);
			}
		}
		else if (value == 27)
		{
			AnConTro();
			system("cls");
			x = 47;
			y = 10;
			while (1)
			{
				if (y == 10) 
				{		
					Textcolor(color);		
					gotoXY(47, 10); cout << "CONTINUE";
					Textcolor(White);
					gotoXY(47, 11); cout << "MAIN MENU";				
					gotoXY(47, 12); cout << "SAVE GAME";
					gotoXY(47, 13); cout << "QUIT GAME";
				}
				else if (y == 11)
				{					
					gotoXY(47, 10); cout << "CONTINUE";	
					Textcolor(color);				
					gotoXY(47, 11); cout << "MAIN MENU";
					Textcolor(White);
					gotoXY(47, 12); cout << "SAVE GAME";					
					gotoXY(47, 13); cout << "QUIT GAME";
				}
				else if (y == 12)
				{					
					gotoXY(47, 10); cout << "CONTINUE";					
					gotoXY(47, 11); cout << "MAIN MENU";
					Textcolor(color);
					gotoXY(47, 12); cout << "SAVE GAME";
					Textcolor(White);
					gotoXY(47, 13); cout << "QUIT GAME";	
				}
				else if (y == 13)
				{
					gotoXY(47, 10); cout << "CONTINUE";	
					gotoXY(47, 11); cout << "MAIN MENU";
					gotoXY(47, 12); cout << "SAVE GAME";
					Textcolor(color);
					gotoXY(47, 13); cout << "QUIT GAME";
					Textcolor(White);
				}
				k = _getch();
				value = k;
				if (value == -32)
					{
						value = _getch();
						switch (value)
						{
						case 72:
							if (y > 10) y--;
							break;
						case 80:
							if (y < 13) y++;
							break;	
						}
					}
				else if (value == 115 || value == 97 || value == 100 || value == 119)
				{
					switch (value)
					{
					case 119:
						if (y > 10) y--;
						break;
					case 115:
						if (y < 13) y++;
						break;
					}
				}
				else if (13)
				{
					if (y == 10) {
						
						DrawBoard(k1, k2, set, mode, p1 ,p2); 
						Continue();
						Play(k1, k2, set, mode, turn, color, sfx, p1, p2);
					}
					else if (y == 11) mainMenu();
					else if (y == 12) Savegame(k1, k2, set, turn);
					else if (y == 13) exit(0);
				}				
			}
		}
	}
}
void tickXO(int x, int y, int& turn, int sfx)
{

	if (a[x][y] == 1 || a[x][y] == 2)
	{
		if (sfx == 1) PlaySound(TEXT("error.wav"), NULL, SND_SYNC);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		return;
	}
	else if (turn == 1)
	{
		if (sfx == 1) PlaySound(TEXT("tickX.wav"), NULL, SND_SYNC);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		a[x][y] = 1;
		Textcolor(Red);
		cout << "X";
		turn = swapTurn(turn);
	}
	else if (turn == 2)
	{
		if (sfx == 1) PlaySound(TEXT("tickO.wav"), NULL, SND_SYNC);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		a[x][y] = 2;
		Textcolor(Blue);
		cout << "O";
		turn = swapTurn(turn);
	}
	Textcolor(White);
}
int checkXO(int sfx)
{
	int check;
	for (int i(5); i <= 49; i += 4)
	{
		for (int j(4); j <= 26; j += 2)
		{
			if (a[i][j] == 1 && a[i + 4][j] == 1 && a[i + 8][j] == 1 && a[i + 12][j] == 1 && a[i + 16][j] == 1)
			{
				if (a[i - 4][j] == 2 && a[i + 20][j] == 2) { check = 0; }
				else
				{
					if (sfx == 1) PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
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
			}
			else if (a[i][j] == 1 && a[i][j + 2] == 1 && a[i][j + 4] == 1 && a[i][j + 6] == 1 && a[i][j + 8] == 1)
			{
				if (a[i][j - 2] == 2 && a[i][j + 10] == 2) { check = 0; }
				else
				{
					if (sfx == 1) PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
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
			}
			else if (a[i][j] == 1 && a[i + 4][j + 2] == 1 && a[i + 8][j + 4] == 1 && a[i + 12][j + 6] == 1 && a[i + 16][j + 8] == 1)
			{
				if (a[i - 4][j - 2] == 2 && a[i + 20][j + 10] == 2) { check = 0; }
				else
				{
					if (sfx == 1) PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
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
			}
			else if (a[i][j] == 1 && a[i + 4][j - 2] == 1 && a[i + 8][j - 4] == 1 && a[i + 12][j - 6] == 1 && a[i + 16][j - 8] == 1)
			{
				if (a[i - 4][j + 2] == 2 && a[i + 20][j - 10] == 2) { check = 0; }
				else
				{
					if (sfx == 1) PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
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
			}
			else if (a[i][j] == 2 && a[i + 4][j] == 2 && a[i + 8][j] == 2 && a[i + 12][j] == 2 && a[i + 16][j] == 2)
			{
				if (a[i - 4][j] == 1 && a[i + 20][j] == 1) { check = 0; }
				else
				{
					if (sfx == 1) PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
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
			}
			else if (a[i][j] == 2 && a[i][j + 2] == 2 && a[i][j + 4] == 2 && a[i][j + 6] == 2 && a[i][j + 8] == 2)
			{
				if (a[i][j - 2] == 1 && a[i][j + 10] == 1) { check = 0; }
				else
				{
					if (sfx == 1) PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
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
			}
			else if (a[i][j] == 2 && a[i + 4][j + 2] == 2 && a[i + 8][j + 4] == 2 && a[i + 12][j + 6] == 2 && a[i + 16][j + 8] == 2)
			{
				if (a[i - 4][j - 2] == 1 && a[i + 20][j + 10] == 1) { check = 0; }
				else
				{
					if (sfx == 1) PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
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
			}
			else if (a[i][j] == 2 && a[i + 4][j - 2] == 2 && a[i + 8][j - 4] == 2 && a[i + 12][j - 6] == 2 && a[i + 16][j - 8] == 2)
			{
				if (a[i - 4][j + 2] == 1 && a[i + 20][j - 10] == 1) { check = 0; }
				else
				{
					if (sfx == 1) PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
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
			}
			else check = 0;
		}
	}
	for (int i(5), c(0); i <= 49; i += 4)
	{
		for (int j(4); j <= 26; j += 2)
		{
			if (a[i][j] != 0) c++;
		}
		if (c == 144) return 3;
	}
	return check;
}
void Continue()
{
	for (int i(5); i <= 49; i += 4)
	{
		for (int j(4); j <= 26; j += 2)
		{
			if (a[i][j] == 1)
			{
				gotoXY(i, j);
				Textcolor(Red);
				cout << "X";
				Textcolor(White);
			}
			else if (a[i][j] == 2)
			{
				gotoXY(i, j);
				Textcolor(Blue);
				cout << "O";
				Textcolor(White);
			}
		}
	}
}
void Savegame(int k1,int k2,int set,int turn)
{
	ofstream f("Loadgame.txt");
	f << k1 << " " << k2 << " " << set << " " << turn << endl;
	for (int i(5); i <= 49; i += 4)
	{
		for (int j(4); j <= 26; j += 2)
		{
			f << a[i][j] << " ";
		}
		f << endl;
	}
	f.close();
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
void Init(int turn, string p1, string p2)
{
	string first;
	system("cls");
	gotoXY(35, 9); cout << "0 %";
	gotoXY(80, 9); cout << "100 %";
	gotoXY(35, 10);
	for (int i(1); i <= 25; i++)
	{
		cout << char(219);
		Sleep(10);
	}
	for (int i(1); i <= 25; i++)
	{
		cout << char(219);
		Sleep(100);
	}
	
	system("cls");
	if (turn == 1) first = p1;
	else if (turn == 2) first = p2;
	gotoXY(46, 8); cout << first << " GO FIRST";
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

