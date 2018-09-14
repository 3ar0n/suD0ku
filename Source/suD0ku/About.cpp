#include "suD0ku.h"


struct A_bout
{
	char str[100];
};

void About()
{
	putLogo(13, 1, White, Cyan);
	A_bout List[38];

	strcpy(List[0].str,  "by R4ven Team                                       version 1.2.0");
	strcpy(List[1].str,  "                               H I S T O R Y                               ");
	strcpy(List[2].str,  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	strcpy(List[3].str,  "   ");
	strcpy(List[4].str,  "  Sudoku is a logic-based,combinatorial number-placement puzzle.");
	strcpy(List[5].str,  "The objective is to fill a 9x9 grid with digits so that each column,");
	strcpy(List[6].str,  "each row, and each of the nine 3x3 sub-grids that compose the grid");
	strcpy(List[7].str,  "(also called 'boxes', 'blocks', 'regions', or 'sub - squares') contain");
	strcpy(List[8].str,  "all of the digits from 1 to 9. The puzzle setter provides a partially");
	strcpy(List[9].str,  "completed grid, which for a well-posed puzzle has a unique solution.");
	strcpy(List[10].str, "   ");
	strcpy(List[11].str, "  Completed puzzles are always a type of Latin square with an additional");
	strcpy(List[12].str, "constraint on the contents of individual regions. For example, the same");
	strcpy(List[13].str, "single integer may not appear twice in the same row, column or in any of");
	strcpy(List[14].str, "the nine 3x3 subregions of the 9x9 playing board.");
	strcpy(List[15].str, "   ");
	strcpy(List[16].str, "  French newspapers featured variations of the puzzles in the 19th century,");
	strcpy(List[17].str, "and the puzzle has appeared since 1979 in puzzle books under the name");
	strcpy(List[18].str, "Number Place. However, the modern Sudoku only started to become mainstream");
	strcpy(List[19].str, "in 1986 by the Japanese puzzle company Nikoli, under the name Sudoku,");
	strcpy(List[20].str, "meaning single number. It first appeared in a US newspaper and then");
	strcpy(List[21].str, "The Times (UK) in 2004, from the efforts of Wayne Gould, who devised");
	strcpy(List[22].str, "a computer program to rapidly produce distinct puzzles.");
	strcpy(List[23].str, "   ");
	strcpy(List[24].str, "   ");
	strcpy(List[25].str, "                    D E V E L O P M E N T     T E A M                     ");
	strcpy(List[26].str, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	strcpy(List[27].str, "   ");
	strcpy(List[28].str, "                        DANG QUOC THAI the 3ar0n            ");
	strcpy(List[29].str, "   ");
	strcpy(List[30].str, "                       NGUYEN TRI THAM the SASORI           ");
	strcpy(List[31].str, "   ");
	strcpy(List[32].str, "                      TRAN THANH THIEN the KUROSAGI         ");

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
			for (int j = 0; j < strlen(List[i].str); j++)
			{
				printf("%c", List[i].str[j]);
				Sleep(4);
			}
		}
		else
		{
			printf("%s", List[i].str);
			Sleep(50);
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