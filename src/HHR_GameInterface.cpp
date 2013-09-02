#include "HHR_GameInterface.h"

HHR_GameInterface::HHR_GameInterface()
{
    //ctor

	scoreBuffer = score = 0; 


}

bool HHR_GameInterface::Load()
{

	if(HenryHead.CreateAnimatedSprite("Assets/HenryHudsonHead2.png",4,4, 2500, true))
    {
        return false;
    }

	HenryHead.SetPosition((WWIDTH/4), (WHEIGHT/4));
	SDL_Color TextColor = {0,0,0};

	if(!ScoreDisplayText.LoadSpriteText("Assets/Romanesque_Serif.ttf", "0", 25,(WWIDTH/2), (WHEIGHT/6),TextColor))
    {
        return false;
    }

	return true; 

}

void HHR_GameInterface::IncreaseScore(unsigned int socreToAdd )
{
	scoreBuffer += socreToAdd; 
}

void HHR_GameInterface::UpDate()
{

	if(scoreBuffer != 0)
	{
		score++; 
		scoreBuffer--; 
		char buffer [256]; 
		 itoa(score,buffer,10); 
		ScoreDisplayText = buffer; 
	}
	HenryHead.OnLoop();
	
}

void HHR_GameInterface::SetHealthIndecator(HealthStatus newHenryHealth)
{
	HenryHead.SetNumberRow(newHenryHealth); 
	HenryHead.SetNumberColumn(0); 

	if(newHenryHealth == Dead)
	{
		HenryHead.SetRate(500); 
		HenryHead.SetLoop(false); 
	}

}


void HHR_GameInterface::Render(MainRender	&theRenderer)
{

	 HenryHead.OnRender(theRenderer);
	 ScoreDisplayText.OnRender(theRenderer); 

}

void HHR_GameInterface::Cleanup()
{
	HenryHead.OnCleanup();
	ScoreDisplayText.OnCleanup(); 
}


HHR_GameInterface::~HHR_GameInterface()
{
    //dtor
}
