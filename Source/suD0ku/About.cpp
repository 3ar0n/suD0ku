#include "suD0ku.h"


struct A_bout
{
	char str[100];
};

void About()
{
	putLogo(13, 1, White, Cyan);
	A_bout List[38];

	strcpy_s(List[0].str,  "by R4ven Team                                       version 1.2.1");
	strcpy_s(List[1].str,  "                               H I S T O R Y                               ");
	strcpy_s(List[2].str,  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	strcpy_s(List[3].str,  "   ");
	strcpy_s(List[4].str,  "  Sudoku is a logic-based,combinatorial number-placement puzzle.");
	strcpy_s(List[5].str,  "The objective is to fill a 9x9 grid with digits so that each column,");
	strcpy_s(List[6].str,  "each row, and each of the nine 3x3 sub-grids that compose the grid");
	strcpy_s(List[7].str,  "(also called 'boxes', 'blocks', 'regions', or 'sub - squares') contain");
	strcpy_s(List[8].str,  "all of the digits from 1 to 9. The puzzle setter provides a partially");
	strcpy_s(List[9].str,  "completed grid, which for a well-posed puzzle has a unique solution.");
	strcpy_s(List[10].str, "   ");
	strcpy_s(List[11].str, "  Completed puzzles are always a type of Latin square with an additional");
	strcpy_s(List[12].str, "constraint on the contents of individual regions. For example, the same");
	strcpy_s(List[13].str, "single integer may not appear twice in the same row, column or in any of");
	strcpy_s(List[14].str, "the nine 3x3 subregions of the 9x9 playing board.");
	strcpy_s(List[15].str, "   ");
	strcpy_s(List[16].str, "  French newspapers featured variations of the puzzles in the 19th century,");
	strcpy_s(List[17].str, "and the puzzle has appeared since 1979 in puzzle books under the name");
	strcpy_s(List[18].str, "Number Place. However, the modern Sudoku only started to become mainstream");
	strcpy_s(List[19].str, "in 1986 by the Japanese puzzle company Nikoli, under the name Sudoku,");
	strcpy_s(List[20].str, "meaning single number. It first appeared in a US newspaper and then");
	strcpy_s(List[21].str, "The Times (UK) in 2004, from the efforts of Wayne Gould, who devised");
	strcpy_s(List[22].str, "a computer program to rapidly produce distinct puzzles.");
	strcpy_s(List[23].str, "   ");
	strcpy_s(List[24].str, "   ");
	strcpy_s(List[25].str, "                    D E V E L O P M E N T     T E A M                     ");
	strcpy_s(List[26].str, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	strcpy_s(List[27].str, "   ");
	strcpy_s(List[28].str, "                        DANG QUOC THAI aka 3ar0n            ");
	strcpy_s(List[29].str, "   ");
	strcpy_s(List[30].str, "                       NGUYEN TRI THAM aka SASORI           ");
	strcpy_s(List[31].str, "   ");
	strcpy_s(List[32].str, "                      TRAN THANH THIEN aka KUROSAGI         ");

	gotoxy(13, 7);
	printf("%s", List[0].str);
	for (int i = 1; i <= 32; i++)
	{
		gotoxy(8, 10 + i);
		if (i == 1 || i == 25)
			SetColor(Green);
		else if (i == 2 || i == 26)
			SetColor(Yellow);
		else
			SetColor();
		if (i != 1 && i != 2 && i != 25 && i != 26)
		{
			for (unsigned int j = 0; j < strlen(List[i].str); j++)
			{
				printf("%c", List[i].str[j]);
				Sleep(1);
			}
		}
		else
		{
			printf("%s", List[i].str);
			Sleep(10);
		}
	}
	gotoxy(0, 0);

	int key;
	do
	{
		key = Read_Key();
	} while (key != Esc);
	system("cls");
}