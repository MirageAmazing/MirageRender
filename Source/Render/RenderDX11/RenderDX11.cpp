#include "RenderDX11.h"

#if defined(MIRAGE_PLATFORM_WINDOWS)

RenderDX11::RenderDX11(int iScreenWidth, int iScreenHeight, void* pWindowHandle) :BaseRender(iScreenWidth, iScreenHeight, pWindowHandle)
{
	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	SDL_GetWindowWMInfo(window, &wmInfo);

	mHwnd = wmInfo.info.win.window;

	EnvirmentCheck();
}

RenderDX11::~RenderDX11()
{
	
}

bool RenderDX11::EnvirmentCheck()
{
	HRESULT result;
	IDXGIFactory* factory;
	IDXGIAdapter* adapter;
	IDXGIOutput* output;

	result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
	if (FAILED(result))
	{
		return false;
	}

	result = factory->EnumAdapters(0, &adapter);//video card
	if (FAILED(result))
	{
		return false;
	}

	result = adapter->EnumOutputs(0, &output);//monitor
	if (FAILED(result))
	{
		return false;
	}

	DXGI_ADAPTER_DESC adapterDesc;
	adapter->GetDesc(&adapterDesc);

	MessageBox(mHwnd, adapterDesc.Description, TEXT("ME"), MB_YESNO);

	return true;
}

void RenderDX11::OnSetClearColor()
{

}

void RenderDX11::Frame()
{

}

#endif