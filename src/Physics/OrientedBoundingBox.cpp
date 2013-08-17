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

#include "OrientedBoundingBox.h"



namespace HHR_Physics
{



    Vector3 OrientedBoundingBox::GetXAxis()
    {

        real cosineTheta = real_cos(Orientation.x);
        real sineTheta   = real_sin(Orientation.x);

        return Vector3(this->position.x,
                      (this->position.y * cosineTheta)+(this->position.z * (-1 *sineTheta)),
                      (this->position.y * sineTheta)+(this->position.z * cosineTheta));

    }
    Vector3 OrientedBoundingBox::GetYAxis()
    {

        real cosineTheta = real_cos(Orientation.y);
        real sineTheta   = real_sin(Orientation.y);

        return Vector3((this->position.x*cosineTheta) + (this->position.z * sineTheta),
                       this->position.y,
                       (this->position.x *(-1*sineTheta) + (this->position.z * cosineTheta)));

    }
    Vector3 OrientedBoundingBox::GetZAxis()
    {

        real cosineTheta = real_cos(Orientation.z);
        real sineTheta   = real_sin(Orientation.z);

        return Vector3((this->position.x * cosineTheta) + (this->position.y *(-1*sineTheta)),
                       (this->position.x * sineTheta) + (this->position.y*cosineTheta),
                        this->position.z);

    }

}
