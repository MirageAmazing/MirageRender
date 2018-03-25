#pragma once

#include "../BaseRender/BaseRender.h"
#include <GL/glew.h>

#if defined(MIRAGE_PLATFORM_LINUX)

class RenderOGL4 :public BaseRender
{
public:
	RenderOGL4(int iScreenWidth, int iScreenHeight, void* pWindowHandle);
	~RenderOGL4();

	void Frame() override;

protected:
	void OnSetClearColor() override;
};

#endif