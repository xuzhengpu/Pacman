#include "stdafx.h"
#include "BlueOne.h"


BlueOne::BlueOne()
{
}


BlueOne::~BlueOne()
{
}

void BlueOne::MakeDecision(bool b)
{
	int const DR = drow - player->GetRow();
	int const DA = darray - player->GetArray();
	if (!b&&DR == 0)
	{
		// 与玩家在同一横坐标上
		if (DA > 0&&DR<=BLUE)
		{
			//玩家在左侧
			twCommand = LEFT;
			return;
		}
		if (DA < 0 && DA <= BLUE)
		{
			//在右侧
			twCommand = RIGHT;
			return;
		}

	}
	if (!b&&DA == 0)
	{
		// 与玩家在同一纵坐标上
		if (DR > 0 && DR <= BLUE)
		{
			//玩家在上侧
			twCommand = UP;
			return;
		}
		if (DR < 0 && DR <= BLUE)
		{
			//在下侧
			twCommand = DOWN;
			return;
		}
		
	}
	RedOne::MakeDecision(b);
}
