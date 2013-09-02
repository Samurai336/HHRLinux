#ifndef HHR_GAMEINTERFACE_H
#define HHR_GAMEINTERFACE_H

#include <stdlib.h>
#include <stdio.h>

#include "BaseClasses/BaseInterface.h" 
#include "BaseClasses/SpriteText.h" 
#include "BaseClasses/SpriteAnimation.h"


enum HealthStatus
{
	Healthy=0,
	Hurt, 
	Dieing, 
	Dead

}; 


class HHR_GameInterface: public BaseInterface 
{
    public:
        HHR_GameInterface();
        virtual ~HHR_GameInterface();
		
		bool Load(); 

		void UpDate();

		void Render(MainRender	&theRenderer);

		void Cleanup();

		void IncreaseScore(unsigned int socreToAdd); 

		void SetHealthIndecator(HealthStatus newHenryHealth); 

		

    protected:
    private:
		int scoreBuffer; 
		unsigned int score; 
		SpriteText ScoreDisplayText; 
		SpriteAnimation HenryHead; 
		
};

#endif // HHR_GAMEINTERFACE_H
