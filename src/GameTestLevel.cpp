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

#include "GameTestLevel.h"





GameTestLevel::GameTestLevel()
{
    //SpriteAnimation Sprite();
    //ctor
}

GameTestLevel::~GameTestLevel()
{
    //dtor
}


bool GameTestLevel::LoadLevel()
{




    if(Test.Load("Assets/skullPowerUp2.png"))
    {
           return false;
    }
    Test.setSpeed(1,0);

    Test.setRotationSpeed(2.2);

    Test.SetPosition(WWIDTH-50, (WHEIGHT)/2);

    if(Test2.Load("Assets/skullPowerUp2.png"))
    {
        return false;
    }
    Test2.setSpeed(-1,0);

    //Test2.setRotationSpeed(1.0);

    Test2.SetPosition(50, (WHEIGHT)/2);

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



    if(Henry.CreateAnimatedSprite("Assets/HenryHudsonHead2.png",4,4, 2500, true))
    {
        return false;
    }

    Henry.SetPosition((WWIDTH/4), (WHEIGHT/4) );

    Henry.SetScale(0.5f);

    Test2.setRenderOrder(50);
    Test.setRenderOrder(50);

    Henry.setRenderOrder(50);


    if(BackGroundMusic.Load("Assets/Audio/music/spaceBkd.ogg"))
    {
        return false;
    }

    if(MainPlayer.SetUpHHRPlayer("Assets/Ship2.png",4,4,50,true))
    {
        return false;
    }

    MainPlayer.setRenderOrder(55);
    MainPlayer.StartAnimating();
    MainPlayer.SetPosition((WWIDTH/2), (WHEIGHT/2) );
    MainPlayer.SetScale(0.5f);



    anEnemy.SetUpHHREnemy("Assets/Boat2.png",6,1,35,false);
    anEnemy.SetPosition((100), (WHEIGHT/2) );

    anEnemy.setRenderOrder(50);

    anEnemy.SetScale(0.5f);

    BackGroundMusic.Play();


    aShootingEnemy.SetHHRShootingEnemy("Assets/electricShip2.png",3,3,50,true);
    aShootingEnemy.SetPosition((300), 200 );

    aShootingEnemy.StartAnimating();

    aShootingEnemy.setRenderOrder(50);


    return true;
}

void GameTestLevel::OnEvent(SDL_Event* Event)
{
    Events::OnEvent(Event);

    MainPlayer.OnEvent(Event);

}
void GameTestLevel::OnLoop()
{
   
    //Test.OnLoop();
    Test2.OnLoop();
    CheckCollision();
	background.UpDate();
    Henry.OnLoop();
    MainPlayer.OnLoop();
    anEnemy.OnLoop();
    aShootingEnemy.OnLoop();

    //Test2.SetPosition(MainPlayer.GetAnimationCenter());




}

void GameTestLevel::CheckCollision()
{
    if(HHR_Physics::Collider::Check(Test2.GetCollisionObject(),Test.GetCollisionObject()) ||
       HHR_Physics::Collider::Check(MainPlayer.GetCollisionObject(),Test.GetCollisionObject()) ||
       HHR_Physics::Collider::Check(Test2.GetCollisionObject(),MainPlayer.GetCollisionObject())
      )
    {
        Colliding = true;
    }
    else
    {
        Colliding = false;
    }
}


void GameTestLevel::OnRender(MainRender	&theRenderer)
{

    background.Render(theRenderer);
   
    //Test.OnRender(theRenderer);
    Test2.OnRender(theRenderer);
    Henry.OnRender(theRenderer);
    MainPlayer.OnRender(theRenderer);
    anEnemy.OnRender(theRenderer);
    aShootingEnemy.OnRender(theRenderer);

#ifdef PHYSICS_DEBUG
    Test.GetCollisionObject().OnRender(theRenderer, Colliding);
    Test2.GetCollisionObject().OnRender(theRenderer, Colliding);    
#endif


    AMessage.OnRender(theRenderer);

}

void GameTestLevel::OnKeyUp(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode)
{
    if(sym == SDLK_p)
    {
        aShootingEnemy.ModifyHealth(-15);
    }

    if(sym == SDLK_q)
    {
        aShootingEnemy.Reset();
    }

}
void GameTestLevel::OnCleanup()
{
	background.Cleanup();
    Test.OnCleanup();
    Test2.OnCleanup();
    MainPlayer.OnCleanup();
    anEnemy.OnCleanup();
    aShootingEnemy.OnCleanup();
    
    AMessage.OnCleanup();
}
