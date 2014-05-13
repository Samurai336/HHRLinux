#pragma once


#include <SDL2/SDL.h>


class FrameRateController
{
	public:	
        FrameRateController(unsigned int TargetHz = 64, unsigned int targetGameSpeed = 64);
		virtual ~FrameRateController(void);

		void    OnLoop();

		int     GetFPS();

		int		GetTargetHerz();

		void	SetTargetHz(unsigned int targetRate);

        void	SetGameSpeed(unsigned int gameSpeed);

		bool	TargetRateHit();

        float   GetGameSpeed();

		void Render();

	private:
		uint32_t     OldTime;
		uint32_t     LastTime;
		uint32_t     FPSTime;
        float        gameSpeed;

		unsigned int 	TargetHertz;
        unsigned int 	TargetGameSpeed;

		int		NumFrames;
		int     Frames;

		bool maxHzHit;





};


