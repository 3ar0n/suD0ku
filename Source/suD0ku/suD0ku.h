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
constexpr auto Up = 22472;
constexpr auto Left = 22475;
constexpr auto Right = 22477;
constexpr auto Down = 22480;
constexpr auto Enter = 13;
constexpr auto Esc = 27;
constexpr auto New = 78;
constexpr auto Hint = 72;
constexpr auto Clear = 67;
constexpr auto Erase = 69;
constexpr auto Check = 75;
constexpr auto Mute = 77;

//mode
constexpr auto a_row = 1001;
constexpr auto a_col = 1002;
constexpr auto a_cell = 1003;

//color
constexpr auto Black = 0;
constexpr auto Blue_D = 1;
constexpr auto Green_D = 2;
constexpr auto Cyan_D = 3;
constexpr auto Red_D = 4;
constexpr auto Pink_D = 5;
constexpr auto Yellow_D = 6;
constexpr auto White_D = 7;
constexpr auto Grey = 8;
constexpr auto Blue = 9;
constexpr auto Green = 10;
constexpr auto Cyan = 11;
constexpr auto Red = 12;
constexpr auto Pink = 13;
constexpr auto Yellow = 14;
constexpr auto White = 15;

//Main.cpp
void ClearMenu(opt head);

//SetupConsole.cpp
int Read_Key();
void gotoxy(SHORT x, SHORT y);
void SetColor(int Text = White, int Background = Black);
void SetWindowsSize(SHORT x = 80, SHORT y = 25);

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