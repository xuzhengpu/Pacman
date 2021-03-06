#pragma once
#include "object.h"
#include "resource.h"

class PacMan :public object
{
public:
	void  virtual AchiveCtrl();  //重新定义虚函数 用于更新物体到达块中心时的豆子坐标
	POINT GetPos();
	bool win();
	void Draw(HDC &hdc);
	void SetTwcommand(TWARDS command);
	void Over();
	PacMan(int x, int y) :object(x, y)
	{
		this->speed = PLAYERSPEED;
		twCommand = tw = LEFT;
	}
	void action();
	TWARDS GetTw();
 };
