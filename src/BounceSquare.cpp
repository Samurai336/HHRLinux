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

#include "BounceSquare.h"


BounceSquare::BounceSquare(void)
{
    BaseUnit();


    speedX	= speedY = roataitonSpeed = 0.0f;


}

bool BounceSquare::Load(char* File)
{
    bool loadStatus = BaseUnit::Load(File);

    orientedCollisionBox.SetUpBox(Position, width,height, rotation);

    return loadStatus;

}

void BounceSquare::setSpeed(float xSpeed, float ySpeed)
{
	speedX = xSpeed;
    speedY = ySpeed;
}

void BounceSquare::setRotationSpeed(float newSpeed)
{
    roataitonSpeed = newSpeed;
}


void BounceSquare::OnLoop()
{

    if( Position.x < 0 || (Position.x+width) > WWIDTH)
	{
		speedX *= -1;
	}

    if(Position.y < 0 || (Position.y+height) > WHEIGHT)
	{
		speedY *= -1;
	}

    rotation += roataitonSpeed;

    Position.x += speedX;
    Position.y += speedY;

    orientedCollisionBox.moveTo(Position,rotation);
}

HHR_Physics::OrientedBoundingBox2D *BounceSquare::GetCollisionObject()
{

    return &orientedCollisionBox;
}



void BounceSquare::OnRender(MainRender	&theRenderer)
{
    BaseUnit::OnRender(theRenderer);

}

void BounceSquare::OnCleanup()
{

}


BounceSquare::~BounceSquare(void)
{
}
