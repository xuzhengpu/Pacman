#pragma once
#include "RedOne.h"
class BlueOne :
	public RedOne
{
public:
	BlueOne();
	~BlueOne();
	void virtual MakeDecision(bool b);
	void Draw(HDC &hdc);
	BlueOne(int x, int y) :RedOne(x, y)
	{
		color = RGB(0, 0, 255);
	}
};

