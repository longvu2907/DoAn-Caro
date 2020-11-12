#include "Start.h"

void Play(int& x, int& y)
{
	char k;
	int value;
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
			cout << "X";
			gotoXY(x, y);
		}
	}
}