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

#ifndef GAMELEVEL1_H
#define GAMELEVEL1_H

#include "Define.h"
#include "BaseClasses/Level.h"
#include "Renderer/MainRender.h"
#include "BounceSquare.h"
#include "rotatingbouncesquare.h"
#include "BaseClasses/SpriteAnimation.h"
#include "BaseClasses/ScrollingBackGround.h"
#include "BaseClasses/SpriteText.h"
#include "BounceCircle.h"
#include "Audio/MusicSound.h"
#include "GameClasses/BaseGameClasses/HHR_Player.h"
#include "Physics/Collider.h"
#include "GameClasses/PlayableUnits/HenryHudson.h"
#include "GameClasses/AIUnits/HHREnemy.h"
#include "GameClasses/AIUnits/HHRShootingEnemy.h"
#include "GameClasses/AI_Manager.h"







class SpriteAnimation;

class GameTestLevel : public Level
{
    public:
        GameTestLevel();
        bool LoadLevel();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void CheckCollision();
        void OnRender(MainRender	&theRenderer);
        void OnKeyUp(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode);
        void OnCleanup();
        ~GameTestLevel();
    protected:

    private:
        BounceCircle Test;
        RotatingBounceSquare Test2;
        HenryHudson MainPlayer;
        bool Colliding;
        SpriteAnimation Henry;
		ScrollingBackGround background;
		SpriteText AMessage;
        MusicSound BackGroundMusic;
        HHREnemy anEnemy;
        HHRShootingEnemy aShootingEnemy;
        AI_Manager<HHREnemy> BasicEnemy;

};

#endif // GAMELEVEL1_H
