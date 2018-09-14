#include "suD0ku.h"

void RuleOpt(opt *head)
{
	opt h1 = (opt)malloc(sizeof(menu));
	h1->value = 1;
	strcpy(h1->text, "- the numbers 1 to 9 appear exactly once in each row");

	opt h2 = (opt)malloc(sizeof(menu));
	h2->value = 2;
	strcpy(h2->text, "- the numbers 1 to 9 appear exactly once in each column");

	opt h3 = (opt)malloc(sizeof(menu));
	h3->value = 3;
	strcpy(h3->text, "- the numbers 1 to 9 appear exactly once in each 3x3 box");

	*head = h1;
	h1->prev = NULL;
	h2->prev = h1;
	h3->prev = h2;
	h1->next = h2;
	h2->next = h3;
	h3->next = NULL;
}

void SelectRule(opt head, int x, int y)
{
	int Key;
	opt p = head;
	info *ROW, *COL, *CELL;

	SetColor(White, Pink_D);
	gotoxy(x, y);
	printf("%s", p->text);

	SetColor(White);
	gotoxy(x, y + 1);
	printf("%s", p->next->text);

	gotoxy(x, y + 2);
	printf("%s", p->next->next->text);

	SetColor(White);
	SetRandomMode(&ROW, &COL, &CELL, p->value);
	PrintSudoku_v2(ROW, 26, 17);

	do
	{
		Key = Read_Key();
		if (Key == Up || Key == Down)
		{
			if (Key == Up && p->prev)
			{
				gotoxy(x, y);
				SetColor(White);
				printf("%s", p->text);

				y = y - 1;
				p = p->prev;

				gotoxy(x, y);
				SetColor(White, Pink_D);
				printf("%s", p->text);
				SetColor(White);
				SetRandomMode(&ROW, &COL, &CELL, p->value);
				PrintSudoku_v2(ROW, 26, 17);
				ClearTable(ROW);
			}
			if (Key == Down && p->next)
			{
				gotoxy(x, y);
				SetColor(White);
				printf("%s", p->text);

				y = y + 1;
				p = p->next;

				gotoxy(x, y);
				SetColor(White, Pink_D);
				printf("%s", p->text);
				SetColor(White);
				SetRandomMode(&ROW, &COL, &CELL, p->value);
				PrintSudoku_v2(ROW, 26, 17);
				ClearTable(ROW);
			}
		}
	} while (Key != Esc);
	SetColor();
	//return p->value;
}

void PrintSudoku_v2(info *LinkRow, int x, int y)
{
	int X = x + 2;
	int Y = y + 1;
	for (int i = 0; i < 9; i++)
	{
		ref q = LinkRow[i].head;
		do
		{
			gotoxy(X, Y);
			if (q->key != 0)
				printf("%d", q->key);

			else
				printf(" ");
			X = X + 4;
			q = q->next_row;
		} while (q != LinkRow[i].head);
		X = x + 2;
		Y = Y + 2;
	}
	gotoxy(0, 0);
}

void SetRandomMode(info **LinkRow, info **LinkCol, info **LinkCell, int mode)
{
	srand((unsigned)time(NULL));
	CreateTable(LinkRow, LinkCol, LinkCell);
	int i, j;
	j = rand() % 9;
	ref p;
	switch (mode)
	{
	case 1:
		p = (*LinkRow + j)->head;
		for (i = 0; i < 9; i++)
		{
			while (1)
			{
				p->key = rand() % 9 + 1;
				if (CheckValue(p, a_row) == false)
					break;
			}
			p = p->next_row;
		}
		break;
	case 2:
		p = (*LinkCol + j)->head;
		for (i = 0; i < 9; i++)
		{
			while (1)
			{
				p->key = rand() % 9 + 1;
				if (CheckValue(p, a_col) == false)
					break;
			}
			p = p->next_col;
		}
		break;
	case 3:
		p = (*LinkCell + j)->head;
		for (i = 0; i < 9; i++)
		{
			while (1)
			{
				p->key = rand() % 9 + 1;
				if (CheckValue(p, a_cell) == false)
					break;
			}
			p = p->next_cell;
		}
		break;
	}
}

void HowToPlay()
{
	putLogo(13, 1, White, Cyan);
	gotoxy(35, 9);
	SetColor(Green);
	printf("G A M E   G U I D E");
	gotoxy(23, 10);
	printf("-------------------------------------------\n");
	SetColor();
	printf("      With the classic sudoku puzzles, you have to fill 9x9 grid with numbers that:");
	putFrame(26, 17, White, 1);
	gotoxy(36, 37);
	SetColor(Green);
	printf("S H O R T C U T S");
	gotoxy(23, 38);
	printf("-------------------------------------------\n");
	SetColor();
	printf("  Press ");
	SetColor(Pink);
	printf("'0'");
	SetColor();
	printf(" clear the value at current cell\n");
	printf("  Press ");
	SetColor(Pink);
	printf("'N'");
	SetColor();
	printf(" to start a new game\n");
	printf("  Press ");
	SetColor(Pink);
	printf("'E'");
	SetColor();
	printf(" to clear all filled values in the table\n");
	printf("  Press ");
	SetColor(Pink);
	printf("'H'");
	SetColor();
	printf(" to reveal right value of the cell which is pointed\n");
	printf("  Press ");
	SetColor(Pink);
	printf("'C'");
	SetColor();
	printf(" to check the result, if you've fill all the cells without incorrect, you win\n");
	//printf("  Press ");
	//SetColor(Pink);
	//printf("'Enter'");
	//SetColor();
	//printf(" then press Password to see answer\n");
	printf("  Press ");
	SetColor(Pink);
	printf("'Esc'");
	SetColor();
	printf(" to get back to the main menu");
	opt headHow;
	RuleOpt(&headHow);
	int how;
	SelectRule(headHow, 17, 13);

	ClearMenu(headHow);
}