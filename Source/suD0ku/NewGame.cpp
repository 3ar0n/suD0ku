﻿#include "suD0ku.h"

void DifficultLevel(opt *head)
{
	opt l1 = (opt)malloc(sizeof(menu));
	l1->value = 1;
	strcpy_s(l1->text, "       E A S Y       ");

	opt l2 = (opt)malloc(sizeof(menu));
	l2->value = 2;
	strcpy_s(l2->text, "     N O R M A L     ");

	opt l3 = (opt)malloc(sizeof(menu));
	l3->value = 3;
	strcpy_s(l3->text, "       H A R D       ");


	*head = l1;
	l1->prev = NULL;
	l2->prev = l1;
	l3->prev = l2;
	l1->next = l2;
	l2->next = l3;
	l3->next = NULL;
}

int SelectLevel(opt head, int x, int y)
{
	int Key;
	//int d = 21;
	opt p = head;

	SetColor(Cyan);
	gotoxy(x, y);
	printf("%s", p->text);
	putBorder(Cyan, x, y, 21);

	SetColor(Cyan_D);
	gotoxy(x, y + 3);
	printf("%s", p->next->text);
	putBorder(Cyan_D, x, y + 3, 21);

	SetColor(Cyan_D);
	gotoxy(x, y + 6);
	printf("%s", p->next->next->text);
	putBorder(Cyan_D, x, y + 6, 21);

	gotoxy(0, 0);

	do
	{
		fflush(stdin);
		Key = Read_Key();
		if (Key == Up || Key == Down)
		{
			if (Key == Up && p->prev)
			{
				gotoxy(x, y);
				SetColor(Cyan_D);
				printf("%s", p->text);
				putBorder(Cyan_D, x, y, 21);

				y = y - 3;
				p = p->prev;

				gotoxy(x, y);
				SetColor(Cyan);
				printf("%s", p->text);
				putBorder(Cyan, x, y, 21);


			}
			if (Key == Down && p->next)
			{
				gotoxy(x, y);
				SetColor(Cyan_D);
				printf("%s", p->text);
				putBorder(Cyan_D, x, y, 21);

				y = y + 3;
				p = p->next;

				gotoxy(x, y);
				SetColor(Cyan);
				printf("%s", p->text);
				putBorder(Cyan, x, y, 21);
			}
		}
		gotoxy(0, 0);
	} while (Key != Enter && Key != Esc);
	SetColor(White);
	if (Key == Enter)
		return p->value;
	else
		return 0;
}

void NewGame(int difficulty)
{
	int x = 9, y = 1; //Tọa độ gốc
	putFrame(x, y); //Vẽ lưới sudoku
	ButtonFunction(Cyan, Cyan, Yellow);
	
	info *ROW, *COL, *CELL;
	info *tmpROW, *tmpCOL, *tmpCELL;
	bool check = true;
	int Key;
	char code[256];
	ref p, q;
	int count_Hint = 3;
	do
	{
		if (count_Hint > 0)
			SetColor(Cyan);
		else
			SetColor(White_D);
		gotoxy(77, 43); printf("%d", count_Hint);

		CreateTable(&ROW, &COL, &CELL);
		SetRandomValue(ROW, difficulty);
		CreateTable(&tmpROW, &tmpCOL, &tmpCELL);
		CopyData(ROW, tmpROW);
		PrintSudoku(ROW, x, y);
		
		p = ROW[0].head;

		bool isNew = true;
		int solved;
	LOOP_1:
		Key = Pointer(ROW, &p, x, y, false);
		goto LOOP_2;

	LOOP_End:
		do
		{
			Key = Read_Key();
			if (Key != Esc)
			{
				putPopup(x, y, 35, 7, "Press 'ESC' key");
				gotoxy(33, 20);
				SetColor(White_D);
				printf("to get back to main menu!");
				SetColor();
				//printf("");
				gotoxy(0, 0);
			}
		} while (Key != Esc);
		goto LOOP_3;

	LOOP_Fin:
		do
		{
			Key = Read_Key();
		} while (Key != Enter);
		Key = Esc;
		goto LOOP_3;

	LOOP_2:
		if (Key != Esc)
		{
			switch (Key)
			{
				case Erase:
					CopyData(tmpROW, ROW);
					PrintSudoku(ROW, x, y);
					goto LOOP_1;
					break;
				case Check:
					CheckGame(ROW, &solved);
					if (solved != 1)
					{
						PrintSudoku(ROW, x, y, false);
						if (solved == - 1)
							Sleep(1000);
						ReturnGame(ROW);
						PrintSudoku(ROW, x, y, false);
						goto LOOP_1;
					}
					else
					{
					LOOP_Win:
						putWinner(x, y);
						//isNew = false;
						goto LOOP_Fin;
					}
					break;
				case Hint:
					if (count_Hint > 0)
					{
						if (p->is_stable == false)
						{
							q = tmpROW[0].head;
							while (q->is_stable == true)
							{
								if (q->next_row != tmpROW[q->row].head)
									q = q->next_row;
								else
									q = tmpROW[q->row + 1].head;
							}
							// giải lưới sudoku tạm 
							SolveSudoku(tmpROW, &check, q);
							q = FindElement(p->row, p->col, tmpROW);
							p->key = q->key;
							//p->is_stable = true;
							CopyData(ROW, tmpROW);
							PrintSudoku(ROW, x, y, false);
							count_Hint--;
							if (count_Hint > 0)
								SetColor(Cyan);
							else
								SetColor(White_D);
							gotoxy(77, 43); printf("%d", count_Hint);
							SetColor();
						}
					}
					goto LOOP_1;
					break;
				case New:
					count_Hint = 3;
					isNew = true;
					break;
				case Enter:
					if (isNew)
					{
						putPopup(x, y, 35, 7, "Enter code:");
						putBorder(7, x + 29, y + 19, 15);
						enterCode(x + 27, y + 19, code);
						PrintCenter(ROW, x, y);
						if (code && strcmp(code, "Never Give Up") == 0)
						{
							code[0] = NULL;
							//xác định vị trí đầu tiên "còn trống"
							q = tmpROW[0].head;
							while (q->is_stable == true)
							{
								if (q->next_row != tmpROW[q->row].head)
									q = q->next_row;
								else
									q = tmpROW[q->row + 1].head;
							}
	
							//giải và in lưới sudoku
							SolveSudoku(tmpROW, &check, q);
							CopyData(tmpROW, ROW, true);
							PrintSudoku(ROW, x, y, false);
							gotoxy(0, 0);
							isNew = false;
							goto LOOP_End;
						}
						else if (code && strcmp(code, "mjolnir") == 0)
						{
							Moving_Square(44, 18);
							Key = Esc;
							goto LOOP_3;
						}
						else if (code && strcmp(code, "selfie") == 0)
						{
							goto LOOP_Win;
						}
					}
					goto LOOP_1;
					break;
				default:
					if (!check)
					{
						PrintCenter(ROW, x, y);
						check = true;
					}
					isNew = true;
					Key = Read_Key();
					goto LOOP_2;
			}
		}
		else
		{
			putPopup(x, y, 35, 7, " Do you want to save and quit?");
			//putBorder(7, x + 29, y + 19, 15);
			//gotoxy(x + 27, y + 19);

			opt headSave;
			SaveOpt(&headSave);
			int save = Save(headSave, 32, 19);
			switch (save)
			{
				case 10: //Thoát có lưu
					writeFile("sud0ku.save", ROW, difficulty, count_Hint);
					break;
				case 20: //Thoát không lưu
					break;
				case 30: //Không thoát
					PrintCenter(ROW, x, y);
					goto LOOP_1;
					break;
			}
			ClearMenu(headSave);
		}

	LOOP_3: //Xóa dữ liệu và thoát ra main menu
		ClearTable(ROW);
		free(ROW);
		free(COL);
		free(CELL);
		ClearTable(tmpROW);
		free(tmpROW);
		free(tmpCOL);
		free(tmpCELL);
	} while (Key != Esc);
}
