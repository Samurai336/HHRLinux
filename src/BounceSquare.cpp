#include "BounceSquare.h"


BounceSquare::BounceSquare(void)
{
	BaseUnit(); 
	speedX	= speedY = 0; 

}

void BounceSquare::Load(char* File)
{
	BaseUnit::Load(File); 

	SDL_QueryTexture(unitTexture, NULL, NULL, &width, &height); 
	
}

void BounceSquare::setSpeed(float xSpeed, float ySpeed) 
{
	speedX = xSpeed; 
	speedY = ySpeed; 
}


void BounceSquare::OnLoop()
{

	if(X < 0 || (X+width) > WWIDTH)
	{
		speedX *= -1; 
	}

	if(Y < 0 || (Y+width) > WHEIGHT)
	{
		speedY *= -1;
	}

	X += speedX; 
	Y += speedY; 
}
		
void BounceSquare::OnRender()
{
	BaseUnit::OnRender(); 
}

void BounceSquare::OnCleanup()
{

}


BounceSquare::~BounceSquare(void)
{
}
