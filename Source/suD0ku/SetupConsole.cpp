#include "suD0ku.h"

int Read_Key()
{
	int key = -1;
	switch (_getch())
	{
		case 13:
			key = Enter;
			break;
		case 27:
			key = Esc;
			break;
		case 'm': case 'M':
			key = Mute;
			break;
		case 'n': case 'N':
			key = New;
			break;
		case 'e': case 'E':
			key = Erase;
			break;
		case 'c': case 'C':
			key = Check;
			break;
		case 'h': case 'H':
			key = Hint;
			break;
		case 224:
			switch (_getch())
			{
				case 72: key = Up; break;
				case 75: key = Left; break;
				case 77: key = Right; break;
				case 80: key = Down; break;
			}
			break;
		case 48: key = 0; break;
		case 49: key = 1; break;
		case 50: key = 2; break;
		case 51: key = 3; break;
		case 52: key = 4; break;
		case 53: key = 5; break;
		case 54: key = 6; break;
		case 55: key = 7; break;
		case 56: key = 8; break;
		case 57: key = 9; break;
	}
	return key;
}

void gotoxy(SHORT x, SHORT y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void SetColor(int Text, int Background)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Background * 16 + Text);
}

void SetWindowsSize(SHORT x, SHORT y)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	wchar_t str[256] = L"suDOku - by R4ven Team";
	SetConsoleTitle(str);

	SMALL_RECT windowSize = { 0, 0, x - 1, y - 1 };
	SetConsoleWindowInfo(hConsole, true, &windowSize);

	if (y == 25)
		y = 10;
	COORD bufferSize = { x, y };
	SetConsoleScreenBufferSize(hConsole, bufferSize);
}