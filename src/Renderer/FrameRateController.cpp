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
	if(OldTime + 1000 < SDL_GetTicks()) 
	{
		OldTime = SDL_GetTicks();

		NumFrames = Frames;



		Frames = 0;
	}
	
	if(Frames >= TargetHertz)
	{
		maxHzHit = true; 
		
	}
	else
	{
		maxHzHit = false; 
	}

	LastTime = SDL_GetTicks();

	Frames++;

}

bool FrameRateController::TargetRateHit()
{
	OnLoop(); 

	return maxHzHit; 
}


int FrameRateController::GetFPS()
{
	return NumFrames; 
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
