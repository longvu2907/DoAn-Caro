#include "Start.h"

int a[60][60] = {};

void Play(int& k1, int& k2)
{
	char k;
	int value;
	int x(5), y(4);
	int turn(initTurn());
	gotoXY(x, y); 
	while (1)
	{
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
			turn = swapTurn(turn);
			if (checkXO()==1)
			{
				k1++;
				if (k1 == 3)
				{
					system("cls");
					cout << "NGUOI CHOI 1 CHIEN THANG";
					system("pause");
				}
				NewGame();
			}
			else if (checkXO() == 2)
			{
				k2++;
				if (k2 == 3)
				{
					system("cls");
					cout << "NGUOI CHOI 1 CHIEN THANG";
					system("pause");
				}
				NewGame();
			}
		}
	}
}
void tickXO(int x, int y, int turn)
{

	if (a[x][y] == 1 || a[x][y] == 2) return;
	else if (turn == 1)
	{
		a[x][y] = 1;
		cout << "X";
	}
	else if (turn== 2)
	{
		a[x][y] = 2;
		cout << "O";
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