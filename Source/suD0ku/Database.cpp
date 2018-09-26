#include "suD0ku.h"

ref CreateNode(int row, int col)
{
	ref p = (ref)malloc(sizeof(sudoku));
	p->row = row;
	p->col = col;
	p->is_stable = false;
	p->is_error = false;
	p->key = 0;
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

void CreateTable(info **LinkRow, info **LinkCol, info **LinkCell) //Tạo bảng danh sách liên kết 9x9
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

void ClearTable(info *LinkRow) //Xóa dữ liệu bảng 9x9
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

bool CheckValue(ref p, int mode) //Kiểm tra xem giá trị có bị trùng theo hàng/cột/vùng, nếu có trả về "true"
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

void SolveSudoku(info *LinkRow, bool *check, ref p) //Giải Sudoku (bằng đệ quy)
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

int Pointer(info *LinkRow, ref *p, int x, int y, bool Solve)
{
	int Key;
	int X = x + 4 + (*p)->col * 8, Y = y + 2 + (*p)->row * 4;
	putPointer(X , Y);
	bool out = false;
	do
	{
		Key = Read_Key();
		switch (Key)
		{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
				if (!Solve && !(*p)->is_stable)
				{
					(*p)->key = Key;
					putNumber((*p)->key, Yellow, X, Y);
				}
				break;
			case Up: case Down: case Left: case Right:
				putPointer(X, Y, false);
				gotoxy(X, Y);
				if (Key == Up && Y > y + 2)
				{
					*p = BeforeNode(*p, a_col);
					Y = Y - 4;
				}
				if (Key == Down && Y < y + 34)
				{
					*p = (*p)->next_col;
					Y = Y + 4;
				}
				if (Key == Left && X > x + 4)
				{
					*p = BeforeNode(*p, a_row);
					X = X - 8;
				}

				if (Key == Right && X < x + 68)
				{
					*p = (*p)->next_row;
					X = X + 8;
				}
				putPointer(X, Y);
				break;
			case Esc: case Enter: case New: case Erase: case Check: case Hint:
				putPointer(X, Y, false);
				out = true;
				break;
		}
	} while (!out);
	return Key;
}

void SetRandomValue(info *LinkRow, int difficulty) //Đục lỗ bảng "kết quả"
{
	srand((unsigned)time(NULL));
	bool check = true;
	ref p = LinkRow[0].head;
	int i, j;
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
	p = LinkRow[1].head;
	SolveSudoku(LinkRow, &check, p);

	for (i = 0; i < 9; i++)
	{
		p = LinkRow[i].head;
		for (j = 0; j < 9; j++)
		{
			int Ran = rand();
			if (Ran % (difficulty + 1) == 0 || Ran % (10 - difficulty) == 0)
			{
				p->is_stable = true;
			}
			else
			{
				p->is_stable = false;
				p->key = 0;
			}	
			p = p->next_row;
		}
	}
}

void CopyData(info *RowSource, info *RowDest, bool is_full) //Sao chép dữ liệu (chỉ những số "stable") từ bảng liên kết này sang bảng liên kết khác
{
	ref p, q;
	for (int i = 0; i < 9; i++)
	{
		q = RowSource[i].head;
		p = RowDest[i].head;
		do
		{
			if (q->is_stable)
			{
				p->key = q->key;
				p->is_stable = true;
			}
			else
			{
				if (is_full)
					p->key = q->key;
				else
					p->key = 0;
				p->is_stable = false;
			}
			q = q->next_row;
			p = p->next_row;
		} while (q != RowSource[i].head);
	}
}

void enterCode(int x, int y, char *str)
{
	char tmp;
	int i = 0;
	do
	{
		gotoxy(x, y);
		tmp = _getch();

		if ((tmp >= 32 && tmp <= 126) && i < 19)
		{
			str[i] = tmp;
			i++;
			printf("%c", tmp);
			x++;
		}
		else if (tmp == 8 && i > 0) //backspace
		{
			str[i] = NULL;
			i--;
			gotoxy(x - 1, y);
			printf(" ");
			x = x - 1;
		}
		else if (tmp == 27)
		{
			str[0] = NULL;
		}
	} while (tmp != 13 && tmp != 27);
	str[i] = NULL;
}

void CheckGame(info *LinkRow, int *solved)
{
	*solved = 1;
	for (int i = 0; i < 9; i++)
	{
		ref p = LinkRow[i].head;
		do
		{
			if (!(p->is_stable))
			{
				if (p->key == 0)
				{
					if (*solved == 1)
						*solved = 0;
				}
				else
				{
					if (CheckValue(p, a_row) || CheckValue(p, a_col) || CheckValue(p, a_cell))
					{
						p->is_error = true;
						*solved = -1;
					}
				}
			}
			p = p->next_row;
		} while (p != LinkRow[i].head);
	}
}

void ReturnGame(info *LinkRow)
{
	for (int i = 0; i < 9; i++)
	{
		ref p = LinkRow[i].head;
		do
		{
			if (!(p->is_stable))
			{
				if (p->is_error = true)
				{
					p->is_error = false;
				}
			}
			p = p->next_row;
		} while (p != LinkRow[i].head);
	}
}

ref FindElement(int Row, int Col, info *LinkRow)
{
	ref q = NULL;
	for (int i = 0; i < 9; i++)
	{
		q = LinkRow[i].head;
		do
		{
			if (q->row == Row && q->col == Col)
				goto END;
			q = q->next_row;
		} while (q != LinkRow[i].head);
	}
END:
	return q;
}