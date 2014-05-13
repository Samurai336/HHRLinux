#include "FrameRateController.h"



FrameRateController::FrameRateController(unsigned int TargetHz, unsigned int targetGameSpeed)
{
	TargetHertz = TargetHz;
	OldTime = 0;
	LastTime = 0;
    TargetGameSpeed = targetGameSpeed;

	NumFrames =0 ;
	Frames = 0 ;

	maxHzHit = false;
}


FrameRateController::~FrameRateController(void)
{

}


void FrameRateController::OnLoop()
{
    uint32_t currentTime = SDL_GetTicks();


    if( (currentTime-OldTime) > (1000/TargetHertz))
    {
        OldTime = SDL_GetTicks();
        Frames++;
        maxHzHit = false;
    }
    else
    {

        maxHzHit = true;
    }     

    if((currentTime - FPSTime) > 1000)
    {
        FPSTime= SDL_GetTicks();
        NumFrames = Frames ;
        Frames = 0;
    }

    gameSpeed = (float)TargetGameSpeed/(float)TargetHertz;




	LastTime = SDL_GetTicks();

}

bool FrameRateController::TargetRateHit()
{
	OnLoop();

    return maxHzHit;
}

float FrameRateController::GetGameSpeed()
{
    return gameSpeed;
}

void FrameRateController::SetGameSpeed(unsigned int gameSpeed)
{
    TargetGameSpeed = gameSpeed;
}

int FrameRateController::GetFPS()
{
    if(NumFrames == 0)
    {
        return 0;
    }
    else
    {
        return   (NumFrames);
    }

}

int	FrameRateController::GetTargetHerz()
{
	return TargetHertz;
}

void FrameRateController::SetTargetHz(unsigned int targetRate)
{
	TargetHertz = targetRate;
}

void FrameRateController::Render()
{

}
