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

#include "BaseUnit.h"

//This is here due to circulalr dependency issue.
#include "../MainApp.h"



BaseUnit::BaseUnit(void)
{

    Position.x = Position.y = 0.0f;
    Position.z = 1.0f;
	unitTexture = NULL;
	rotation = 0.0;
	renderOrder = 1;
	width = 0;
	height =0;
    Scale = 1.0f;

}


BaseUnit::~BaseUnit(void)
{

}


bool BaseUnit::Load(char* File)
{
	 if((unitTexture = MainApp::Instance()->GetMainRenderTarget()->LoadTexture(File)) == NULL)
     {
#ifdef DEBUG_MODE
                 printf("IMG_Load Error: Unit Asset(%s): %s\n",File, IMG_GetError());
#endif
         return true;
     }

     SDL_QueryTexture(unitTexture, NULL, NULL, &width, &height);

     return false;
}


void BaseUnit::OnLoop()
{

}

void BaseUnit::OnRender(MainRender	&theRenderer)
{

    theRenderer.Draw(unitTexture, Position.x, Position.y, rotation, Scale);
    //theRenderer.Draw(unitTexture, Position.x, Position.y,Position.x, Position.y,width,height, rotation, Size);
}

void BaseUnit::OnCleanup()
{
	 if(unitTexture)
	 {
        SDL_DestroyTexture(unitTexture);
	 }

    unitTexture = NULL;
}

void BaseUnit::SetPosition(const float MoveX, const float MoveY)
{
    Position.x = MoveX - (width/2);
    Position.y = MoveY - (height/2);
}

void BaseUnit::SetPosition(const HHR_Physics::Vector3 &newPosition)
{
    Position = newPosition;
    Position.x -= (width/2);
    Position.y -= (height/2);
}

void BaseUnit::SetScale(const float newScale)
{
    Scale = newScale;
}

float BaseUnit::GetScale()
{
    return Scale;
}
