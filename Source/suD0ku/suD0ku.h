#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

typedef struct sudoku * ref;
struct sudoku
{
	int row;
	int col;
	int key;
	bool is_stable;
	bool is_error;
	ref next_row;
	ref next_col;
	ref next_cell;
};

struct info
{
	ref head;
};

typedef struct menu * opt;
struct menu
{
	int value;
	char text[255];
	opt next;
	opt prev;
};

//key
#define Up 22472
#define Left 22475
#define Right 22477
#define Down 22480
#define Enter 13
#define Esc 27
#define New 78
#define Hint 72
#define Clear 67
#define Erase 69
#define Check 75
#define Mute 77

//mode
#define a_row 1001
#define a_col 1002
#define a_cell 1003

//color
#define Black 0
#define Blue_D 1
#define Green_D 2
#define Cyan_D 3
#define Red_D 4
#define Pink_D 5
#define Yellow_D 6
#define White_D 7
#define Grey 8
#define Blue 9
#define Green 10
#define Cyan 11
#define Red 12
#define Pink 13
#define Yellow 14
#define White 15

//Main.cpp
void ClearMenu(opt head);

//SetupConsole.cpp
int Read_Key();
void gotoxy(int x, int y);
void SetColor(int Text = White, int Background = Black);
void SetWindowsSize(int x = 80, int y = 25);

//Graphic.cpp
void putLogo(int x, int y, int Color, int Color_Shad);
void putFrame(int x = 0, int y = 0, int color = Cyan, int zoom = 2);
void putPointer(int x = 0, int y = 0, bool Visible = true);
void putNumber(int key, int Color, int x = 0, int y = 0);
void PrintSudoku(info *LinkRow, int x = 0, int y = 0, bool is_full = true, bool error = false);
void PrintCenter(info *LinkRow, int x, int y);
void putPopup(int x, int y, int width, int height, char *str0 = NULL);
void ButtonFunction(int Border, int Highlight, int FontColor);
void putFuntion(int key, int x, int y, int FrameColor, int FontColor_1, int FontColor_2);
void Raven(int x, int y);
void Owl(int x, int y);
void FlappyBird(int x, int y);
void putWinner(int x, int y);

//Database
ref CreateNode(int row, int col);
void AddNode(ref *head, ref p, int mode);
ref BeforeNode(ref p, int mode);
void CreateTable(info **LinkRow, info **LinkCol, info **LinkCell);
void ClearTable(info *LinkRow);
int Pointer(info *LinkRow, ref *p, int x = 0, int y = 0, bool Solve = true);
bool CheckValue(ref p, int mode);
void SolveSudoku(info *LinkRow, bool *check, ref p = NULL);
void SetRandomValue(info *LinkRow, int difficulty = 2);
void CopyData(info *RowSource, info *RowDest, bool is_full = false);
void enterCode(int x, int y, char *str);
void CheckGame(info *LinkRow, int *solved);
void ReturnGame(info *LinkRow);
ref FindElement(int Row, int Col, info *LinkRow);

//StartScreen.cpp
void LoadingScreen(int x, int y);
void LoadingBar(int x, int y, int size, int Color);
void CreateMenu(opt *head);
int Select(opt head, int x, int y, bool saved = false);
void putBorder(int color, int x, int y, int width = 21);
void ExitOpt(opt *head);
int Exit(opt head, int x, int y);

//NewGame.cpp
void DifficultLevel(opt *head);
int SelectLevel(opt head, int x, int y);
void NewGame(int difficulty = 2);

//HowToPlay.cpp
void RuleOpt(opt *head);
void SelectRule(opt head, int x, int y);
void PrintSudoku_v2(info *LinkRow, int x, int y);
void SetRandomMode(info **LinkRow, info **LinkCol, info **LinkCell, int mode);
void HowToPlay();

//SaveGame.cpp
void SaveOpt(opt *head);
int Save(opt head, int x, int y);

//File.cpp
void readFile(char *input, info **LinkRow, info **LinkCol, info **LinkCell, int *difficulty, int *hint);
void writeFile(char* output, info *LinkRow, int difficulty, int hint);

//About.cpp
void About();

//Continue.cpp
void CoutinueGame();

//Relax.cpp
void putShape(int posX, int posY, int edge, bool Visible, int Color = 15);
void putShapeBorder(int posX, int posY, int sizeX, int sizeY);
void Moving_Square(int sizeX, int sizeY);