#pragma once
#include "object.h"
#include "PacMan.h"
class Enermy :
	public object
{
protected :
      void Catch();     // �Ƿ�ץס����
public:
	Enermy();
	~Enermy();
	static PacMan* player;
	void virtual MakeDecision(bool b)=0;  //AI ʵ��
	COLORREF color;
	void virtual Draw(HDC &hdc);
	Enermy(int x, int y) :object(x, y)
	{
		speed = ENERMYSPEED;
		tw = LEFT;
		twCommand = UP;
	}
	void action();  //���˵Ļģʽ���Է�Ϊ����
};

