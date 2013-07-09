#ifndef LEVEL_H
#define LEVEL_H


#include "Events.h"


class Level : public Events
{
    public:
        Level(){};
        virtual ~Level();
        virtual void LoadLevel() = 0;
        virtual void OnEvent(SDL_Event* Event) =0 ;
        virtual void OnLoop()= 0;
        virtual void OnRender(SDL_Renderer*	theRenderer)= 0;
        virtual void OnCleanup() =0;


    protected:
        bool isLoading;
    private:

};

#endif // LEVEL_H
