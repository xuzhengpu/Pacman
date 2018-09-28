#include "stdafx.h"
#include "Enermy.h"


Enermy::Enermy()
{
}


Enermy::~Enermy()
{
}

PacMan *Enermy::player = NULL;
void Enermy::Catch()
{ 
	int DX = point.x - player->GetPos().x;
	int DY = point.y - player->GetPos().y;
	if ((-RD<DX&&DX>RD) && (-RD<DY&&DY>RD))
		player->Over();
									
}

void Enermy::Draw(HDC & hdc)
{
	HPEN pen = ::CreatePen(0, 0, color);
	HPEN oldpen = (HPEN)SelectObject(hdc, pen);
	Arc(hdc, point.x - DISTANCE, point.y + DISTANCE, point.x + DISTANCE, point.y + DISTANCE,
		point.x + DISTANCE, point.y,
		point.x + DISTANCE, point.y
	);
	int const LEGLENTH = (DISTANCE) / (LEGCOUNTS);
	if (frame % 2 == 0)
	{
		MoveToEx(hdc, point.x - DISTANCE, point.y, NULL);
		LineTo(hdc, point.x - DISTANCE, point.y + DISTANCE - LEGLENTH);
		MoveToEx(hdc, point.x + DISTANCE, point.y, NULL);
		LineTo(hdc, point.x + DISTANCE, point.y + DISTANCE - LEGLENTH);
		for (int i = 0; i < LEGCOUNTS; i++)
		{
			Arc(hdc, point.x - DISTANCE + i * 2 * LEGCOUNTS, point.y + DISTANCE - 2 * LEGCOUNTS,
				point.x - DISTANCE + (i + 1) * 2 * LEGCOUNTS, point.y + DISTANCE,
				point.x - DISTANCE + i * 2 * LEGCOUNTS, point.y + DISTANCE - LEGLENTH,
				point.x - DISTANCE + (i + 1) * 2 * LEGCOUNTS, point.y + DISTANCE - LEGLENTH);
		}
	}
	else 
	{
		MoveToEx(hdc, point.x - DISTANCE, point.y,NULL);
		LineTo(hdc, point.x - DISTANCE, point.y + DISTANCE - LEGLENTH);
		MoveToEx(hdc, point.x + DISTANCE, point.y, NULL);
		LineTo(hdc, point.x + DISTANCE, point.y + DISTANCE - LEGLENTH);
		MoveToEx(hdc, point.x - DISTANCE, point.y+DISTANCE,NULL);
		LineTo(hdc, point.x - DISTANCE+LEGLENTH, point.y + DISTANCE - LEGLENTH);
		for (int i = 0; i < LEGCOUNTS - 1; i++)
		{
			Arc(hdc, point.x - DISTANCE + (1 + i * 2) * LEGCOUNTS, point.y + DISTANCE - 2 * LEGCOUNTS,
				point.x - DISTANCE + (3 + i * 2) * LEGCOUNTS, point.y + DISTANCE,
				point.x - DISTANCE + (1 + i * 2) * LEGCOUNTS, point.y + DISTANCE - LEGLENTH,
				point.x - DISTANCE + (3 + i * 2) * LEGCOUNTS, point.y + DISTANCE - LEGLENTH);
		}
		MoveToEx(hdc, point.x + DISTANCE, point.y + DISTANCE,NULL);
		LineTo(hdc, point.x + DISTANCE - LEGLENTH, point.y + DISTANCE - LEGLENTH);
	}
	
	//根据方向绘制眼睛
	int R = DISTANCE / 5;
	switch(tw)
	{
	case UP:
		Ellipse(hdc, point.x - 2 * R, point.y - 2 * R, point.x, point.y);
		Ellipse(hdc, point.x, point.y - 2 * R, point.x + 2 * R, point.y);
		break;
	case DOWN:
		Ellipse(hdc, point.x - 2 * R, point.y, point.x, point.y + 2 * R);
		Ellipse(hdc, point.x, point.y , point.x + 2 * R, point.y + 2 * R);
		break;
	case LEFT:
		Ellipse(hdc, point.x - 3 * R, point.y - R, point.x-R, point.y+R);
		Ellipse(hdc, point.x-R, point.y - R, point.x + R, point.y+R);
		break;
	case RIGHT:
		Ellipse(hdc, point.x - R, point.y - R, point.x + R, point.y + R);
		Ellipse(hdc, point.x + R, point.y - R, point.x + 3*R, point.y + R);
		break;
	}
	frame++;
	SelectObject(hdc, oldpen);
	DeleteObject(pen);
	return;
}

void Enermy::action()
{
	bool b = Collision();  //第一步碰撞检查
	MakeDecision(b);  //第二步智能行动
	Catch();       //第三步抓大嘴
}
