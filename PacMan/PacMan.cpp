// PacMan.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "PacMan.h"
#include "object.h"
#include "BlueOne.h"
#include "Enermy.h"
#include "RedOne.h"
#include "YellowOne.h"
#define MAX_LOADSTRING 100
#define WLENTH 700
#define WHIGHT 740
#define STAGE_COUNT 1
BOOL InitInstan(HINSTANCE hInstance, int nCmdShow, HWND &hwnd);
//template <class T>
//void Realese(T t)
//{
//	if (t != NULL)
//	{
//        delete t;
//	}
//		
//}
// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
PacMan * p;
object *e1;
object *e2; 
object *e3;
object *e4;
// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。
	int s_n = 0;   //进行到的关卡数
	p = new PacMan(PROW, PARRAY);
	e1 = new RedOne(EROW, EARRAY);
	e2 = new RedOne(EROW, EARRAY);
	e3 = new BlueOne(EROW, EARRAY);
	e4 = new YellowOne(EROW, EARRAY);
	map * MapArray =  new stage_1() ;
	object::pstage = MapArray;
	Enermy::player = p;
    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PACMAN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
	HWND hwnd;  // 拿到窗口句柄
    if (!InitInstan (hInstance, nCmdShow,hwnd))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PACMAN));

    MSG msg;
	DWORD t = 0;
	HDC hdc = GetDC(hwnd);
	object::pstage->DrawMap(hdc);
    // 主消息循环:
    while (p->GetTw()!=OVER&&s_n<1)
    {
		
		
		if(PeekMessage(&msg, NULL, 0, 0,PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
		if (p->win())
		{
			MessageBoxA(hwnd, "恭喜过关","吃豆子提醒", MB_OK);
			s_n++;	
		}
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			p->SetTwcommand(RIGHT);
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			p->SetTwcommand(DOWN);
		if (GetAsyncKeyState(VK_UP) & 0x8000)
			p->SetTwcommand(UP);
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			p->SetTwcommand(LEFT);
		
		if (GetTickCount() - t > 58)
			{ 
				HDC hdc = GetDC(hwnd);
				e1->action();
				e2->action();
				e3->action();
				e4->action();
				p->action();
				object::pstage->DrawPeas(hdc);
				e1->DrawBlank(hdc);
				e2->DrawBlank(hdc);
				e3->DrawBlank(hdc);
				e4->DrawBlank(hdc);
				p->DrawBlank(hdc);
				e1->Draw(hdc);
				e2->Draw(hdc);
				e3->Draw(hdc);
				e4->Draw(hdc);
				p->Draw(hdc);
				DeleteDC(hdc);
				t = GetTickCount();
			}
    }

	delete e1;
	delete e2;
	delete e3;
	delete e4;
	delete MapArray;
	if (s_n >= 1)
	{
		MessageBoxA(hwnd, "恭喜通关，游戏结束","吃豆子提醒", MB_OK);
	}
	else
	{
		MessageBoxA(hwnd, "出师未捷", "吃豆子提醒", MB_OK);
	}
	delete p;
    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PACMAN));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PACMAN);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstan(HINSTANCE hInstance, int nCmdShow,HWND &hwnd)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   hwnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hwnd)
   {
      return FALSE;
   }

   ShowWindow(hwnd, nCmdShow);
   UpdateWindow(hwnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
		::exit(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void PacMan::AchiveCtrl()
{
	object::AchiveCtrl();  //更新玩家的坐标
	if (Achive())   //如果到达中心点，把豆子吃掉
	{
		if (drow >= 0 && drow < MAPLENTH&&darray >= 0 && darray < MAPLENTH)
		{
			if (pstage->peaMapData[drow][darray])
				pstage->peaMapData[drow][darray] = false;//吃掉豆子
		}
	}

}

POINT PacMan::GetPos()
{
	return point;
}

bool PacMan::win()
{  
	for (int i = 0; i < MAPLENTH; i++)
	{
		for (int j = 0; j < MAPLENTH; j++)
		{
			if (pstage->peaMapData[i][j]==true)
			{
				return false;  //还有豆子，游戏没有结束
			}
		}
	}
	return true;
}

void PacMan::Draw(HDC & hdc)
{
	if (tw == OVER)
	{
	}
	else if (frame % 2 == 0)   //第2,4，帧
	{
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		int offsetx = DISTANCE / 2 + OFFSET;
		int offsety = DISTANCE / 2 + OFFSET;
		switch (tw)
		{
		case UP:
			x1 = point.x - offsetx;
			x2 = point.x + offsetx;
			y2 = y1 = point.y - offsety;
			break;
		case DOWN:
			x1 = point.x + offsetx;
			x2 = point.x - offsetx;
			y2 = y1 = point.y + offsety;
			break;
		case LEFT:
			x2 = x1 = point.x - offsetx;
			y1 = point.y + offsetx;
			y2 = point.y - offsety;
			break;
		case RIGHT:
			x2 = x1 = point.x + offsetx;
			y1 = point.y - offsetx;
			y2 = point.y + offsety;
			break;

		}
		Arc(hdc, point.x - DISTANCE, point.y - DISTANCE,
			point.x + DISTANCE, point.y + DISTANCE,
			x1, y1,
			x2, y2);
	}
	else if (frame % 3 == 0)   //第3帧
	{
		Ellipse(hdc, point.x - DISTANCE, point.y - DISTANCE,
			point.x + DISTANCE, point.y + DISTANCE);
	}
	else 
	{
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		switch (tw)
		{
		case UP:
			x1 = point.x - DISTANCE;
			x2 = point.x + DISTANCE;
			y2 = y1 = point.y;
			break;
		case DOWN:
			x1 = point.x + DISTANCE;
			x2 = point.x - DISTANCE;
			y2 = y1 = point.y;
			break;
		case LEFT:
			x2 = x1 = point.x;
			y1 = point.y + DISTANCE;
			y2 = point.y - DISTANCE;
			break;
		case RIGHT:
			x2 = x1 = point.x;
			y1 = point.y - DISTANCE;
			y2 = point.y + DISTANCE;
			break;
			

		}
           Arc(hdc, point.x - DISTANCE, point.y - DISTANCE,
				point.x + DISTANCE, point.y + DISTANCE,
				x1, y1,
				x2, y2);
			MoveToEx(hdc, x1, y1, NULL);
			LineTo(hdc, point.x, point.y);
			LineTo(hdc, x2, y2);	    
	}
	frame++;
}
void PacMan::SetTwcommand(TWARDS command)
{
	twCommand = command;
}

void PacMan::Over()
{
	tw = OVER;
}

void PacMan::action()
{
	Collision();  //大嘴的活动只有一种就是碰壁检查
}

TWARDS PacMan::GetTw()
{
	return tw;
}
