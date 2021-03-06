#include "stdafx.h"
#include "object.h"

map* object::pstage = NULL;
object::object()
{
}


object::~object()
{
}

bool object::Achive()
{
	int n = (point.x - pstage->LD / 2) % pstage->LD;
	int m = (point.y - pstage->LD / 2) % pstage->LD;
	if (n == 0 && m == 0)
		return 1;
	else
		return 0;
}
int object::PtTransform(int n)
{
	return (n - (pstage->LD / 2)) / pstage->LD;
}
void object::AchiveCtrl()
{
	if (Achive())   //如果物体移动到地图块中心位置，从新计算更新物体的逻辑坐标
	{
		drow = PtTransform(point.y);
	    darray = PtTransform(point.x);
	}

}
bool object::Collision()   //判断是否撞墙， 撞墙返回1，不撞墙返回0
{
	bool flag = false;   //返回值  默认为0 （不撞墙）
	AchiveCtrl();//更新行列
	if (drow<0 || darray<0 || drow>MAPLENTH || darray>MAPLENTH)    // 
	{
		flag = false; // 指令失效
	}
	else if (Achive())
	{
		switch (twCommand)
		{
		case LEFT:
			if (darray > 0 && !pstage->mapData[drow][darray - 1]) //判断下一个格子是否通行
			{
				flag = true;   //撞墙
			}
			break;

		case RIGHT:
			if (darray < MAPLENTH - 1 && !pstage->mapData[drow][darray + 1])
			{
				flag = true;   //撞墙
			}
			break;
		case UP:
			if (drow > 0 && !pstage->mapData[drow - 1][darray])
			{
				flag = true;   //撞墙
			}
			break;
		case DOWN:
			if (drow < MAPLENTH - 1 && !pstage->mapData[drow + 1][darray])
			{
				flag = true;   //撞墙
			}
			break;
		}
		if (flag == false)  //没撞墙则把指令给tw
		{
			tw = twCommand;
		}
	}
	mX = point.x;
	mY = point.y;
	int MAX = pstage->LD*MAPLENTH + pstage->LD / 2;
	int MIN = pstage->LD / 2;
	switch (tw)
	{
	case LEFT:
		if (darray > 0 && !pstage->mapData[drow][darray - 1]) //判断下一个格子是否通行
		{
			flag = false;
			break;
		}
		if (point.x < MIN)
			point.x = MAX;
		point.x -= speed;
		break;
	case RIGHT:
		if (darray < MAPLENTH - 1 && !pstage->mapData[drow][darray + 1])
		{
			flag = false;
			break;
		}
		point.x += speed;
		if (point.x >MAX)
			point.x = MIN;
		break;
	case UP:
		if (drow > 0 && !pstage->mapData[drow - 1][darray])
		{
			flag = false;
			break;
		}
		if (point.y < MIN)
			point.y = MAX;
		point.y -= speed;
		break;
	case DOWN:
		if (drow < MAPLENTH - 1 && !pstage->mapData[drow + 1][darray])
		{
			flag = false;
			break;
		}
		point.y += speed;
		if (point.y > MAX)
			point.y = MIN;
		break;
	}
	return flag;
}
object::object(int row, int array)
{
	frame = 1;
	pstage = NULL;
	drow = row;
	darray = array;
	point.y = drow * pstage->LD + pstage->LD / 2;
	point.x = darray * pstage->LD + pstage->LD / 2;
	mX = point.x;
	mY = point.y;
}
int object::GetRow()
{
	return drow;
}
int object::GetArray()
{
	return darray;
}
void object::DrawBlank(HDC & hdc)
{
	RECT rect;
	rect.top = mY - RD;
	rect.left = mX - RD;
	rect.right = mX + RD;
	rect.bottom = mY + RD;
	FillRect(hdc, &rect, ::CreateSolidBrush(RGB(255, 255, 255)));
}
void object::SetPosition(int row, int array)
{
	drow = row;
	darray = array;
	point.y = drow * pstage->LD + pstage->LD / 2;
	point.x = darray * pstage->LD + pstage->LD / 2;
}
