#pragma once

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 

#include "../Define.h" 
#include "../BaseClasses/BaseUnit.h"


class MainRender
{

	public:

		SDL_Texture* LoadTexture(char* File); 


	public:

		MainRender(void); 

		bool InitRenderer(SDL_Window*); 

		bool Draw(SDL_Texture* theTexture, int X, int Y, double rotation = 0.0);  
		bool Draw(SDL_Texture* theTexture, int X, int Y, int X2, int Y2, int W, int H, double rotation = 0.0); 
		


		void CreateDisplayRect(); 

        void RenderDisplay();

		void Clean(); 
		//static SDL_Texture *OnLoad(char *filePath, SDL_Renderer *MainRenderer); 

		
	private: 
		SDL_Renderer*    Renderer;


};

