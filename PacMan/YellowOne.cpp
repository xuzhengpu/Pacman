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
			//������ں����귽��Ͻ�
			if (DA > 0) {
				//����ҵ��Ҳ෽��Ӧ�������ƶ�
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
				//����ҵ��·���Ӧ�������ƶ�
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


