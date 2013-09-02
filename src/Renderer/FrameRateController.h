#pragma once


#include <SDL2/SDL.h> 


class FrameRateController
{
	public:
		FrameRateController(void);
		FrameRateController(unsigned int TargetHz);
		virtual ~FrameRateController(void);

		void    OnLoop();

		int     GetFPS();

		int		GetTargetHerz();

		void	SetTargetHz(unsigned int targetRate); 

		bool	TargetRateHit(); 

		void Render();

	private:
		int     OldTime;
		int     LastTime;

		unsigned int 	TargetHertz;

		int		NumFrames;
		int     Frames;

		bool maxHzHit; 





};
