#pragma once
#define MAPLENTH 19
#include "stdafx.h"
#include <list>
#define A true
#define B false
#define EARRAY 9   //��ʼ���з���λ��
#define EROW 8
#define PARRAY 9   //��ʼ�ҷ�λ��
#define PROW 10

class map
{
public:
	map();
	~map();
    friend class object;      //��Ԫ������
	friend class PacMan;       //���������ʶ��ӵ�ͼ
	void DrawMap(HDC &hdc);    //���Ƶ�ͼ
	void DrawPeas(HDC &hdc);      //���ƶ���
	void initOP();    //����˫����ʼλ��û�ж���

protected :
	static  int LD;  // �ϰ���ߴ�
	static int PD;   //���Ӱ뾶
	
	bool peaMapData[MAPLENTH][MAPLENTH];   //���ӵ�ͼ����
	bool mapData[MAPLENTH][MAPLENTH];   // �ϰ����ͼ����
	COLORREF color;
};

class stage_1 :public map
{
private :
	bool static initData[MAPLENTH][MAPLENTH];
public:
	stage_1();
};