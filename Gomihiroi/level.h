#pragma once

#define NEXT_IMAGE_SIZE_X 128
#define NEXT_IMAGE_SIZE_Y 128

enum Level
{
	LEVEL_DUST,		//初期値 埃がクリックできる
	LEVEL_BANANA,	//埃とバナナの皮がクリックできる
	LEVEL_BOOK,		//埃から雑誌までクリックできる
	LEVEL_TRASH,	//埃からゴミ袋までクリックできる
	LEVEL_FRIDGE,	//埃から冷蔵庫までクリックできる
};

void InitLevel(void);
void UninitLevel(void);
void UpdateLevel(int addLevel);
void DrawLevel(void);
void ChangeLevel(int setlevel);
int GetLevel();