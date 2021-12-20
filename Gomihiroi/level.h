#pragma once

#define NEXT_IMAGE_SIZE_X 128
#define NEXT_IMAGE_SIZE_Y 128

enum Level
{
	LEVEL_DUST,		//�����l �����N���b�N�ł���
	LEVEL_BANANA,	//���ƃo�i�i�̔炪�N���b�N�ł���
	LEVEL_BOOK,		//������G���܂ŃN���b�N�ł���
	LEVEL_TRASH,	//������S�~�܂܂ŃN���b�N�ł���
	LEVEL_FRIDGE,	//������①�ɂ܂ŃN���b�N�ł���
};

void InitLevel(void);
void UninitLevel(void);
void UpdateLevel(int addLevel);
void DrawLevel(void);
void ChangeLevel(int setlevel);
int GetLevel();