#include "BaseRender.h"
#include "../RenderDX11/RenderDX11.h"
#include "../RenderOGL4/RenderOGL4.h"

unique_ptr<BaseRender> BaseRender::mBaseRender = nullptr;

unique_ptr<BaseRender> BaseRender::GetRender(RenderType type, int iScreenWidth, int iScreenHeight, HWND hWnd)
{
	switch (type)
	{
	case RenderType::DirectX11:
		if (mBaseRender == nullptr)
			mBaseRender = unique_ptr<BaseRender>(new RenderDX11(iScreenWidth, iScreenHeight, hWnd));
		return move(mBaseRender);
	case RenderType::OpenGL40:
		if (mBaseRender == nullptr)
			mBaseRender = unique_ptr<BaseRender>(new RenderOGL4(iScreenWidth, iScreenHeight, hWnd));
		return move(mBaseRender);
	}

	return nullptr;
}

BaseRender::BaseRender(int iScreenWidth, int iScreenHeight, HWND hWnd)
{
	mRenderWidth = iScreenWidth;
	mRenderHeight = iScreenHeight;
	mHwnd = hWnd;
}

BaseRender::BaseRender(BaseRender&& render)
{
	mHwnd = render.mHwnd;
	mClearColor[0] = render.mClearColor[0];
	mClearColor[1] = render.mClearColor[1];
	mClearColor[2] = render.mClearColor[2];
}

BaseRender::~BaseRender()
{
}

bool BaseRender::EnvirmentCheck()
{
	return true;
}

void BaseRender::SetClearColor(float r, float g, float b)
{
	mClearColor[0] = r;
	mClearColor[1] = g;
	mClearColor[2] = b;

	this->OnSetClearColor();
}

void BaseRender::OnSetClearColor()
{
}

void BaseRender::Frame()
{

}