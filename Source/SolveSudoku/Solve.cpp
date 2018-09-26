#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

typedef struct sudoku * ref;
struct sudoku
{
	int row;
	int col;
	int key;
	bool stable;
	ref next_row;
	ref next_col;
	ref next_cell;
};

struct info
{
	ref head;
};

#define Up 22472
#define Left 22475
#define Right 22477
#define Down 22480
#define Enter 13
#define a_row 1001
#define a_col 1002
#define a_cell 1003

int Read_Key();
void gotoxy(SHORT x, SHORT y);
void SetColor(int Color = 15);
void SetWindowsSize(SHORT x, SHORT y);
void putFrame(int x = 0, int y = 0);
void putPointer(int x = 0, int y = 0);
void putNumber(int key, int Color, int x = 0, int y = 0);
void Pointer(info *LinkRow, int x = 0, int y = 0);

bool CheckValue(ref p, int mode);
ref CreateNode(int row, int col);
void AddNode(ref *head, ref p, int mode);
ref BeforeNode(ref p, int mode);
void CreateTable(info **LinkRow, info **LinkCol, info **LinkCell);
void ClearTable(info *LinkRow);
void PrintSudoku(info *LinkRow, int x = 0, int y = 0);
void SolveSudoku(info *LinkRow, bool *check, ref p = NULL);

int Read_Key()
{
	int key = - 1;
	switch (_getch())
	{
	case 13: key = Enter; break;
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

void SetColor(int Color)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Color);
}

void SetWindowsSize(SHORT x, SHORT y)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTitle("SUDOKU");

	SMALL_RECT windowSize = { 0, 0, x - 1, y - 1 };
	SetConsoleWindowInfo(hConsole, true, &windowSize);

	if (y == 25)
		y = 10;
	COORD bufferSize = { x, y };
	SetConsoleScreenBufferSize(hConsole, bufferSize);
}

void putFrame(int x, int y)
{
	SetColor(11);
	for (int i = 0; i <= 36; i++)
	{
		gotoxy(x, y);
		for (int j = 0; j <= 72; j++)
		{
			if (j == 0)
			{
				if (i == 0)
					printf("%c", 201);
				else if (i == 36)
					printf("%c", 200);
				else if (i % 12 == 0)
					printf("%c", 204);
				else if (i % 4 == 0)
					printf("%c", 199);
				else
					printf("%c", 186);
			}

			else if (j == 72)
			{
				if (i == 0)
					printf("%c", 187);
				else if (i == 36)
					printf("%c", 188);
				else if (i % 12 == 0)
					printf("%c", 185);
				else if (i % 4 == 0)
					printf("%c", 182);
				else
					printf("%c", 186);
			}

			else if (j % 24 == 0)
			{
				if (i == 0)
					printf("%c", 203);
				else if (i == 36)
					printf("%c", 202);
				else if (i % 12 == 0)
					printf("%c", 206);
				else if (i % 4 == 0)
					printf("%c", 215);
				else
					printf("%c", 186);
			}

			else if (j % 8 == 0)
			{
				if (i == 0)
					printf("%c", 209);
				else if (i == 36)
					printf("%c", 207);
				else if (i % 12 == 0)
					printf("%c", 216);
				else if (i % 4 == 0)
				{
					SetColor(3);
					printf("%c", 197);
					SetColor(11);
				}
				else
				{
					SetColor(3);
					printf("%c", 179);
					SetColor(11);
				}

			}

			else
			{
				if (i == 0)
					printf("%c", 205);
				else if (i == 36)
					printf("%c", 205);
				else if (i % 12 == 0)
					printf("%c", 205);
				else if (i % 4 == 0)
				{
					SetColor(3);
					printf("%c", 196);
					SetColor(11);
				}
				else
					printf(" ");
			}
		}
		y++;
	}
	printf("\n");
	SetColor();
}

void putPointer(int x, int y)
{
	gotoxy(x - 3, y - 1);	printf("%c", 201);
	gotoxy(x - 3, y);		printf("%c", 186);
	gotoxy(x - 3, y + 1);	printf("%c", 200);
	gotoxy(x + 3, y - 1);	printf("%c", 187);
	gotoxy(x + 3, y);		printf("%c", 186);
	gotoxy(x + 3, y + 1);	printf("%c", 188);
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

void Pointer(info *LinkRow, int x, int y)
{
	int Key;
	int X = x + 4, Y = y + 2;
	ref p = LinkRow[0].head;
	putPointer(X, Y);
	do
	{
		Key = Read_Key();
		if (Key >= 0 && Key <= 9)
		{
			int tmp = p->key;
			p->key = Key;
			if (CheckValue(p, a_row) || CheckValue(p, a_col) || CheckValue(p, a_cell))
			{
				p->key = tmp;
				putNumber(p->key, 11, X, Y);
			}
			else
			{
				putNumber(Key, 11, X, Y);
				if (Key == 0)
					p->stable = false;
				else
					p->stable = true;
			}
		}
		else
		{
			gotoxy(X - 3, Y - 1);	printf(" ");
			gotoxy(X - 3, Y);		printf(" ");
			gotoxy(X - 3, Y + 1);	printf(" ");
			gotoxy(X + 3, Y - 1);	printf(" ");
			gotoxy(X + 3, Y);		printf(" ");
			gotoxy(X + 3, Y + 1);	printf(" ");
			gotoxy(X, Y);
			if (Key == Up && Y > y + 2)
			{
				p = BeforeNode(p, a_col);
				Y = Y - 4;
			}
			if (Key == Down && Y < y + 34)
			{
				p = p->next_col;
				Y = Y + 4;
			}
			if (Key == Left && X > x + 4)
			{
				p = BeforeNode(p, a_row);
				X = X - 8;
			}
				
			if (Key == Right && X < x + 68)
			{
				p = p->next_row;
				X = X + 8;
			}
			putPointer(X, Y);
		}
	} while (Key != Enter);
}

bool CheckValue(ref p, int mode)
{
	ref q;
	switch (mode)
	{
	case a_row:
		q = p->next_row;
		while (q != p)
		{
			if (q->key == p->key && q->key != 0)
				return true;
			q = q->next_row;
		}
		break;
	case a_col:
		q = p->next_col;
		while (q != p)
		{
			if (q->key == p->key && q->key != 0)
				return true;
			q = q->next_col;
		}
		break;
	case a_cell:
		q = p->next_cell;
		while (q != p)
		{
			if (q->key == p->key && q->key != 0)
				return true;
			q = q->next_cell;
		}
		break;
	}
	return false;
}

ref CreateNode(int row, int col)
{
	ref p = (ref)malloc(sizeof(sudoku));
	p->row = row;
	p->col = col;
	p->stable = false;
	p->key = 0; //p->key = (x-1) * 9 + y;
	p->next_col = NULL;
	p->next_row = NULL;
	p->next_cell = NULL;
	return p;
}

void AddNode(ref *head, ref p, int mode)
{
	ref q = *head;
	switch (mode)
	{
	case a_row:
		if (*head == NULL)
			*head = p;
		else
		{
			while (q->next_row != *head)
				q = q->next_row;
			q->next_row = p;
		}
		p->next_row = *head;
		break;
	case a_col:
		if (*head == NULL)
			*head = p;
		else
		{
			while (q->next_col != *head)
				q = q->next_col;
			q->next_col = p;
		}
		p->next_col = *head;
		break;
	case a_cell:
		if (*head == NULL)
			*head = p;
		else
		{
			while (q->next_cell != *head)
				q = q->next_cell;
			q->next_cell = p;
		}
		p->next_cell = *head;
		break;
	}
}

ref BeforeNode(ref p, int mode)
{
	ref q = NULL;
	switch (mode)
	{
		case a_row:
			q = p->next_row;
			while (q->next_row != p)
			{
				q = q->next_row;
			}
			break;
		case a_col:
			q = p->next_col;
			while (q->next_col != p)
			{
				q = q->next_col;
			}
			break;
		case a_cell:
			q = p->next_cell;
			while (q->next_cell != p)
			{
				q = q->next_cell;
			}
			break;
	}
	return q;
}

void CreateTable(info **LinkRow, info **LinkCol, info **LinkCell)
{
	int i, j;
	*LinkRow = (info*)malloc(10 * sizeof(info));
	*LinkCol = (info*)malloc(9 * sizeof(info));
	*LinkCell = (info*)malloc(9 * sizeof(info));

	ref tmp = CreateNode(9, 0);
	(*LinkRow + 9)->head = tmp;

	for (i = 0; i < 9; i++)
	{
		(*LinkRow + i)->head = NULL;
		(*LinkCol + i)->head = NULL;
		(*LinkCell + i)->head = NULL;
	}

	ref p;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
		{
			p = CreateNode(i, j);
			AddNode(&(*LinkRow + i)->head, p, a_row);

			AddNode(&(*LinkCol + j)->head, p, a_col);

			int tmp = 3 * (i / 3) + (j / 3);
			AddNode(&(*LinkCell + tmp)->head, p, a_cell);
		}
}

void ClearTable(info *LinkRow)
{
	for (int i = 0; i < 9; i++)
	{
		if (LinkRow[i].head != NULL)
		{
			ref p, q = LinkRow[i].head;
			while (q->next_row != LinkRow[i].head)
			{
				p = q;
				q = q->next_row;
				free(p);
			}
		}
	}
}

void PrintSudoku(info *LinkRow, int x, int y)
{
	int X = x + 4;
	int Y = y + 2;
	for (int i = 0; i < 9; i++)
	{
		ref q = LinkRow[i].head;
		do
		{
			//gotoxy(X, Y);
			if (q->key != 0 && q->stable == false)
				putNumber(q->key, 14, X, Y);
			X = X + 8;
			q = q->next_row;
		} while (q != LinkRow[i].head);
		X = x + 4;
		Y = Y + 4;
	}
	//putPointer(x + 4, y + 2);
}

void SolveSudoku(info *LinkRow, bool *check, ref p)
{
	int row = p->row;
	ref q;
	if (p->next_row != LinkRow[row].head)
		q = p->next_row;
	else
	{
		if (row <= 8)
			q = LinkRow[row + 1].head;
		else
			q = NULL;
	}

	if (row > 8 || (p->key == 0 && *check == false))
		return;
	else
	{
		if (p->key == 0)
		{
			*check = false;
			int j = 1;
			while (*check == false)
			{
				p->key = j;
				//PrintTable(LinkRow);
				if (q->key == 0 || q == NULL)
				{
				}
				else
				{
					if (q->next_row != LinkRow[row].head)
						q = q->next_row;
					else
					{
						if (row <= 8)
							q = LinkRow[row + 1].head;
						else
							q = NULL;
					}
				}
				if (j <= 9)
				{
					if (!CheckValue(p, a_row) && !CheckValue(p, a_col) && !CheckValue(p, a_cell))
					{
						*check = true;
						//PrintSudoku(LinkRow, 8, 1);
						SolveSudoku(LinkRow, check, q);
					}
				}
				else
				{
					p->key = 0;
					break;
				}
				j++;
			}
			if (p->key == 0 || *check == true)
				return;
		}
		else
			SolveSudoku(LinkRow, check, q);
	}
}

int main()
{
	SetWindowsSize(80, 40);

	int x = 6, y = 1; //Tọa độ gốc
	info *ROW, *COL, *CELL;
	bool check = true;

	CreateTable(&ROW, &COL, &CELL);

	putFrame(x, y);
	for (int i = 1; i <= 9; i++) {
		putNumber(i, i, 2, 4 * i - 1);
	}
	Pointer(ROW, x, y);

	ref p = ROW[0].head;
	while (p->stable == true)
	{
		if (p->next_row != ROW[p->row].head)
			p = p->next_row;
		else
			p = ROW[p->row + 1].head;
	}
	//printf("%d %d", p->row, p->col);

	SolveSudoku(ROW, &check, p);
	PrintSudoku(ROW, x, y);

	gotoxy(0, 37);
	
	if (check == false)
	{
		gotoxy(37, 38);
		printf("Can't solve");
	}

	ClearTable(ROW);
	free(ROW);
	free(COL);
	free(CELL);

	do {
		gotoxy(34, 39);
		printf("Press ESC to exit");
	} while (_getch() != 27);
	return 0;
}