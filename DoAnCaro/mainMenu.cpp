#include "mainMenu.h"

char k;
int value;
char name1, name2;
int color ;
int mode ;
int sound;
string p1, p2;

void writeSetting(int color, int sound, int mode)
{
	ofstream f("setting.txt");
	f << color << " " << sound << " " << mode;
	f.close();
}
void readSetting(int& color, int& sound, int& mode)
{
	ifstream f("setting.txt");
	f >> color >> sound >> mode ;
	f.close();
}
void Name(string& p1, string& p2)
{
	system("cls");
	gotoXY(40, 7);
	cout << "NAME'S PLAYER 1: "; getline(cin, p1);
	transform(p1.begin(), p1.end(), p1.begin(), ::toupper);
	gotoXY(40, 9);
	cout << "NAME'S PLAYER 2: "; getline(cin, p2);
	transform(p2.begin(), p2.end(), p2.begin(), ::toupper);
}
void PlayVsBot();

void mainMenu()
{
	system("cls");
	readSetting(color, sound, mode);
	if (sound == 1)  PlaySound(TEXT("Sound/nhacnen.wav"), NULL, SND_ASYNC );
	else;
	int x(51), y(7);
	AnConTro();	
	gotoXY(x, y);
	while (1)
	{
		Textcolor(DarkGreen);
		gotoXY(50, 20);
		cout << "W S: UP DOWN";
		gotoXY(50, 21);
		cout << "ENTER: SELECT";
		gotoXY(50, 22);
		cout << "TURN OFF UNIKEY, CAPSLOCK";
		Textcolor(White);
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
			if (y > 7) 
			{
				y--; gotoXY(x, y); 
			}
			break;
		case 115:
			if (y < 12) 
			{
				y++; gotoXY(x, y); 
			}
			break;
		case 13:
			if (sound == 1) PlaySound(TEXT("Sound/button.wav"), NULL, SND_ASYNC);
			else;
			if (y == 7)
			{
				int k1(0), k2(0), set(1);
				NewGame(k1, k2, set, mode);
				break;
			}
			else if (y == 8)
			{
				PlayVsBot();
			}
			else if (y == 9)
			{
				LoadGame();
			}
			else if (y == 10)
			{
				Setting(color, sound, mode);
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
	Init(turn, p1 ,p2);
	DrawBoard(k1, k2, set, mode, p1, p2);
	resetBoard();
	Play(k1, k2, set, mode, turn, color, sound, p1, p2);
}

void PlayVsBot()
{
	system("cls");
	gotoXY(50, 10);
	cout << "LOADING";
	for (int i = 0; i < 5; i++)
	{
		gotoXY(57, 10);
		for (int i = 0; i < 5; i++)
		{
			cout << ".";
			Sleep(100);
		}
		gotoXY(57, 10);
		for (int i = 0; i < 5; i++)
		{
			cout << " ";
		}
	}
	system("cls");
	gotoXY(50, 10);
	cout << "TINH NANG DANG PHAT TRIEN";
	Sleep(1000);
	system("cls");
	mainMenu();
}

void LoadGame()
{
	system("cls");
	string listName[10];
	string name;
	int a[60][60];
	int k1, k2, set, turn;
	ifstream f("listPlayer.txt");
	int n = 0;
	while (getline(f, name))
	{
		listName[n] = name;
		n++;
	}
	int choice;
	int cmd = 10;
	while (true)
	{
		system("cls");
		if (listName[0] == "")
		{
			gotoXY(52, 10);
			cout << "NO DATA";
			gotoXY(52, 21);
			cout << "ESC: BACK";
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				gotoXY(52, i + 10);
				cout << listName[i];
			}
			gotoXY(52, 21);
			cout << "ESC: BACK";
			gotoXY(50, cmd);
			cout << "->";
		}
			char key = _getch();
			if (key == 'w' || key == 'W')
			{
				if (cmd > 10)
				{
					cmd--;
				}
			}
			else if (key == 's' || key == 'S')
			{
				if (cmd < n + 9)
				{
					cmd++;
				}
			}
			else if (key == 13)
			{
				choice = cmd - 10;
				break;
			}
			else if (key == 27)
			{
				mainMenu();
			}
		
	}
	f.close();
	ifstream fRead("dataPlayer/" + listName[choice] + ".txt");
	fRead >> k1 >> k2 >> set >> turn;
	fRead >> p1 >> p2;
	for (int i(5); i <= 49; i += 4)
	{
		for (int j(4); j <= 26; j += 2)
		{
			fRead >> a[i][j];
		}
	}
	fRead.close();
	DrawBoard(k1, k2, set, mode, p1, p2);
	loadData(a);
	Continue();
	Play(k1, k2, set, mode, turn, color, sound, p1, p2);
}

void NHOM1()
{
	gotoXY(47, 3); cout << "NGUYEN PHUC THUAN";
	gotoXY(50, 4); cout << "MSSV:20120380";
	gotoXY(45, 6); cout << "DANG VO HOANG KIM TUYEN";
	gotoXY(50, 7); cout << "MSSV:20120399";
	gotoXY(48, 9); cout << "NGUYEN LONG VU";
	gotoXY(50, 10); cout << "MSSV:20120405";
	gotoXY(48, 12); cout << "TRAN THANH TUNG";
	gotoXY(50, 13); cout << "MSSV:20120409";
	
}
void About()
{
	system("cls");
	int x(48), y(7);
	while (1)
	{
		if (y == 7)
		{
			gotoXY(52, 3); cout << "ABOUT";
			Textcolor(color);
			gotoXY(52, 7); cout << "NHOM 1";
			Textcolor(White);
			gotoXY(52, 8); cout << "20CTT3";
			gotoXY(46, 10); cout << "GIAO VIEN HUONG DAN ";
			gotoXY(47, 11); cout << "TRUONG TOAN THINH";
			gotoXY(53, 15); cout << "BACK";
		}
		else if (y == 15)
		{
			gotoXY(52, 3); cout << "ABOUT";
			gotoXY(52, 7); cout << "NHOM 1";
			gotoXY(52, 8); cout << "20CTT3";
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
			if (y > 7) { y -= 8; gotoXY(x, y); }
			break;
		case 115:
			if (y < 15) { y += 8; gotoXY(x, y); }
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
				NHOM1();
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

void Setting(int& color, int& sound, int& mode)
{
	int x(45), y(9);
	int n(1);
	system("cls");
	gotoXY(45, 9); cout << "COLOR:";
	gotoXY(45, 10); cout << "MUSIC:";
	gotoXY(55, 10);
	if (sound == 1)
	{
		cout << char(174);
		cout << "   ON    ";
		cout << char(175);
	}
	else if (sound == 0)
	{
		cout << char(174);
		cout << "   OFF   ";
		cout << char(175);
	}
	gotoXY(45, 11); cout << "MODE:";
	gotoXY(55, 11);
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
		writeSetting(color, sound, mode);
		if (y == 9)
		{
			Textcolor(color);
			gotoXY(45, 9); cout << "COLOR:";
			Textcolor(White);
			gotoXY(45, 10); cout << "SOUND:";
			gotoXY(45, 11); cout << "MODE:";
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
			gotoXY(45, 10);	cout << "SOUND:";
			Textcolor(White);
			gotoXY(45, 11); cout << "MODE:";
			gotoXY(55, 10);
			if (sound == 1)
			{
				cout << char(174);
				cout << "   ON    ";
				cout << char(175);
			}
			else if (sound == 0)
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
				if (sound > 0) sound--;
				break;
			case 97:
				if (sound < 1) sound++;
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
			gotoXY(45, 10);	cout << "SOUND:";
			Textcolor(color);
			gotoXY(45, 11);	cout << "MODE:";
			Textcolor(White);
			gotoXY(55, 11);
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
			if (y < 11) y++;
			break;
		case -32:
			value = _getch();
			switch (value)
			{
			case 72:
				if (y > 9) y--;
				break;
			case 80:
				if (y < 11) y++;
				break;
			}
		case 13:
			mainMenu();
		}
	}
}


