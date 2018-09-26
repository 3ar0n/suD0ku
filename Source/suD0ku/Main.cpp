#include "suD0ku.h"

void ClearMenu(opt head)
{
	opt p, q = head;
	while (q->next != NULL)
	{
		p = q;
		q = q->next;
		free(p);
	}
}

int main()
{
	SetWindowsSize(91, 46);
	srand((unsigned)time(NULL));
	LoadingScreen(4, 10);
	bool saved;
	FILE *f;

	opt headMenu;
	CreateMenu(&headMenu);
	int choose, level;

	//Phần chính
	do
	{
		system("cls");
		putLogo(13, 11, White, Cyan);

		errno_t err = fopen_s(&f, "sud0ku.save", "rt");
		if (f)
		{
			saved = true;
			fclose(f);
		}
		else
			saved = false;

		choose = Select(headMenu, 35, 28, saved);
		switch (choose)
		{
		case 1: //Màn chơi mới
			system("cls");
			putLogo(13, 11, White, Cyan);
			opt headLevel;
			DifficultLevel(&headLevel);
			level = SelectLevel(headLevel, 35, 30);
			ClearMenu(headLevel);
			if (level)
				NewGame(level);
			break;
		case 2: //Chơi lại game đã lưu
			system("cls");
			CoutinueGame();
			break;
		case 3: //Hướng dẫn chơi
			system("cls");
			HowToPlay();
			break;
		case 4: //Thông tin về trò chơi, tác giả
			system("cls");
			About();
			break;
		case 5: //Thoát game
			opt headExit;
			system("cls");
			FlappyBird(28, 22);
			ExitOpt(&headExit);
			gotoxy(33, 13);
			SetColor(11);
			printf("A R E   Y O U   S U R E ?");
			choose = Exit(headExit, 53, 16);
			ClearMenu(headExit);
			break;
		}
	} while (choose != 5); //tương ứng với lựa chọn "exit" -> "yes"
	ClearMenu(headMenu);
	if (saved)
		remove("sud0ku.save");
	SetColor(15);
	return 0;
	/* Cheat code:
		Never Give Up
		mjolnir
		selfie
	*/
}