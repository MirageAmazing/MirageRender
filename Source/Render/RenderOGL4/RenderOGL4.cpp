#include "RenderOGL4.h"

RenderOGL4::RenderOGL4(int iScreenWidth, int iScreenHeight, HWND hWnd) :BaseRender(iScreenWidth, iScreenHeight, hWnd)
{
	glewInit();
	auto info = glGetString(GL_VERSION);
	MessageBox(mHwnd, (WCHAR*)info, TEXT("ME"), MB_YESNO);
}

RenderOGL4::~RenderOGL4()
{

}

void RenderOGL4::OnSetClearColor()
{

}

void RenderOGL4::Frame()
{

}