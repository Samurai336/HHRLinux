/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of Henry Hudson's Revenge. A Cross Platform project,      **
**  also Known as HHR_X and referd to as such thoughout.						**
**  																			**
**  HHR_X is free software: you can redistribute it and/or modify			  	**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  HHR_X is distributed in the hope that it will be useful,					**
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with HHR_X.  If not, see <http://www.gnu.org/licenses/>.			  	**
**  																			**
**********************************************************************************/

#include "GameLevel1.h"





GameLevel1::GameLevel1()
{
    //SpriteAnimation Sprite();
    //ctor
}

GameLevel1::~GameLevel1()
{
    //dtor
}


bool GameLevel1::LoadLevel()
{




    if(Test.Load("Assets/skullPowerUp2.png"))
    {
           return false;
    }
    Test.setSpeed(1,1);



   


    if(!AMessage.LoadSpriteText("Assets/Romanesque_Serif.ttf", "Hello World"))
    {
        return false;
    }

    AMessage.setPosition((WWIDTH/2), (WHEIGHT/4));
	SDL_Color TextColor = {0,0,0}; 
	TextColor = TextColor; 
    AMessage.setColor(TextColor);
    AMessage.setFontSize(25);



   


	char *Textures[2]= {"Assets/LageBackgound2.png","Assets/LageBackgound2.png"};

	background.LoadEnvirement("Assets/LageBackgound2.png",
								Textures,
								2,
								Down,
								2);





    return true;
}

void GameLevel1::OnEvent(SDL_Event* Event)
{
    Events::OnEvent(Event);

}
void GameLevel1::OnLoop()
{
   
    Test.OnLoop();
	background.UpDate();




}
void GameLevel1::OnRender(MainRender	&theRenderer)
{

	background.Render(theRenderer);
   
    Test.OnRender(theRenderer);
    AMessage.OnRender(theRenderer);

}
void GameLevel1::OnCleanup()
{
	background.Cleanup();
    
    AMessage.OnCleanup();
}
