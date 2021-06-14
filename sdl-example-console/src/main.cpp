#include "headref.h"

Uint32 start_time, frame_time;
float fps;

float timerr;

void render()
{
	timerr += .005f;
	for(unsigned int i = 0; i < GameObject::getAllObjects().size(); i++)
	{
		GameObject::getAllObjects()[i] -> Update();
		GameObject::getAllObjects()[i] -> SetPos(0.f, timerr, 0.f);
	}

}

void FpsCalcInit()
{
	start_time = SDL_GetTicks();
}

void FpsCalc()
{
	frame_time = SDL_GetTicks() - start_time;
	fps = (frame_time > 0) ? 1000.f / frame_time : 0.f;
	std::cout << fps << std::endl;
}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = Display::CreateWindow();
	SDL_GLContext context = SDL_GL_CreateContext(window);

	SDL_Event event;	
	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	bool running = true; 
	Display::GLSettings();
	Display::GLAttributes();

	while(running)
	{
		while(SDL_PollEvent(&event))
		{
			running = event.type != SDL_QUIT;
			Console::KeyToChar(event);
		}

	//	FpsCalcInit();

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		Console::Update();
		
			
		Camera::Translate(keyState);
		Camera::Rotate(keyState);
		Camera::Update();
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
		render();

		if(Console::GetState())
			ScreenLogger::RenderText(Console::GetCharacters().insert(0, "> "), {255, 255, 255}, 0, 0, "../src/assets/font/arial.ttf", 12);

		SDL_GL_SwapWindow(window);

	//	FpsCalc();
	}
	
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
