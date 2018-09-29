#include "stdafx.h"
#include "RedOne.h"


RedOne::RedOne()
{
}


RedOne::~RedOne()
{
}

void RedOne::MakeDecision(bool b)
{
	int i = rand();
	if (b)    // 撞到墙壁，改变方向
	{
		if (i % 4 == 0)
		{
			tw == UP ? twCommand = LEFT : twCommand = UP;
		}
		else if (i % 3 == 0)
		{
			tw == DOWN	? twCommand = RIGHT : twCommand = DOWN;
		}
		else if (i % 2 == 0)
		{
			tw == RIGHT ? twCommand = UP : twCommand = RIGHT;

		}
		else
		{
			tw == LEFT ? twCommand = DOWN : twCommand = LEFT;
		}
	}
	if (i % 4 == 0)
	{
		tw != UP ? twCommand = DOWN : twCommand = UP;
	}
	else if (i % 3 == 0)
	{
		tw != DOWN ? twCommand = UP : twCommand = DOWN;
	}
	else if (i % 2 == 0)
	{
		tw != RIGHT ? twCommand = LEFT : twCommand = RIGHT;

	}
	else
	{
		tw != LEFT ? twCommand = RIGHT : twCommand = LEFT;

	}
}


