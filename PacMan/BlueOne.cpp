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
		// �������ͬһ��������
		if (DA > 0&&DR<=BLUE)
		{
			//��������
			twCommand = LEFT;
			return;
		}
		if (DA < 0 && DA <= BLUE)
		{
			//���Ҳ�
			twCommand = RIGHT;
			return;
		}

	}
	if (!b&&DA == 0)
	{
		// �������ͬһ��������
		if (DR > 0 && DR <= BLUE)
		{
			//������ϲ�
			twCommand = UP;
			return;
		}
		if (DR < 0 && DR <= BLUE)
		{
			//���²�
			twCommand = DOWN;
			return;
		}
		
	}
	RedOne::MakeDecision(b);
}
