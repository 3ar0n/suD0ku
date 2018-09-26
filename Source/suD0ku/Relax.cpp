#include "suD0ku.h"

#define top 1111
#define left 2222
#define right 3333
#define bottom 4444
#define topleft 1122
#define topright 1133
#define bottomleft 4422
#define bottomright 4433

void putShape(int posX, int posY, int edge, bool Visible, int Color)
{
	int vectorX = 2;
	int vectorY = 1;
	for (int i = -vectorY; i <= vectorY; i++)
	{
		gotoxy(posX - vectorX, posY + i);
		for (int j = -vectorX; j <= vectorX; j++)
		{
			if (!Visible)
			{
				SetColor(Black);
				printf(" ");
			}
			else
			{
				SetColor(Color);
				if (i == -vectorY)
				{
					if (j == -vectorX)
						printf("%c", 218);
					else if (j == vectorX)
						printf("%c", 191);
					else
						printf("%c", 196);
				}
				else if (i == vectorY)
				{
					if (j == -vectorX)
						printf("%c", 192);
					else if (j == vectorX)
						printf("%c", 217);
					else
						printf("%c", 196);
				}
				else
				{
					if (j == -vectorX)
						printf("%c", 179);
					else if (j == vectorX)
						printf("%c", 179);
					else
						printf(" ");
				}
			}
		}
	}
	SetColor();
}

void putShapeBorder(int posX, int posY, int sizeX, int sizeY)
{
	for (int i = -sizeY; i <= sizeY; i++)
	{
		gotoxy(posX - sizeX, posY + i);
		for (int j = -sizeX; j <= sizeX; j++)
		{
			if (i == -sizeY)
			{
				if (j == -sizeX)
					printf("%c", 201);
				else if (j == sizeX)
					printf("%c", 187);
				else
					printf("%c", 205);
			}
			else if (i == sizeY)
			{
				if (j == -sizeX)
					printf("%c", 200);
				else if (j == sizeX)
					printf("%c", 188);
				else
					printf("%c", 205);
			}
			else
			{
				if (j == -sizeX)
					printf("%c", 186);
				else if (j == sizeX)
					printf("%c", 186);
				else
					printf(" ");
			}
		}
	}
}

void Moving_Square(int sizeX, int sizeY)
{
	srand((unsigned)time(NULL));
	int x = 3, y = 3 + (rand() % 17) * 2;
	int vX = 2, vY = 1;
	int edge = 0;
	int Color = rand() % 8 + 8;
	int Key, Speed = 100, Sound = 1;
	//putShapeBorder(45, 21, sizeX, sizeY);

	for (int i = 38; i < 46; i++)
	{
		gotoxy(0, i);
		for (int j = 0; j < 90; j++)
			printf(" ");
	}
	gotoxy(28, 41); printf("  Relax your eyes, relax your mind");
	gotoxy(28, 43); printf("Press ESC to return to the main menu");
	putShape(x, y, false, true);
	Sleep(200);

	LOOP_game:
	do
	{
		putShape(x, y, false, false);
		switch (edge)
		{
			case top: case bottom:
				vY = -vY;
				edge = 0;
				break;
			case left: case right:
				vX = -vX;
				edge = 0;
				break;
			case topleft: case topright: case bottomleft: case bottomright:
				vX = -vX;
				vY = -vY;
				edge = 0;
				break;
		}
		x = x + vX;
		y = y + vY;
		putShape(x, y, false, true, Color);
		if (y == 19 - sizeY + 1)
		{
			if (x == 45 - sizeX + 2)
				edge = topleft;
			else if (x == 45 + sizeX - 2)
				edge = topright;
			else
				edge = top;
		}
		else if (y == 19 + sizeY - 1)
		{
			if (x == 45 - sizeX + 2)
				edge = bottomleft;
			else if (x == 45 + sizeX - 2)
				edge = bottomright;
			else
				edge = bottom;
		}
		else
		{
			if (x == 45 - sizeX + 2)
				edge = left;
			else if (x == 45 + sizeX - 2)
				edge = right;
		}
		if (edge)
		{
			if (Sound == 1)
				Beep(415, Speed);
			else if (Sound == -1)
				Sleep(Speed);
			Color = rand() % 8 + 8;
		}
		else
			Sleep(Speed);
		
		if (_kbhit())
		{
			Key = Read_Key();
			if (Key == Esc)
				break;
			else
			{
				if (Key == Up && Speed > 50)
					Speed = Speed - 50;
				else if (Key == Down && Speed < 200)
					Speed = Speed + 50;
				else if (Key == Mute)
					Sound = -Sound;
				goto LOOP_game;
			}
		}
	} while (1);
}