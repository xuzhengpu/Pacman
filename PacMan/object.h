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
	void virtual action() = 0;   //具体的行为，纯虚函数
	void virtual Draw(HDC &hdc)=0;//绘制对象，纯虚函数，根据具体对象重新定义
	bool Collision(); //逻辑碰撞检查 ，将物体摆放到合理的位置
	bool Achive();        // 判断物体是否到达逻辑坐标位置
	void virtual AchiveCtrl();  //到达逻辑点后更新数据
	int PtTransform(int n); //将实际坐标转换成逻辑坐标
	int GetRow();
	int GetArray();
	void DrawBlank(HDC & hdc);
	void SetPosition(int row, int array);
	map  static *pstage;   //指向地图的指针
protected:
	TWARDS tw;    //枚举类型 对象的朝向
	POINT point;   //中心坐标
	int drow;
	int darray;
	int speed;
	TWARDS twCommand;
	int frame; //帧数
	int mX;
	int mY;
};
