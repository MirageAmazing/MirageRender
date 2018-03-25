#include "RenderOGL4.h"
#include <iostream>
using namespace std;

#if defined(MIRAGE_PLATFORM_LINUX)

RenderOGL4::RenderOGL4(int iScreenWidth, int iScreenHeight, void* pWindowHandle) :BaseRender(iScreenWidth, iScreenHeight, pWindowHandle)
{
	glewInit();
	glViewport(0, 0, iScreenWidth, iScreenHeight);  
	auto info = glGetString(GL_VERSION);
	cout<<"RenderOGL4"<<endl;
}

RenderOGL4::~RenderOGL4()
{

}

void RenderOGL4::OnSetClearColor()
{

}

void RenderOGL4::Frame()
{
	glClearColor(0.0, 1.0, 0.0, 1.0);	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);

glBegin(GL_LINE_LOOP);
	glVertex2f(0.25, 0.25);
	glVertex2f(0.75, 0.25);
	glVertex2f(0.75, 0.75);
	glVertex2f(0.25, 0.75);
glEnd();

	glFlush();
}

#endif