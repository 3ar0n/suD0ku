#include "suD0ku.h"

void LoadingScreen(int x, int y)
{
	int i = 0;
	do
	{
		if (i == 0)
			SetColor(8);
		else if (i == 1)
			SetColor(7);
		else if (i == 2)
			SetColor(15);
		else
			SetColor(Cyan);
		Sleep(50 + i * 100);
		gotoxy(x, y + 0); printf("         __________         ____  ___");
		gotoxy(x, y + 1); printf("        /   _________      /   /  ___");
		gotoxy(x, y + 2); printf("       /   /__________    /   /   ___");
		gotoxy(x, y + 3); printf("      /   /___________   /   /    ___     __      ___    ___________    __________ ");
		gotoxy(x, y + 4); printf("     /   /___________   /   /     ___    |  |    ___    /  ________    /  _________");
		gotoxy(x, y + 5); printf("    /   __________     /   /      ___    |  |   ___    /  /_______    /  /     ___");
		gotoxy(x, y + 6); printf("   /   / _____        /   /____________  |  |  ___    /  ________    /  /     ___");
		gotoxy(x, y + 7); printf("  /   /   _____      /_________________  |  | ___    /  /           /  /     ___");
		gotoxy(x, y + 8); printf(" /   /     _____                  ___    |  |___    /  /_______    /  /     ___");
		gotoxy(x, y + 9); printf("/___/       _____                 ___    |_____    /__________    /__/     ___");

		gotoxy(x, y + 12); printf("           _________________");
		gotoxy(x, y + 13); printf("          /______    ______");
		gotoxy(x, y + 14); printf("                /   /      ___________   ______       ____     ______  ");
		gotoxy(x, y + 15); printf("               /   /      /  ________   /  ____      /  ___   /______ ");
		gotoxy(x, y + 16); printf("              /   /      /  /_______   /  / ___     /  / ___ /__ |___  ");
		gotoxy(x, y + 17); printf("             /   /      /  ________   /  /_____    /  /   _____  |___ ");
		gotoxy(x, y + 18); printf("            /   /      /  /_______   /  _______   /  /     ___   |___");
		gotoxy(x, y + 19); printf("           /___/      /__________   /__/    ___  /__/            |___ ");
		i++;
	} while (i < 4);
	Sleep(50);
	LoadingBar(0, 43, 91, Cyan);
}

void LoadingBar(int x, int y, int size, int Color)
{
	SetColor(Color);
	gotoxy(40, y - 2);
	printf("Loading...");
	gotoxy(x, y - 1);
	for (int i = 0; i < size; i++)
		printf("%c", 196);
	gotoxy(x, y + 1);
	for (int i = 0; i < size; i++)
		printf("%c", 196);

	for (int i = 0; i < size; i++)
	{
		gotoxy(x + i, y - 1);
		printf("%c", 220);
		gotoxy(x + i, y);
		printf("%c", 219);
		gotoxy(x + i, y + 1);
		printf("%c", 223);
		if (i < size - 1)
			Sleep(10 + i);
		else
			Sleep(200);
	}
	gotoxy(0, 0);
	SetColor();
}

void CreateMenu(opt *head)
{
	opt p1 = (opt)malloc(sizeof(menu));
	p1->value = 1;
	strcpy(p1->text, "   N E W   G A M E   ");

	opt p2 = (opt)malloc(sizeof(menu));
	p2->value = 2;
	strcpy(p2->text, "   C O N T I N U E   ");

	opt p3 = (opt)malloc(sizeof(menu));
	p3->value = 3;
	strcpy(p3->text, "H O W   T O   P L A Y");

	opt p4 = (opt)malloc(sizeof(menu));
	p4->value = 4;
	strcpy(p4->text, "      A B O U T      ");

	opt p5 = (opt)malloc(sizeof(menu));
	p5->value = 5;
	strcpy(p5->text, "       E X I T       ");

	*head = p1;
	p1->prev = NULL;
	p2->prev = p1;
	p3->prev = p2;
	p4->prev = p3;
	p5->prev = p4;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
}

int Select(opt head, int x, int y, bool saved)
{
	int Key;
	int X = x, Y = y + 3;
	opt p = head;
	SetColor(Cyan_D);
	while (p)
	{
		gotoxy(x, y + p->value * 3);
		if (p->value == 2 && !saved)
		{
			SetColor(Grey);
			printf("%s", p->text);
			putBorder(Grey, x, y + p->value * 3);
			SetColor(Cyan_D);
		}
		else
		{
			printf("%s", p->text);
			putBorder(Cyan_D, x, y + p->value * 3);
		}
		p = p->next;
	}
	p = head;
	gotoxy(X, Y);
	SetColor(Cyan);
	printf("%s", p->text);
	putBorder(Cyan, X, Y);
	gotoxy(0, 0);
	do
	{
		Key = Read_Key();
		if (Key == Up || Key == Down)
		{
			if (Key == Up && p->prev)
			{
				gotoxy(X, Y);
				SetColor(Cyan_D);
				printf("%s", p->text);
				putBorder(Cyan_D, X, Y);
				
				p = p->prev;
				Y = Y - 3;
				if (p->value == 2 && !saved)
				{
					p = p->prev;
					Y = Y - 3;
				}

				gotoxy(X, Y);
				SetColor(Cyan);
				printf("%s", p->text);
				putBorder(Cyan, X, Y);
			}
			if (Key == Down && p->next)
			{
				gotoxy(X, Y);
				SetColor(Cyan_D);
				printf("%s", p->text);
				putBorder(Cyan_D, X, Y);

				p = p->next;
				Y = Y + 3;
				if (p->value == 2 && !saved)
				{
					p = p->next;
					Y = Y + 3;
				}

				gotoxy(X, Y);
				SetColor(Cyan);
				printf("%s", p->text);
				putBorder(Cyan, X, Y);
			}
		}
		gotoxy(0, 0);
	} while (Key != Enter);
	SetColor(15);
	return p->value;
}

void putBorder(int color, int x, int y, int width)
{
	int i;
	SetColor(color);
	
	gotoxy(x - 3, y - 1);
	for (i = 0; i <= width + 5; i++)
		printf("%c", 196);

	gotoxy(x - 3, y + 1);
	for (i = 0; i <= width + 5; i++)
		printf("%c", 196);
	gotoxy(x - 4, y - 1);			printf("%c", 218);
	gotoxy(x - 4, y);				printf("%c", 179);
	gotoxy(x - 4, y + 1);			printf("%c", 192);
	gotoxy(x + width + 3, y - 1);	printf("%c", 191);
	gotoxy(x + width + 3, y);		printf("%c", 179);
	gotoxy(x + width + 3, y + 1);	printf("%c", 217);
}

void ExitOpt(opt *head)
{
	opt e1 = (opt)malloc(sizeof(menu));
	e1->value = 5;
	strcpy(e1->text, "Y E S");

	opt e2 = (opt)malloc(sizeof(menu));
	e2->value = 0;
	strcpy(e2->text, " N O ");

	*head = e1;
	e1->prev = NULL;
	e2->prev = e1;
	e1->next = e2;
	e2->next = NULL;
}

int Exit(opt head, int x, int y)
{
	int Key;
	int d = 21;
	opt p = head->next;

	SetColor(Cyan);
	gotoxy(x, y);
	printf("%s", p->text);
	putBorder(Cyan, x, y, 5);

	SetColor(Cyan_D);
	gotoxy(x - d, y);
	printf("%s", p->prev->text);
	putBorder(Cyan_D, x - d, y, 5);

	gotoxy(0, 0);
	do
	{
		Key = Read_Key();
		if (Key == Left || Key == Right)
		{
			if (Key == Left && p != head)
			{
				gotoxy(x, y);
				SetColor(Cyan_D);
				printf("%s", p->text);
				putBorder(Cyan_D, x, y, 5);
				p = p->prev;
				x = x - d;

				gotoxy(x, y);
				SetColor(11);
				printf("%s", p->text);
				putBorder(Cyan, x, y, 5);
			}
			if (Key == Right && p == head)
			{
				gotoxy(x, y);
				SetColor(Cyan_D);
				printf("%s", p->text);
				putBorder(Cyan_D, x, y, 5);

				p = p->next;
				x = x + d;

				gotoxy(x, y);
				SetColor(Cyan);
				printf("%s", p->text);
				putBorder(Cyan, x, y, 5);
			}
		}
		gotoxy(0, 0);
	} while (Key != Enter);
	SetColor();
	return p->value;
}