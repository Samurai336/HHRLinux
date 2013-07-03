#ifndef _MAINAPP_H_
#define _MAINAPP_H_


#include <SDL2/SDL.h>

#include "Define.h"
#include "Events.h"
#include "MainRender.h" 


class MainApp : public Events
{
	private:
        bool            Running;
   
		SDL_Window*		MainWindow;
		MainRender		MainRenderTarget; 
		SDL_Renderer*	theRenderer; 

      

    public:
        MainApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event* Event);

        	void OnKeyDown(SDL_Keycode sym,  SDL_Keymod mod, Uint16 unicode);

        	void OnKeyUp(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode);

            void OnExit();

        void OnLoop();

        void OnRender();

        void OnCleanup();
};



#endif
