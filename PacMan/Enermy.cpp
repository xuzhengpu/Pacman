#include "stdafx.h"
#include "Enermy.h"


Enermy::Enermy()
{
}


Enermy::~Enermy()
{
}

PacMan *Enermy::player = NULL;
void Enermy::Catch()
{ 

}
void Enermy::MakeDecision(bool b)
{
}

void Enermy::Draw(HDC & hdc)
{
}

void Enermy::action()
{
	bool b = Collision();  //��һ����ײ���
	MakeDecision(b);  //�ڶ��������ж�
	Catch();       //������ץ����
}
