#include "FrameRateController.h"


FrameRateController::FrameRateController(void)
{

	TargetHertz = 15;
	OldTime = 0;
	LastTime = 0;

	NumFrames =0 ;
	Frames = 0 ;

	maxHzHit = false;



}

FrameRateController::FrameRateController(unsigned int TargetHz)
{
	TargetHertz = TargetHz;
	OldTime = 0;
	LastTime = 0;

	NumFrames =0 ;
	Frames = 0 ;

	maxHzHit = false;
}


FrameRateController::~FrameRateController(void)
{

}


void FrameRateController::OnLoop()
{
    uint32_t CurrentTicks = SDL_GetTicks();
	if(OldTime < CurrentTicks)
	{
	    uint32_t updateIntervel = (1000/TargetHertz);
		OldTime = SDL_GetTicks() + updateIntervel;

		maxHzHit = true;
	}
	else
    {

        Frames++;
        maxHzHit = false;

    }

    CurrentTicks = SDL_GetTicks();
    if(FPSTime < CurrentTicks)
    {
        NumFrames = Frames;
        Frames = 0;
        FPSTime = SDL_GetTicks() + 1000;
    }

	LastTime = SDL_GetTicks();


}

bool FrameRateController::TargetRateHit()
{
	OnLoop();

	return maxHzHit;
}

int FrameRateController::GetFPS()
{
	return NumFrames ;
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
