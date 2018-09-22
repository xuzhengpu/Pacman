#pragma once
#define MAPLENTH 19
#include "stdafx.h"
#include <list>
#define A true
#define B false
#define EARRAY 9   //初始化敌方的位置
#define EROW 8
#define PARRAY 9   //初始我方位置
#define PROW 10

class map
{
public:
	map();
	~map();
    friend class object;      //友元物体类
	friend class PacMan;       //允许大嘴访问豆子地图
	void DrawMap(HDC &hdc);    //绘制地图
	void DrawPeas(HDC &hdc);      //绘制豆子
	void initOP();    //敌我双方开始位置没有豆子

protected :
	static  int LD;  // 障碍物尺寸
	static int PD;   //豆子半径
	
	bool peaMapData[MAPLENTH][MAPLENTH];   //豆子地图点阵
	bool mapData[MAPLENTH][MAPLENTH];   // 障碍物地图点阵
	COLORREF color;
};

class stage_1 :public map
{
private :
	bool static initData[MAPLENTH][MAPLENTH];
public:
	stage_1();
};