#pragma once
#include "object.h"
#include "PacMan.h"
class Enermy :
	public object
{
protected :
      void Catch();     // 是否抓住大嘴
public:
	Enermy();
	~Enermy();
	static PacMan* player;
	void virtual MakeDecision(bool b)=0;  //AI 实现
	COLORREF color;
	void virtual Draw(HDC &hdc);
	Enermy(int x, int y) :object(x, y)
	{
		speed = ENERMYSPEED;
		tw = LEFT;
		twCommand = UP;
	}
	void action();  //敌人的活动模式可以分为三步
};

