#include "BaseUnit.h"

//This is here due to circulalr dependency issue. 
#include "../MainApp.h"



BaseUnit::BaseUnit(void)
{
	
	X = Y = 0.0f; 
	unitTexture = NULL; 
	rotation = 0.0; 
	renderOrder = 1; 
	
}


BaseUnit::~BaseUnit(void)
{
	
}


void BaseUnit::Load(char* File)
{
	 unitTexture = MainApp::Instance()->GetMainRenderTarget()->LoadTexture(File); 
}


void BaseUnit::OnLoop()
{

}

void BaseUnit::OnRender()
{
	MainApp::Instance()->GetMainRenderTarget()->Draw(unitTexture, X,Y, rotation);  
}

void BaseUnit::OnCleanup()
{
	 if(unitTexture) 
	 {
        SDL_DestroyTexture(unitTexture);
	 }

    unitTexture = NULL;
}

void BaseUnit::SetPosition(float MoveX, float MoveY)
{
	X = MoveX; 
	Y = MoveY; 
}
