#pragma once

#include <Windows.h>
#include <memory>
using namespace std;

enum RenderType
{
	DirectX11,
	OpenGL40
};

class BaseRender
{
public:
	BaseRender(int iScreenWidth, int iScreenHeight, HWND hWnd);
	BaseRender(BaseRender&& render);
	virtual ~BaseRender();
	BaseRender(BaseRender&) = delete;

	void SetClearColor(float r, float g, float b);

	virtual void Frame();

protected:
	virtual bool EnvirmentCheck();
	virtual void OnSetClearColor();

protected:
	int mRenderWidth = 800;
	int mRenderHeight = 600;
	float mClearColor[3]{0,0,0};
	HWND mHwnd;

public:
	static unique_ptr<BaseRender> GetRender(RenderType type, int iScreenWidth, int iScreenHeight, HWND hWnd);

private:
	static unique_ptr<BaseRender> mBaseRender;
};