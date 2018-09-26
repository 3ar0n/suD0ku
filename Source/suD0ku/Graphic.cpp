#include "suD0ku.h"

void putLogo(int x, int y, int Color, int Color_Shad)
{
	SetColor(Color);

	gotoxy(x, y + 0);	printf("%c%c%c%c%c%c%c%c  %c%c%c   %c%c%c    %c%c%c%c%c%c%c    %c%c%c%c%c%c%c     %c%c%c  %c%c%c  %c%c%c   %c%c%c", 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 187, 219, 219, 187, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 187, 219, 219, 187, 219, 219, 187, 219, 219, 187, 219, 219, 187);
	gotoxy(x, y + 1);	printf("%c%c%c%c%c%c%c%c  %c%c%c   %c%c%c    %c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c%c    %c%c%c %c%c%c%c  %c%c%c   %c%c%c", 219, 219, 201, 205, 205, 205, 205, 188, 219, 219, 186, 219, 219, 186, 219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 201, 205, 219, 219, 219, 219, 187, 219, 219, 186, 219, 219, 201, 188, 219, 219, 186, 219, 219, 186);
	gotoxy(x, y + 2);	printf("%c%c%c%c%c%c%c%c  %c%c%c   %c%c%c    %c%c%c  %c%c%c  %c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c   %c%c%c   %c%c%c", 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 186, 219, 219, 186, 219, 219, 186, 219, 219, 186, 219, 219, 186, 219, 219, 201, 219, 219, 186, 219, 219, 219, 219, 219, 201, 188, 219, 219, 186, 219, 219, 186);
	gotoxy(x, y + 3);	printf("%c%c%c%c%c%c%c%c  %c%c%c   %c%c%c    %c%c%c  %c%c%c  %c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c   %c%c%c   %c%c%c", 200, 205, 205, 205, 205, 219, 219, 186, 219, 219, 186, 219, 219, 186, 219, 219, 186, 219, 219, 186, 219, 219, 219, 219, 201, 188, 219, 219, 186, 219, 219, 201, 205, 219, 219, 187, 219, 219, 186, 219, 219, 186);
	gotoxy(x, y + 4);	printf("%c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c%c    %c%c%c  %c%c%c  %c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 186, 200, 219, 219, 219, 219, 219, 219, 201, 188, 219, 219, 219, 219, 219, 219, 201, 188, 200, 219, 219, 219, 219, 219, 219, 201, 188, 219, 219, 186, 219, 219, 187, 200, 219, 219, 219, 219, 219, 219, 201, 188);

	SetColor(Color_Shad);
	//1
	gotoxy(x + 7, y + 0);	printf("%c", 187);
	gotoxy(x + 12, y + 0);	printf("%c", 187);
	gotoxy(x + 18, y + 0);	printf("%c", 187);
	gotoxy(x + 29, y + 0);	printf("%c", 187);
	gotoxy(x + 40, y + 0);	printf("%c", 187);
	gotoxy(x + 48, y + 0);	printf("%c", 187);
	gotoxy(x + 53, y + 0);	printf("%c", 187);
	gotoxy(x + 58, y + 0);	printf("%c", 187);
	gotoxy(x + 64, y + 0);	printf("%c", 187);
	// 2
	gotoxy(x + 2, y + 1);	printf("%c%c%c%c%c%c", 201, 205, 205, 205, 205, 188);
	gotoxy(x + 12, y + 1);	printf("%c", 186);
	gotoxy(x + 18, y + 1);	printf("%c", 186);
	gotoxy(x + 25, y + 1);	printf("%c%c%c", 201, 205, 205);
	gotoxy(x + 30, y + 1);	printf("%c", 187);
	gotoxy(x + 35, y + 1);	printf("%c%c", 201, 205);
	gotoxy(x + 41, y + 1);	printf("%c", 187);
	gotoxy(x + 48, y + 1);	printf("%c", 186);
	gotoxy(x + 52, y + 1);	printf("%c%c", 201, 188);
	gotoxy(x + 58, y + 1);	printf("%c", 186);
	gotoxy(x + 64, y + 1);	printf("%c", 186);
	// 3
	gotoxy(x + 7, y + 2);	printf("%c", 187);
	gotoxy(x + 12, y + 2);	printf("%c", 186);
	gotoxy(x + 18, y + 2);	printf("%c", 186);
	gotoxy(x + 25, y + 2);	printf("%c", 186);
	gotoxy(x + 30, y + 2);	printf("%c", 186);
	gotoxy(x + 35, y + 2);	printf("%c", 186);
	gotoxy(x + 38, y + 2);	printf("%c", 201);
	gotoxy(x + 41, y + 2);	printf("%c", 186);
	gotoxy(x + 51, y + 2);	printf("%c%c", 201, 188);
	gotoxy(x + 58, y + 2);	printf("%c", 186);
	gotoxy(x + 64, y + 2);	printf("%c", 186);
	// 4
	gotoxy(x + 0, y + 3);	printf("%c%c%c%c%c", 200, 205, 205, 205, 205);
	gotoxy(x + 7, y + 3);	printf("%c", 186);
	gotoxy(x + 12, y + 3);	printf("%c", 186);
	gotoxy(x + 18, y + 3);	printf("%c", 186);
	gotoxy(x + 25, y + 3);	printf("%c", 186);
	gotoxy(x + 30, y + 3);	printf("%c", 186);
	gotoxy(x + 37, y + 3);	printf("%c%c", 201, 188);
	gotoxy(x + 41, y + 3);	printf("%c", 186);
	gotoxy(x + 48, y + 3);	printf("%c%c", 201, 205);
	gotoxy(x + 52, y + 3);	printf("%c", 187);
	gotoxy(x + 58, y + 3);	printf("%c", 186);
	gotoxy(x + 64, y + 3);	printf("%c", 186);
	// 5
	gotoxy(x + 7, y + 4);	printf("%c", 186);
	gotoxy(x + 10, y + 4);	printf("%c", 200);
	gotoxy(x + 17, y + 4);	printf("%c%c", 201, 188);
	gotoxy(x + 29, y + 4);	printf("%c%c", 201, 188);
	gotoxy(x + 33, y + 4);	printf("%c", 200);
	gotoxy(x + 40, y + 4);	printf("%c%c", 201, 188);
	gotoxy(x + 48, y + 4);	printf("%c", 186);
	gotoxy(x + 53, y + 4);	printf("%c", 187);
	gotoxy(x + 56, y + 4);	printf("%c", 200);
	gotoxy(x + 63, y + 4);	printf("%c%c", 201, 188);
	// 6
	gotoxy(x, y + 5);	printf("%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c     %c%c%c%c%c%c%c    %c%c%c%c%c%c%c     %c%c%c  %c%c%c   %c%c%c%c%c%c%c ", 200, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 188, 200, 205, 188, 200, 205, 205, 205, 205, 205, 188);
	SetColor();
}

void putFrame(int x, int y, int color, int zoom)
{
	SetColor(color);
	for (int i = 0; i <= 18 * zoom; i++)
	{
		gotoxy(x, y);
		for (int j = 0; j <= 36 * zoom; j++)
		{
			if (j == 0)
			{
				if (i == 0)
					printf("%c", 201);
				else if (i == 18 * zoom)
					printf("%c", 200);
				else if (i % (6 * zoom) == 0)
					printf("%c", 204);
				else if (i % (2 * zoom) == 0)
					printf("%c", 199);
				else
					printf("%c", 186);
			}

			else if (j == 36 * zoom)
			{
				if (i == 0)
					printf("%c", 187);
				else if (i == 18 * zoom)
					printf("%c", 188);
				else if (i % (6 * zoom) == 0)
					printf("%c", 185);
				else if (i % (2 * zoom) == 0)
					printf("%c", 182);
				else
					printf("%c", 186);
			}

			else if (j % (12 * zoom) == 0)
			{
				if (i == 0)
					printf("%c", 203);
				else if (i == 18 * zoom)
					printf("%c", 202);
				else if (i % (6 * zoom) == 0)
					printf("%c", 206);
				else if (i % (2 * zoom) == 0)
					printf("%c", 215);
				else
					printf("%c", 186);
			}

			else if (j % (4 * zoom) == 0)
			{
				if (i == 0)
					printf("%c", 209);
				else if (i == 18 * zoom)
					printf("%c", 207);
				else if (i % (6 * zoom) == 0)
					printf("%c", 216);
				else if (i % (2 * zoom) == 0)
				{
					SetColor(color - 8);
					printf("%c", 197);
					SetColor(color);
				}
				else
				{
					SetColor(color - 8);
					printf("%c", 179);
					SetColor(color);
				}

			}

			else
			{
				if (i == 0)
					printf("%c", 205);
				else if (i == 18 * zoom)
					printf("%c", 205);
				else if (i % (6 * zoom) == 0)
					printf("%c", 205);
				else if (i % (2 * zoom) == 0)
				{
					SetColor(color - 8);
					printf("%c", 196);
					SetColor(color);
				}
				else
					printf(" ");
			}
		}
		y++;
	}
	SetColor();
}

void putPointer(int x, int y, bool Visible)
{
	if (Visible)
	{
		gotoxy(x - 3, y - 1);	printf("%c", 218);
		gotoxy(x - 3, y);		printf("%c", 179);
		gotoxy(x - 3, y + 1);	printf("%c", 192);
		gotoxy(x + 3, y - 1);	printf("%c", 191);
		gotoxy(x + 3, y);		printf("%c", 179);
		gotoxy(x + 3, y + 1);	printf("%c", 217);
	}
	else
	{
		gotoxy(x - 3, y - 1);	printf(" ");
		gotoxy(x - 3, y);		printf(" ");
		gotoxy(x - 3, y + 1);	printf(" ");
		gotoxy(x + 3, y - 1);	printf(" ");
		gotoxy(x + 3, y);		printf(" ");
		gotoxy(x + 3, y + 1);	printf(" ");
	}
	gotoxy(0, 0);
}

void putNumber(int key, int Color, int x, int y)
{
	SetColor(Color);
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
		{
			gotoxy(x + i, y + j);
			printf(" ");
		}

	switch (key)
	{
	case 1:
		gotoxy(x, y - 1);		printf("%c", 187);
		gotoxy(x, y + 1);		printf("%c", 202);
		gotoxy(x, y);			printf("%c", 186);
		break;
	case 2:
		gotoxy(x - 1, y - 1);	printf("%c", 205);
		gotoxy(x, y - 1);		printf("%c", 205);
		gotoxy(x + 1, y - 1);	printf("%c", 187);
		gotoxy(x + 1, y);		printf("%c", 188);
		gotoxy(x - 1, y);		printf("%c", 201);
		gotoxy(x - 1, y + 1);	printf("%c", 200);
		gotoxy(x, y + 1);		printf("%c", 205);
		gotoxy(x + 1, y + 1);	printf("%c", 205);
		gotoxy(x, y);			printf("%c", 205);
		break;
	case 3:
		gotoxy(x - 1, y - 1);	printf("%c", 205);
		gotoxy(x, y - 1);		printf("%c", 205);
		gotoxy(x + 1, y - 1);	printf("%c", 187);
		gotoxy(x + 1, y);		printf("%c", 185);
		gotoxy(x - 1, y + 1);	printf("%c", 205);
		gotoxy(x, y + 1);		printf("%c", 205);
		gotoxy(x + 1, y + 1);	printf("%c", 188);
		gotoxy(x, y);			printf("%c", 205);
		break;
	case 4:
		gotoxy(x - 1, y - 1);	printf("%c", 183);
		gotoxy(x + 1, y - 1);	printf("%c", 183);
		gotoxy(x + 1, y);		printf("%c", 185);
		gotoxy(x - 1, y);		printf("%c", 200);
		gotoxy(x + 1, y + 1);	printf("%c", 186);
		gotoxy(x, y);			printf("%c", 205);
		break;
	case 5:
		gotoxy(x - 1, y - 1);	printf("%c", 201);
		gotoxy(x, y - 1);		printf("%c", 205);
		gotoxy(x + 1, y - 1);	printf("%c", 205);
		gotoxy(x + 1, y);		printf("%c", 187);
		gotoxy(x - 1, y);		printf("%c", 200);
		gotoxy(x - 1, y + 1);	printf("%c", 205);
		gotoxy(x, y + 1);		printf("%c", 205);
		gotoxy(x + 1, y + 1);	printf("%c", 188);
		gotoxy(x, y);			printf("%c", 205);
		break;
	case 6:
		gotoxy(x - 1, y - 1);	printf("%c", 201);
		gotoxy(x, y - 1);		printf("%c", 205);
		gotoxy(x + 1, y - 1);	printf("%c", 205);
		gotoxy(x + 1, y);		printf("%c", 187);
		gotoxy(x - 1, y);		printf("%c", 204);
		gotoxy(x - 1, y + 1);	printf("%c", 200);
		gotoxy(x, y + 1);		printf("%c", 205);
		gotoxy(x + 1, y + 1);	printf("%c", 188);
		gotoxy(x, y);			printf("%c", 205);
		break;
	case 7:
		gotoxy(x - 1, y - 1);	printf("%c", 205);
		gotoxy(x, y - 1);		printf("%c", 205);
		gotoxy(x + 1, y - 1);	printf("%c", 187);
		gotoxy(x + 1, y);		printf("%c", 206);
		gotoxy(x + 1, y + 1);	printf("%c", 186);
		gotoxy(x, y);			printf("%c", 205);
		break;
	case 8:
		gotoxy(x - 1, y - 1);	printf("%c", 201);
		gotoxy(x, y - 1);		printf("%c", 205);
		gotoxy(x + 1, y - 1);	printf("%c", 187);
		gotoxy(x + 1, y);		printf("%c", 185);
		gotoxy(x - 1, y);		printf("%c", 204);
		gotoxy(x - 1, y + 1);	printf("%c", 200);
		gotoxy(x, y + 1);		printf("%c", 205);
		gotoxy(x + 1, y + 1);	printf("%c", 188);
		gotoxy(x, y);			printf("%c", 205);
		break;
	case 9:
		gotoxy(x - 1, y - 1);	printf("%c", 201);
		gotoxy(x, y - 1);		printf("%c", 205);
		gotoxy(x + 1, y - 1);	printf("%c", 187);
		gotoxy(x + 1, y);		printf("%c", 185);
		gotoxy(x - 1, y);		printf("%c", 200);
		gotoxy(x - 1, y + 1);	printf("%c", 205);
		gotoxy(x, y + 1);		printf("%c", 205);
		gotoxy(x + 1, y + 1);	printf("%c", 188);
		gotoxy(x, y);			printf("%c", 205);
		break;
	}
	SetColor();
	gotoxy(0, 0);
}

void PrintSudoku(info *LinkRow, int x, int y, bool is_full, bool error)
{
	int X = x + 4;
	int Y = y + 2;
	for (int i = 0; i < 9; i++)
	{
		ref q = LinkRow[i].head;
		do
		{
			if (q->is_stable == false)
			{
				if (q->is_error)
					putNumber(q->key, Red, X, Y);
				else
					putNumber(q->key, Yellow, X, Y);
			}
			else if (is_full)
			{
				putNumber(q->key, Cyan, X, Y);
			}
			X = X + 8;
			q = q->next_row;
		} while (q != LinkRow[i].head);
		X = x + 4;
		Y = Y + 4;
	}
}

void PrintCenter(info *LinkRow, int x, int y)
{
	int X = x + 17;
	int Y = y + 13;
	SetColor(Cyan_D);
	for (int i = 1; i < 12; i++)
	{
		gotoxy(X, Y);
		for (int j = 1; j < 40; j++)
		{
			if (j == 8 || j == 32)
			{
				SetColor(Cyan);
				if (i == 4 || i == 8)
					printf("%c", 215);
				else
					printf("%c", 186);
				SetColor(Cyan_D);
			}
			else if (j == 16 || j == 24)
			{
				if (i == 4 || i == 8)
					printf("%c", 197);
				else
					printf("%c", 179);
			}
			else
			{
				if (i == 4 || i == 8)
					printf("%c", 196);
				else
					printf(" ");
			}
		}
		Y++;
	}
	ref q;
	for (int i = 3; i <= 5; i++)
	{
		X = x + 20;
		Y = y + 2 + 4 * i;
		q = LinkRow[i].head->next_row->next_row;
		for (int j = 0; j < 5; j++)
		{
			if (q->key != 0 && q->is_stable == false)
				putNumber(q->key, Yellow, X, Y);
			else if (q->key != 0 && q->is_stable == true)
				putNumber(q->key, Cyan, X, Y);

			q = q->next_row;
			X = X + 8;
		}
	}
	gotoxy(0, 0);
}

void putPopup(int x, int y, int width, int height, char *str0)
{
	SetColor(7);
	int X = x + 36 - width/2;
	int Y = y + 18 - height/2;
	for (int i = 0; i < height; i++)
	{
		gotoxy(X, Y);
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				if (i == 0)
					printf("%c", 201);
				else if (i == height - 1)
					printf("%c", 200);
				else
					printf("%c", 186);
			}
			else if (j == width - 1)
			{
				if (i == 0)
					printf("%c", 187);
				else if (i == height - 1)
					printf("%c", 188);
				else
					printf("%c", 186);
			}
			else
			{
				if (i == 0 || i == height - 1)
					printf("%c", 205);
				else
					printf(" ");
			}
		}
		Y++;
	}
	if (str0)
	{
		SetColor(7);
		int len = strlen(str0);
		X = x + 36 - len / 2;
		Y = y + 18 - 1;
		gotoxy(X, Y);
		printf("%s", str0);
	}
	SetColor(White);
}

void ButtonFunction(int Border, int Highlight, int FontColor)
{
	putFuntion(Enter, 34, 39, Border, Highlight, FontColor);
	putFuntion(New, 9, 39, Border, Highlight, FontColor);
	putFuntion(Esc, 9, 42, Border, Highlight, FontColor);
	putFuntion(Erase, 26, 42, Border, Highlight, FontColor);
	putFuntion(Check, 45, 42, Border, Highlight, FontColor);
	putFuntion(Hint, 64, 42, Border, Highlight, FontColor);
}

void putFuntion(int key, int x, int y, int Border, int Highlight, int FontColor)
{
	switch (key)
	{
	case Enter:
		SetColor(Border);
		gotoxy(x, y + 0); printf("%c", 218);
		gotoxy(x, y + 1); printf("%c", 179);
		gotoxy(x, y + 2); printf("%c", 192);

		for (int i = 1; i <= 46; i++)
		{
			gotoxy(x + i, y); printf("%c", 196);
			gotoxy(x + i, y + 2); printf("%c", 196);
		}

		gotoxy(x + 47, y + 0); printf("%c", 191);
		gotoxy(x + 47, y + 1); printf("%c", 179);
		gotoxy(x + 47, y + 2); printf("%c", 217);

		SetColor(Highlight);
		gotoxy(x + 7, y + 1); printf("E N T E R");
		SetColor(FontColor);
		printf("    a d m i n   c o d e");
		break;

	case New:
		SetColor(Border);
		gotoxy(x, y + 0); printf("%c", 218);
		gotoxy(x, y + 1); printf("%c", 179);
		gotoxy(x, y + 2); printf("%c", 192);

		for (int i = 1; i <= 21; i++)
		{
			gotoxy(x + i, y); printf("%c", 196);
			gotoxy(x + i, y + 2); printf("%c", 196);
		}

		gotoxy(x + 22, y + 0); printf("%c", 191);
		gotoxy(x + 22, y + 1); printf("%c", 179);
		gotoxy(x + 22, y + 2); printf("%c", 217);

		SetColor(Highlight);
		gotoxy(x + 4, y + 1); printf("N");
		SetColor(FontColor);
		printf(" e w   g a m e");
		break;

	case Esc:
		SetColor(Border);
		gotoxy(x, y + 0); printf("%c", 218);
		gotoxy(x, y + 1); printf("%c", 179);
		gotoxy(x, y + 2); printf("%c", 192);

		for (int i = 1; i <= 13; i++)
		{
			gotoxy(x + i, y); printf("%c", 196);
			gotoxy(x + i, y + 2); printf("%c", 196);
		}

		gotoxy(x + 14, y + 0); printf("%c", 191);
		gotoxy(x + 14, y + 1); printf("%c", 179);
		gotoxy(x + 14, y + 2); printf("%c", 217);

		SetColor(Highlight);
		gotoxy(x + 5, y + 1); printf("E S C");
		break;

	case Hint:
		SetColor(Border);
		gotoxy(x, y + 0); printf("%c", 218);
		gotoxy(x, y + 1); printf("%c", 179);
		gotoxy(x, y + 2); printf("%c", 192);

		for (int i = 1; i <= 16; i++)
		{
			gotoxy(x + i, y); printf("%c", 196);
			gotoxy(x + i, y + 2); printf("%c", 196);
		}

		gotoxy(x + 17, y + 0); printf("%c", 191);
		gotoxy(x + 17, y + 1); printf("%c", 179);
		gotoxy(x + 17, y + 2); printf("%c", 217);

		SetColor(Highlight);
		gotoxy(x + 3, y + 1); printf("H");
		SetColor(FontColor);
		printf(" i n t  ( )");
		break;

	case Erase:
		SetColor(Border);
		gotoxy(x, y + 0); printf("%c", 218);
		gotoxy(x, y + 1); printf("%c", 179);
		gotoxy(x, y + 2); printf("%c", 192);

		for (int i = 1; i <= 15; i++)
		{
			gotoxy(x + i, y); printf("%c", 196);
			gotoxy(x + i, y + 2); printf("%c", 196);
		}

		gotoxy(x + 16, y + 0); printf("%c", 191);
		gotoxy(x + 16, y + 1); printf("%c", 179);
		gotoxy(x + 16, y + 2); printf("%c", 217);

		SetColor(Highlight);
		gotoxy(x + 4, y + 1); printf("E");
		SetColor(FontColor);
		printf(" r a s e");
		break;

	case Check:
		SetColor(Border);
		gotoxy(x, y + 0); printf("%c", 218);
		gotoxy(x, y + 1); printf("%c", 179);
		gotoxy(x, y + 2); printf("%c", 192);

		for (int i = 1; i <= 15; i++)
		{
			gotoxy(x + i, y); printf("%c", 196);
			gotoxy(x + i, y + 2); printf("%c", 196);
		}

		gotoxy(x + 16, y + 0); printf("%c", 191);
		gotoxy(x + 16, y + 1); printf("%c", 179);
		gotoxy(x + 16, y + 2); printf("%c", 217);

		SetColor(Highlight);
		gotoxy(x + 4, y + 1); printf("C");
		SetColor(FontColor);
		printf(" h e c k");
		break;
	}
}

void Raven(int x, int y)
{
	gotoxy(x, y);
	printf("  ^ ^  ");
	gotoxy(x, y + 1);
	printf(" (o,o) ");
	gotoxy(x, y + 2);
	printf("((   ))");
	gotoxy(x, y + 3);
	printf(" -%c-%c-", 34, 34);
}

void Owl(int x, int y)
{
	gotoxy(x, y);
	printf("{O,O}");
	gotoxy(x, y + 1);
	printf("/)_)");
	gotoxy(x, y + 2);
	printf(" %c %c ", 34, 34);
}

void FlappyBird(int x, int y)
{
	SetColor(White_D);
	gotoxy(x, y + 0);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 220, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 220);
	gotoxy(x, y + 1);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 32, 220, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 219, 223, 32, 32, 32, 32, 219, 220);
	gotoxy(x, y + 2);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 223, 32, 32, 32, 32, 32, 32, 219, 220);
	gotoxy(x, y + 3);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 223, 32, 32, 32, 32, 32, 32, 32, 32, 219, 220);
	gotoxy(x, y + 4);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219);
	gotoxy(x, y + 5);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 32, 32, 32, 32, 32, 32, 219, 219, 32, 32, 219, 219);
	gotoxy(x, y + 6);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 220, 32, 32, 32, 32, 32, 219, 219, 32, 32, 219, 219);
	gotoxy(x, y + 7);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 219, 219, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219);
	gotoxy(x, y + 8);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(x, y + 9);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 176, 176, 176, 176, 219, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 219);
	gotoxy(x, y + 10); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 176, 176, 176, 219, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 219);
	gotoxy(x, y + 11); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 223, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 177, 177, 177, 177, 219, 178, 178, 178, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 223);
	gotoxy(x, y + 12); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 219, 219, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 219, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 219);
	gotoxy(x, y + 13); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 219, 219, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 219, 219, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 219);
	gotoxy(x, y + 14); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 219, 219, 219, 219, 219, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(x, y + 15); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32, 32, 32, 32, 223, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 223);
	//SetColor();
}

void putWinner(int x, int y)
{
	int i = 0;
	putPopup(x, y, 49, 10, "");
	do
	{
		i++;
		SetColor(i % 15 + 1);
		gotoxy(30, 16); printf("%c %c | %c ||  |_   _|     / | / /", 92, 92, 92);
		gotoxy(30, 17); printf(" %c %c|| %c||    | |      / /|/ /", 92, 92, 92);
		gotoxy(30, 18); printf("  %c %c|%c ||    | |     / /|| /", 92, 92, 92);
		gotoxy(30, 19); printf("   %c_| %c |  |_____|  / / | /", 92, 92);
		Raven(23, 16);
		Raven(61, 16);
		gotoxy(26, 21);
		SetColor();
		printf("Press 'Enter' to get back to main menu!");
		gotoxy(0, 0);
		Sleep(500);
	} while (!_kbhit());
	
}