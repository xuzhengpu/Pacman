#pragma once
#define PLAYERSPEED 6
#define ENERMYSPEED 4
#define LEGCOUNTS 5
#define DISTANCE 10
#define BLUE 8
#define OFFSET 2
#define RD 12	
#include <time.h>
#include "map.h"
; enum TWARDS {
	UP,DOWN ,LEFT,RIGHT,OVER
};

class object
{
public:
	object();
	~object();
	object(int row, int array);
	void virtual action() = 0;   //�������Ϊ�����麯��
	void virtual Draw(HDC &hdc)=0;//���ƶ��󣬴��麯�������ݾ���������¶���
	bool Collision(); //�߼���ײ��� ��������ڷŵ������λ��
	bool Achive();        // �ж������Ƿ񵽴��߼�����λ��
	void virtual AchiveCtrl();  //�����߼�����������
	int PtTransform(int n); //��ʵ������ת�����߼�����
	int GetRow();
	int GetArray();
	void DrawBlank(HDC & hdc);
	void SetPosition(int row, int array);
	map  static *pstage;   //ָ���ͼ��ָ��
protected:
	TWARDS tw;    //ö������ ����ĳ���
	POINT point;   //��������
	int drow;
	int darray;
	int speed;
	TWARDS twCommand;
	int frame; //֡��
	int mX;
	int mY;
};
