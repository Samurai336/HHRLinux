#include "FrameRateController.h"


FrameRateController::FrameRateController(void)
{

	TargetHertz = 30;
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
        if(Frames > (1000/TargetHertz))
        {
            NumFrames += Frames;
            Frames = 0;
            maxHzHit = true;
        }
        else
        {

            maxHzHit = false ;
            Frames++;
        }


        uint32_t CurrentTime = SDL_GetTicks() ;
        if( FPSTime < CurrentTime)
        {
            NumFrames = 0;
            FPSTime = CurrentTime+ 1000;

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
    if(NumFrames == 0)
    {
        return 0;
    }
    else
    {
        return   (1000/NumFrames);
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
