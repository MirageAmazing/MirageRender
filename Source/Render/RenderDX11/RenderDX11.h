#pragma once

#if defined(MIRAGE_PLATFORM_WINDOWS)

#include "../BaseRender/BaseRender.h"
#include <dxgi.h>
#include <d3d11.h>

#pragma comment(lib, "dxgi.lib")

class RenderDX11 :public BaseRender
{
public:
	RenderDX11(int iScreenWidth, int iScreenHeight, HWND hWnd);
	~RenderDX11();

	void Frame() override;

protected:
	bool EnvirmentCheck() override;
	void OnSetClearColor() override;

private:
	HWND mHwnd;
};

#endif