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

void BoundingBox::SetUpBB(Vector3 &Pos, Vector3 &Ext)
{
    position = Pos;
    extension = Ext;
}

void BoundingBox::SetSize(Vector3 &newSize)
{
    extension = (newSize/2);
}

real BoundingBox::Mininmum(const XYZ i) const
    {
        switch(i)
        {
            case(X):
                return (this->position.x - this->extension.x);
                break;
            case(Y):
                return (this->position.y - this->extension.y);
                break;
            case(Z):
                return (this->position.z - this->extension.z);
                break;
            default:
                return 0;
                break;
        }

    }

    real BoundingBox::Maximum(const XYZ i) const
    {
        switch(i)
        {
            case(X):
                return (this->position.x + this->extension.x);
                break;
            case(Y):
                return (this->position.y + this->extension.y);
                break;
            case(Z):
                return (this->position.z + this->extension.z);
                break;
            default:
                return 0;
                break;
        }
    }

    real BoundingBox::GetWidth() const
    {

        return this->extension.x;
    }

    real BoundingBox::GetHeight() const
    {
        return this->extension.y;
    }

    void BoundingBox::setPostion(Vector3 &NewPositon)
    {
        position = NewPositon;
    }

    void BoundingBox::OnRender(MainRender &theRenderer, bool isColliding)
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

        theRenderer.DrawLine(Mininmum(X),Mininmum(Y),Mininmum(X),Maximum(Y), Player1Color); // uper right to down

        theRenderer.DrawLine(Mininmum(X),Mininmum(Y),Maximum(X),Mininmum(Y), Player1Color); //upper right to left

        theRenderer.DrawLine(Maximum(X),Mininmum(Y),Maximum(X), Maximum(Y), Player1Color);

        theRenderer.DrawLine(Mininmum(X),Maximum(Y),Maximum(X), Maximum(Y), Player1Color);

#endif
    }

    BoundingBox::~BoundingBox()
    {
        //dtor
    }

}

