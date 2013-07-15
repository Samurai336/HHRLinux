#ifndef _MAINAPP_H_
#define _MAINAPP_H_





#include <SDL2/SDL.h>
#include "Define.h"
#include "BaseClasses/Events.h"
#include "Renderer/MainRender.h"
#include "BaseClasses/Level.h"
#include "BounceSquare.h"

  
class MainApp : public Events
{
    /* Singleton stuff */
    public:
        static MainApp* Instance();



    private:
        MainApp();
        MainApp(MainApp const&){};
        MainApp& operator = (MainApp const&){};
        static MainApp* m_pInstance;

    /*************************/

    public:

        int OnExecute();

    public:

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnKeyDown(SDL_Keycode sym,  SDL_Keymod mod, Uint16 unicode);

        void OnKeyUp(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode);

        void OnExit();

        void OnLoop();

		void LoadGame(); 



        void OnRender();

        void OnCleanup();

		MainRender* GetMainRenderTarget(); 


    private:
        bool            Running;
		

		BounceSquare		Test; 

        Level*          CurrentLevel;
		SDL_Window*		MainWindow;
		MainRender		MainRenderTarget;
		





};



#endif
