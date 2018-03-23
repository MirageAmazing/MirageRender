#pragma once
#include "../BaseRender/BaseRender.h"
#include <GL\glew.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glew32s.lib")

class RenderOGL4 :public BaseRender
{
public:
	RenderOGL4(int iScreenWidth, int iScreenHeight, HWND hWnd);
	~RenderOGL4();

	void Frame() override;

protected:
	void OnSetClearColor() override;
};