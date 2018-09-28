#include "stdafx.h"
#include "map.h"


int map::LD = 36;
int map::PD = 3;
map::map()
{
}
map::~map()
{
}
void map::DrawMap(HDC & hdc)
{
	for (int i = 0; i < MAPLENTH; i++)
	{
		for (int j = 0; j < MAPLENTH; j++)
		{
			if (!mapData[i][j])
			{
				RECT rect;
				rect.left = j * LD;
				rect.top = i * LD;
				rect.right = (j + 1)*LD;
				rect.bottom = (i + 1)*LD;
				FillRect(hdc, &rect, CreateSolidBrush(color));

			}
		}
	}
}
void map::DrawPeas(HDC & hdc)
{
	for (int i = 0; i < MAPLENTH; i++)
	{
		for (int j = 0; j < MAPLENTH; j++)
		{
			
			if (peaMapData[i][j])
			{
				Ellipse(hdc, (LD / 2 - PD) + j * LD, (LD / 2 - PD) + i * LD, (LD / 2 + PD) + j * LD, (LD / 2 + PD) + i * LD);

			}
		}
	}
}
void map::initOP()
{
	peaMapData[EARRAY][EROW] = false;

	peaMapData[PARRAY][PROW] = false;
}
stage_1::stage_1()
{
	color = RGB(140, 240, 240);
	for (int i = 0; i < MAPLENTH; i++)
	{
		for (int j = 0; j < MAPLENTH; j++)
		{
			this->mapData[i][j] = initData[i][j];
			this->peaMapData[i][j] = initData[i][j];
		}
	}
	initOP();   // 
}
bool stage_1::initData[MAPLENTH][MAPLENTH] =
{
	B,B,B,B,B,B,B,B,B,A,B,B,B,B,B,B,B,B,B,  //0
	B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,  //1
	B,A,A,B,A,A,B,B,B,A,B,B,B,A,A,B,A,A,B,  //2
	B,A,B,B,A,A,A,A,A,A,A,A,A,A,A,B,A,A,B,  //3
	B,A,B,A,A,A,B,B,B,A,B,B,B,A,A,A,B,A,B,  //4
	B,A,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,A,B,  //5
	B,A,A,A,A,A,B,B,A,A,A,B,B,A,A,A,A,A,B,  //6
	B,A,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,A,B,  //7
	B,A,B,A,A,A,A,A,B,A,B,A,A,A,A,A,B,A,B,  //8
	A,A,A,A,A,A,A,A,B,B,B,A,A,A,A,A,A,A,A,  //9
	B,A,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,A,B,  //10
	B,A,B,A,A,B,A,A,A,A,A,A,A,A,B,A,B,A,B,  //11
	B,A,B,A,B,B,B,A,A,A,A,A,B,B,B,A,B,A,B,  //12
	B,A,A,A,A,B,A,A,A,A,A,A,A,B,A,A,A,A,B,  //13
	B,A,B,B,A,A,A,A,A,A,A,A,A,A,A,B,B,A,B,  //14
	B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,  //15
	B,A,A,A,A,B,B,B,A,B,A,B,B,B,A,A,A,A,B,  //16
	B,A,A,A,A,B,A,A,A,A,A,A,A,B,A,A,A,A,B,  //17
	B,B,B,B,B,B,B,B,B,A,B,B,B,B,B,B,B,B,B,  //18
};