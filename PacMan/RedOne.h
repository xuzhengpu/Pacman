#pragma once
#include "Enermy.h"
class RedOne :
	public Enermy
{
public:
	RedOne();
	~RedOne();
	void virtual MakeDecision(bool b);
	RedOne(int x, int y) :Enermy(x, y)
	{
		color = RGB(255, 0, 0);
	}

};

