#include "MainApp.h"


MainApp::MainApp()
{
	MainWindow = NULL;

	Running = true; 
}

int MainApp::OnExecute()
{
		if(OnInit() == false)
		{
			return -1; 
		}

		SDL_Event Event; 


		while (Running)
		{
			while (SDL_PollEvent(&Event))
			{
				OnEvent(&Event); 
			}

			OnLoop(); 

			//OnRender();

			MainRenderTarget.Render(); 


		}

		OnCleanup(); 

		return 0; 
}


bool MainApp::OnInit()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("failed to initi\n");
		printf("SDL_Init failed: %s\n", SDL_GetError()); 
        	return false;
	}

	MainWindow = SDL_CreateWindow("HHR_X",
							  SDL_WINDOWPOS_CENTERED, 
							  SDL_WINDOWPOS_CENTERED,
							  WWIDTH, WHEIGHT,
                              SDL_WINDOW_RESIZABLE );


	if(MainRenderTarget.InitRenderer(MainWindow) == false )
	{
		printf("Main Render Target Failed to Initilize\n"); 
		return false;
	}





	return true; 
}


void MainApp::OnEvent(SDL_Event* Event) 
{
    Events::OnEvent(Event);
}


void MainApp::OnKeyDown(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode) 
{
	switch(sym)
	{
		default: 
		{

		}
	}
}

void MainApp::OnKeyUp(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode) 
{
	switch(sym)
	{
		default: 
		{

		}
	}
}


void MainApp::OnExit()
{
	Running = false; 
}


void MainApp::OnLoop()
{

}


void MainApp::OnRender()
{
}


void MainApp::OnCleanup()
{
	//SDL_DestroyRenderer(Renderer);
	MainRenderTarget.Clean(); 
	SDL_DestroyWindow(MainWindow); 


    SDL_Quit();
}
