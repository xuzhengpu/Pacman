#include "stdafx.h"
#include "YellowOne.h"


YellowOne::YellowOne()
{
}


YellowOne::~YellowOne()
{
}

void YellowOne::MakeDecision(bool b)
{
	int const DR = drow - player->GetRow();
	int const DA = darray - player->GetArray();
	if (!b)
	{
		if (DR*DR>DA*DA)
		{
			//与玩家在横坐标方向较近
			if (DA > 0) {
				//在玩家的右侧方，应该向左移动
				twCommand = LEFT;
				return;
			}
			else if(DA<0)
			{
				twCommand = RIGHT;
				return;
			}
		
		}
		else  
		{
			if (DR > 0) {
				//在玩家的下方，应该向上移动
				twCommand =UP;
				return;
			}
			else if (DR < 0)
			{
				twCommand = DOWN;
				return;
			}
		}

	}

	RedOne::MakeDecision(b);
}


