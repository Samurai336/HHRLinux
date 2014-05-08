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

#include "CollisionObjects.h"

namespace HHR_Physics
{

void Sphere::SetSphere(Vector3 &pos, real rad)
{
    position = pos;
    radious = rad;
}

void Sphere::MoveTo(const Vector3 &center)
{
    Vector3 Translation(center.x + (radious),center.y + (radious) ,center.z);

    position= Translation;
}

void Sphere::OnRender(MainRender &theRenderer, bool isColliding)
{
#ifdef PHYSICS_DEBUG
        SDL_Color Player1Color;
        SDL_Color CollidingColor = {255,255,0,255};
        SDL_Color NotCollidingColor = {255,0,0,255};

        if(isColliding)
        {
            Player1Color = CollidingColor;
        }
        else
        {
            Player1Color = NotCollidingColor;
        }
    theRenderer.DrawCircle(position.x,position.y, radious, Player1Color);

#endif
}

Sphere::~Sphere()
    {
        //dtor
    }
}
