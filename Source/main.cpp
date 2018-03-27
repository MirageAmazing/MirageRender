#include "SDL2/SDL.h"
#include "SDL2/SDL_main.h"
#include "./Render/BaseRender/BaseRender.h"

#pragma comment(lib ,"SDL2.lib")  
#pragma comment(lib ,"SDL2main.lib") 

int main(int argc, char* argv[])
{
	bool isRun = true;
	SDL_Window *window = 0;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("MERender", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
	
	auto render = BaseRender::GetRender(RenderType::DirectX11, 800, 600, window);

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
		render->Frame();
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}