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


#include "BoundingBox.h"


namespace HHR_Physics
{

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

    BoundingBox::~BoundingBox()
    {
        //dtor
    }

}
