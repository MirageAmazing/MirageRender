#include "SDL2/SDL.h"
#include "SDL2/SDL_main.h"

#include "MirageEngine.h"
#include "./Render/BaseRender/BaseRender.h"
#include "Core/Math/Vector2.h"
#include "Core/Math/Vector3.h"
#include "Core/Math/Matrix.h"

using namespace MirageMath;

void TestMain();

int main(int argc, char* argv[])
{
	TestMain();

	#if defined(MIRAGE_PLATFORM_WINDOWS)
	#else
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	#endif
	
	bool isRun = true;
	SDL_Window *window = 0;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("MERender", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
	
	#if defined(MIRAGE_PLATFORM_WINDOWS)
		auto render = BaseRender::GetRender(RenderType::DirectX11, 800, 600, window);
	#else
		auto render = BaseRender::GetRender(RenderType::OpenGL40, 800, 600, window);
	#endif

	float colorVar = 0;

	while(isRun)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_EventType::SDL_QUIT:
				isRun = false;
				break;
			}
		}
		render->SetClearColor(0, colorVar, 0);
		render->Frame();

		if (colorVar > 1) colorVar = 0;
		else colorVar += 0.001f;
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

void TestMain()
{
	Vector2f vecA(12, 90);
	Vector2f vecB(65, 45);

	auto vecC = 2.0f*vecA + 300.0f/vecB;
	auto result = Vector2f::Dot(vecA, vecB);

	Vector3f vecAA(1, 2, 3);
	Vector3f vecBB(2, 24, 13);
	auto vecCC = vecAA + vecBB + Vector3f::Left;

	Matrix4x4f mA = Matrix4x4f::IndentityMatrix();
	auto mB = mA*32.0f;
	mB = 23 * mB;

	Matrix3x3f m3A = Matrix3x3f::IndentityMatrix();
	m3A[0][1] = 23;
	m3A[1][0] = 3;

	auto m3A_Invered = m3A.Inverse();
	auto m3A_Result = m3A*m3A_Invered;

	auto size = sizeof(MEGUID);

	int x = 0;
	x++;
}