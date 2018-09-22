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
	bool b = Collision();  //第一步碰撞检查
	MakeDecision(b);  //第二步智能行动
	Catch();       //第三步抓大嘴
}
