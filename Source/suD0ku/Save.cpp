#include "suD0ku.h"

void SaveOpt(opt *head)
{
	opt s1 = (opt)malloc(sizeof(menu));
	s1->value = 10;
	strcpy_s(s1->text, " Y E S ");

	opt s2 = (opt)malloc(sizeof(menu));
	s2->value = 20;
	strcpy_s(s2->text, "  N O  ");

	opt s3 = (opt)malloc(sizeof(menu));
	s3->value = 30;
	strcpy_s(s3->text, "B A C K");


	*head = s1;
	s1->prev = NULL;
	s2->prev = s1;
	s3->prev = s2;
	s1->next = s2;
	s2->next = s3;
	s3->next = NULL;
}

int Save(opt head, int x, int y)
{
	int Key;
	int d = 10;
	opt p = head;

	y = y + 1;
	gotoxy(x, y);
	SetColor(Cyan);
	printf("%s", p->text);
	//putBorder(Cyan, x + 1, y, 3);

	gotoxy(x + d, y);
	SetColor(White_D);
	printf("%s", p->next->text);
	//putBorder(Cyan_D, x + d + 1, y, 3);

	gotoxy(x + 2*d, y);
	SetColor(White_D);
	printf("%s", p->next->next->text);
	//putBorder(Cyan_D, x + d + d + 1, y, 3);

	gotoxy(0, 0);
	do
	{
		Key = Read_Key();
		if (Key == Left || Key == Right)
		{
			if (Key == Left && p->prev)
			{
				gotoxy(x, y);
				SetColor(White_D);
				printf("%s", p->text);
				//putBorder(Cyan_D, x + 1, y, 3);

				p = p->prev;
				x = x - d;

				gotoxy(x, y);
				SetColor(Cyan);
				printf("%s", p->text);
				//putBorder(Cyan, x + 1, y, 3);
			}
			if (Key == Right && p->next)
			{
				gotoxy(x, y);
				SetColor(White_D);
				printf("%s", p->text);
				//putBorder(Cyan_D, x + 1, y, 3);

				p = p->next;
				x = x + d;

				gotoxy(x, y);
				SetColor(Cyan);
				printf("%s", p->text);
				//putBorder(Cyan, x + 1, y, 3);
			}
		}
		gotoxy(0, 0);
	} while (Key != Enter);
	SetColor();
	return p->value;
}