#include "SDL2/SDL.h"
#include "SDL2/SDL_main.h"
#include "./Render/BaseRender/BaseRender.h"
#include "Core/Math/Vector2.h"
#include "Core/Math/Vector3.h"

using namespace MirageMath;

void TestMain();

int main(int argc, char* argv[])
{
	TestMain();

	bool isRun = true;
	SDL_Window *window = 0;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("MERender", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
	
	auto render = BaseRender::GetRender(RenderType::OpenGL40, 800, 600, window);
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

	int x = 0;
	x++;
}