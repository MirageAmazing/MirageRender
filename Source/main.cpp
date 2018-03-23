﻿#include <Windows.h>
#include "Render\BaseRender\BaseRender.h"

#define CONVERTSTR(str) TEXT(str)

int gWidth = 800;
int gHeight = 600;

HINSTANCE gInstance;
HWND gHwnd;
LRESULT CALLBACK WinMsgProc( HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
void InitSys();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	gInstance = hInstance;

	WNDCLASS  wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WinMsgProc;
	wndcls.lpszClassName = CONVERTSTR("MirageRender");
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndcls);

	gHwnd = CreateWindow(CONVERTSTR("MirageRender"), CONVERTSTR("MirageRender"), WS_OVERLAPPEDWINDOW, 50, 50, gWidth, gHeight,
		NULL, NULL, hInstance, NULL);

	ShowWindow(gHwnd, SW_NORMAL);
	UpdateWindow(gHwnd);
	InitSys();

	MSG  msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WinMsgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CHAR:
		break;

	case WM_LBUTTONDOWN:
		break;

	case WM_RBUTTONDOWN:
		break;

	case WM_CLOSE:
		//if (IDYES == MessageBox(hwnd, CONVERTSTR("Do you quit now ？"), CONVERTSTR("Tips"), MB_YESNO))
		{
			DestroyWindow(hwnd);
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}

	return 0;
}

void InitSys()
{
	BaseRender::GetRender(RenderType::OpenGL40, gWidth, gHeight, gHwnd);
}