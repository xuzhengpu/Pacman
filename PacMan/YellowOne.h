#pragma once
#include "RedOne.h"
class YellowOne :
	public RedOne
{
public:
	YellowOne();
	~YellowOne();
	void virtual MakeDecision(bool b);
	void Draw(HDC &hdc);
	YellowOne(int x, int y) :RedOne(x, y)
	{
		color = RGB(200,200, 100);
	}
};

