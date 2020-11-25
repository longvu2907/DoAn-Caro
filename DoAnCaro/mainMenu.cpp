#include "mainMenu.h"


char k;
int value;
char name1, name2;
int color ;
int mode ;
int music ;
int sfx ;
string p1, p2;

void writeSetting(int color, int music, int sfx, int mode)
{
	ofstream f("setting.txt");
	f << color << " " << music << " " << sfx << " " << mode;
	f.close();
}
void readSetting(int& color, int& music, int& sfx, int& mode)
{
	ifstream f("setting.txt");
	f >> color >> music >> sfx >> mode ;
	f.close();
}
void Name(string p1, string p2)
{
	system("cls");
	gotoXY(40, 7);
	cout << "NHAP TEN PLAYER 1: "; cin >> p1;
	gotoXY(40, 9);
	cout << "NHAP TEN PLAYER 2: "; cin >> p2;
}

void mainMenu()
{
	system("cls");
	readSetting(color, music, sfx, mode);
	if (music == 2)  PlaySound(TEXT("nhoinhoi2.wav"), NULL, SND_ASYNC|SND_LOOP);
	else if(music == 1) PlaySound(TEXT("nhoinhoi1.wav"), NULL, SND_ASYNC);
	else PlaySound(TEXT("none.wav"), NULL, SND_ASYNC);
	
	int x(51), y(7);
	AnConTro();	
	gotoXY(x, y);
	while (1)
	{
		
		if (y == 7)
		{
			Textcolor(color);
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			Textcolor(White);
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			gotoXY(x, 9); cout << "LOAD GAME";
			gotoXY(x, 10); cout << "SETTING";
			gotoXY(x, 11); cout << "ABOUT";
			gotoXY(x, 12); cout << "EXIT";
			
		}
		else if (y == 8)
		{
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			Textcolor(color);
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			Textcolor(White);
			gotoXY(x, 9); cout << "LOAD GAME";
			gotoXY(x, 10); cout << "SETTING";
			gotoXY(x, 11); cout << "ABOUT";
			gotoXY(x, 12); cout << "EXIT";
			
		}
		else if (y == 9)
		{
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			Textcolor(color);
			gotoXY(x, 9); cout << "LOAD GAME";
			Textcolor(White);
			gotoXY(x, 10); cout << "SETTING";
			gotoXY(x, 11); cout << "ABOUT";
			gotoXY(x, 12); cout << "EXIT";
			
		}
		else if (y == 10)
		{
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			gotoXY(x, 9); cout << "LOAD GAME";
			Textcolor(color);
			gotoXY(x, 10); cout << "SETTING";
			Textcolor(White);
			gotoXY(x, 11); cout << "ABOUT";
			gotoXY(x, 12); cout << "EXIT";
			
		}
		else if (y == 11)
		{
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			gotoXY(x, 9); cout << "LOAD GAME";
			gotoXY(x, 10); cout << "SETTING";
			Textcolor(color);
			gotoXY(x, 11); cout << "ABOUT";
			Textcolor(White);
			gotoXY(x, 12); cout << "EXIT";
		
		}	
		else if (y == 12)
		{
			gotoXY(x, 7); cout << "PLAYER VS PLAYER";
			gotoXY(x, 8); cout << "PLAYER VS BOT";
			gotoXY(x, 9); cout << "LOAD GAME";
			gotoXY(x, 10); cout << "SETTING";
			gotoXY(x, 11); cout << "ABOUT";	
			Textcolor(color);
			gotoXY(x, 12); cout << "EXIT";
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
			if (y < 12) { y++; gotoXY(x, y); }
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
				if (y < 12) { y++; gotoXY(x, y); } 
				break;
			}
			break;
		case 13:
			if (sfx == 1) PlaySound(TEXT("button.wav"), NULL, SND_ASYNC);
			else PlaySound(TEXT("none.wav"), NULL, SND_ASYNC);
			if (y == 7)
			{
				int k1(0), k2(0), set(1);
				NewGame(k1, k2, set, mode);
				break;
			}
			else if (y == 8||y == 9)
			{
				LoadGame();
			}
			else if (y == 10)
			{
				Setting(color, music, mode, sfx);
				mainMenu();
			}
			else if (y == 11)
			{
				About();
			}
			else if (y == 12)
			{
				exit(0);
			}
		}
	}
}


void NewGame(int k1, int k2 ,int set,int mode)
{
	int turn = initTurn();
	Name(p1, p2);
	Init(turn);
	DrawBoard(k1, k2, set, mode);
	resetBoard();
	Play(k1, k2, set, mode, turn, color, sfx);
}

void LoadGame()
{
	int a[60][60];
	int k1, k2, set, turn;
	ifstream f("Loadgame.txt");
	f >> k1 >> k2 >> set >> turn;
	for (int i(5); i <= 49; i += 4)
	{
		for (int j(4); j <= 26; j += 2)
		{
			f >> a[i][j];
		}
	}
	DrawBoard(k1, k2, set, mode);
	Continue();
	Play(k1, k2, set, mode, turn, color, sfx);
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
			Textcolor(color);
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
			Textcolor(color);
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
			Textcolor(color);
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
			Textcolor(color);
			gotoXY(54, 8); cout << "BO1\n";
			Textcolor(White);
			gotoXY(54, 9); cout << "BO3\n";
			gotoXY(54, 10); cout << "BO5\n";
		}
		else if (y == 9)
		{
			gotoXY(54, 8); cout << "BO1\n";
			Textcolor(color);
			gotoXY(54, 9); cout << "BO3\n";
			Textcolor(White);
			gotoXY(54, 10); cout << "BO5\n";
		}
		else if (y == 10)
		{
			gotoXY(54, 8); cout << "BO1\n";
			gotoXY(54, 9); cout << "BO3\n";
			Textcolor(color);
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

void Setting(int& color, int& music, int& mode, int& sfx)
{
	int x(45), y(9);
	int n(1);
	system("cls");
	gotoXY(45, 9); cout << "COLOR:";
	gotoXY(45, 10); cout << "MUSIC:";
	gotoXY(55, 10);
	if (music == 2)
	{
		cout << char(174);
		cout << "   100%  ";
		cout << char(175);
	}
	else if (music == 1)
	{
		cout << char(174);
		cout << "   50%   ";
		cout << char(175);
	}
	else if (music == 0)
	{
		cout << char(174);
		cout << "   OFF   ";
		cout << char(175);
	}
	gotoXY(45, 11);  cout << "SFX:";
	gotoXY(55, 11);
	if (sfx == 1)
	{
		cout << char(174);
		cout << "   ON    ";
		cout << char(175);
	}
	else if (sfx == 0)
	{
		cout << char(174);
		cout << "   OFF   ";
		cout << char(175);
	}
	gotoXY(45, 12); cout << "MODE:";
	gotoXY(55, 12);
	if (mode == 1)
	{
		cout << char(174);
		cout << "   BO1   ";
		cout << char(175);
	}
	else if (mode == 3)
	{
		cout << char(174);
		cout << "   BO3   ";
		cout << char(175);
	}
	else if (mode == 5)
	{
		cout << char(174);
		cout << "   BO5   ";
		cout << char(175);
	}
	gotoXY(45, 9);
	while (1)
	{
		writeSetting(color, music, sfx, mode);
		if (y == 9)
		{
			Textcolor(color);
			gotoXY(45, 9); cout << "COLOR:";
			Textcolor(White);
			gotoXY(45, 10); cout << "MUSIC:";
			gotoXY(45, 11); cout << "SFX:";
			gotoXY(45, 12); cout << "MODE:";
			gotoXY(55, 9);
			if (color == Cyan)
			{
				cout << char(174);
				Textcolor(Cyan);
				cout << "   CYAN  ";
				Textcolor(White);
				cout << char(175);
			}
			else if (color == Green)
			{
				cout << char(174);
				Textcolor(Green);
				cout << "   GREEN ";
				Textcolor(White);
				cout << char(175);
			}
			else if (color == Blue)
			{
				cout << char(174);
				Textcolor(Blue);
				cout << "   BLUE  ";
				Textcolor(White);
				cout << char(175);
			}
			else if (color == Red)
			{
				cout << char(174);
				Textcolor(Red);
				cout << "   RED   ";
				Textcolor(White);
				cout << char(175);
			}
			else if (color == Pink)
			{
				cout << char(174);
				Textcolor(Pink);
				cout << "   PINK  ";
				Textcolor(White);
				cout << char(175);
			}
			else if (color == Yellow)
			{
				cout << char(174);
				Textcolor(Yellow);
				cout << "  YELLOW ";
				Textcolor(White);
				cout << char(175);
			}
			k = _getch();
			value = k;
			switch (value)
			{
			case 100:
				if (color < 14) color++;
				break;
			case 97:
				if (color > 9) color--;
				break;
			case -32:
				value = _getch();
				if (value == 77)
				{
					if (color < 14) color++;
				}
				else if (value == 75)
				{
					if (color > 9) color--;
				}
				break;
			case 13:
				if (color == 9) color = Blue;
				else if (color == 10) color = Green;
				else if (color == 11) color = Cyan;
				else if (color == 12)  color = Red;
				else if (color == 13) color = Pink;
				else if (color == 14)  color = Yellow;
				mainMenu();
			}
		}
		else if (y == 10)
		{
			gotoXY(45, 9); cout << "COLOR:";
			Textcolor(color);
			gotoXY(45, 10);	cout << "MUSIC:";
			Textcolor(White);
			gotoXY(45, 11); cout << "SFX:";
			gotoXY(45, 12); cout << "MODE:";
			gotoXY(55, 10);
			if (music == 2)
			{
				cout << char(174);
				cout << "   100%  ";
				cout << char(175);
			}
			else if (music == 1)
			{
				cout << char(174);
				cout << "   50%   ";
				cout << char(175);
			}
			else if (music == 0)
			{
				cout << char(174);
				cout << "   OFF   ";
				cout << char(175);
			}
			k = _getch();
			value = k;
			switch (value)
			{
			case 100:
				if (music > 0) music--;
				break;
			case 97:
				if (music < 2) music++;
				break;
			case -32:
				value = _getch();
				if (value == 77)
				{
					if (n < 2) n++;
				}
				else if (value == 75)
				{
					if (n > 1) n--;
				}
				break;
			case 13:
				mainMenu();
			}
		}
		else if (y == 11)
		{
		gotoXY(45, 9); cout << "COLOR:";
		gotoXY(45, 10);	cout << "MUSIC:";
		Textcolor(color);
		gotoXY(45, 11); cout << "SFX:";
		Textcolor(White);
		gotoXY(45, 12); cout << "MODE:";
		gotoXY(55, 11);
		if (sfx == 1)
		{
			cout << char(174);
			cout << "   ON    ";
			cout << char(175);
		}
		else if (sfx == 0)
		{
			cout << char(174);
			cout << "   OFF   ";
			cout << char(175);
		}
		k = _getch();
		value = k;
		switch (value)
		{
		case 100:
			if (sfx > 0) sfx--;
			break;
		case 97:
			if (sfx < 1) sfx++;
			break;
		case -32:
			value = _getch();
			if (value == 77)
			{
				if (n < 2) n++;
			}
			else if (value == 75)
			{
				if (n > 1) n--;
			}
			break;
		case 13:
			mainMenu();
		}
		}
		else if (y == 12)
		{
			gotoXY(45, 9); cout << "COLOR:";
			gotoXY(45, 10);	cout << "MUSIC:";
			gotoXY(45, 11); cout << "SFX:";
			Textcolor(color);
			gotoXY(45, 12);	cout << "MODE:";
			Textcolor(White);
			gotoXY(55, 12);
			if (mode == 1)
			{
				cout << char(174);
				cout << "   BO1   ";
				cout << char(175);
			}
			else if (mode == 3)
			{
				cout << char(174);
				cout << "   BO3   ";
				cout << char(175);
			}
			else if (mode == 5)
			{
				cout << char(174);
				cout << "   BO5   ";
				cout << char(175);
			}
			k = _getch();
			value = k;
			switch (value)
			{
			case 100:
				if (mode < 5) mode += 2;
				break;
			case 97:
				if (mode > 1) mode -= 2;
				break;
			case -32:
				value = _getch();
				if (value == 77)
				{
					if (mode < 5) mode += 2;;
				}
				else if (value == 75)
				{
					if (mode > 1) mode -= 2;
				}
				break;
			case 13:
				mainMenu();
			}
		}
		switch (value)
		{
		case 119:
			if (y > 9) y--;
			break;
		case 115:
			if (y < 12) y++;
			break;
		case -32:
			value = _getch();
			switch (value)
			{
			case 72:
				if (y > 9) y--;
				break;
			case 80:
				if (y < 12) y++;
				break;
			}
		case 13:
			mainMenu();
		}
	}
}

