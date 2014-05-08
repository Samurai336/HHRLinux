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


    OrientedBoundingBox::OrientedBoundingBox(Vector3 &Pos, Vector3 &Ext, Vector3 &Orent):
    BoundingBox(Pos,Ext), Orientation(Orent)
    {

    }

    void OrientedBoundingBox::SetUpOBB(Vector3 &Pos, Vector3 &Ext, Vector3 &Orent)
    {
        SetUpBB(Pos,Ext);

        Orientation = Orent;

    }

    Vector3 OrientedBoundingBox::GetOrientation() const
    {
        return Orientation;
    }

    void OrientedBoundingBox::setPostion(Vector3 &NewPositon, Vector3 &newOrientation)
    {
        BoundingBox::setPostion(NewPositon);

        Orientation = newOrientation;

        UpDateAxis();
    }

    void OrientedBoundingBox::OnRender(MainRender &theRenderer, bool isColliding)
    {
#ifdef PHYSICS_DEBUG
        Vector3 corner[4];

        //Vector3 vX( real_cos(DEGREES_TO_RADIANS(Orientation.z)), real_sin(DEGREES_TO_RADIANS(Orientation.z)), position.z);
        //Vector3 vY(-real_sin(DEGREES_TO_RADIANS(Orientation.z)), real_cos(DEGREES_TO_RADIANS(Orientation.z)), position.z);





        Vector3 vZ = u[2]; // * extension.x;
        Vector3 vX = u[0]; //* extension.y;
        Vector3 vY = u[1]; //* extension.y;


        corner[0] = ((position) + vZ - vY);
        corner[1] = ((position) - vZ - vY);
        corner[2] = ((position) - vZ + vY);
        corner[3] = ((position) + vZ + vY);

        //Vector3 Translation(halfWidth,halfHeight,position.z);


        /*

        corner[0] = vZ;

         corner[0] += position;

       // corner[0].y = vX.y;
        corner[1] = vZ;
        corner[1] += position;
        //corner[1].y = vX.y;

        corner[1].x -= (extension.x*2);
        */





                //(extension + vX-vY);//+Translation;
        //corner[2] = (extension + vX+vY);//+Translation;
        //corner[3] = (extension - vX+vY);//+Translation;


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

        theRenderer.DrawLine((int)corner[0].x, (int)corner[0].y, (int)corner[1].x, (int)corner[1].y, Player1Color);
        theRenderer.DrawLine((int)corner[0].x, (int)corner[0].y, (int)corner[3].x, (int)corner[3].y, Player1Color);
        theRenderer.DrawLine((int)corner[1].x, (int)corner[1].y, (int)corner[2].x, (int)corner[2].y, Player1Color);
        theRenderer.DrawLine((int)corner[2].x, (int)corner[2].y, (int)corner[3].x, (int)corner[3].y, Player1Color);


#endif

    }

    void OrientedBoundingBox::CalculateXAxis()
    {

        real cosineTheta = real_cos( DEGREES_TO_RADIANS(Orientation.z));
        real sineTheta   = real_sin(DEGREES_TO_RADIANS(Orientation.z));

        u[0]= Vector3(this->extension.x,
                      (this->extension.y * cosineTheta)+(this->extension.z * (-1 *sineTheta)),
                      (this->extension.y * sineTheta)+(this->extension.z * cosineTheta));


    }
    void OrientedBoundingBox::CalculateYAxis()
    {

        real cosineTheta = real_cos(DEGREES_TO_RADIANS(Orientation.z));
        real sineTheta   = real_sin(DEGREES_TO_RADIANS(Orientation.z));

        u[1] = Vector3((this->extension.x*cosineTheta) + (this->extension.z * sineTheta),
                       this->extension.y,
                       (this->extension.x *(-1*sineTheta) + (this->extension.z * cosineTheta)));

    }
    void OrientedBoundingBox::CalculateZAxis()
    {

        real cosineTheta = real_cos(DEGREES_TO_RADIANS(Orientation.z));
        real sineTheta   = real_sin(DEGREES_TO_RADIANS(Orientation.z));

        u[2] =  Vector3((this->extension.x * cosineTheta) + (this->extension.y *(-1*sineTheta)),
                       (this->extension.x * sineTheta) + (this->extension.y*cosineTheta),
                        this->extension.z);

    }

    void OrientedBoundingBox::UpDateAxis()
    {
        CalculateXAxis();
        CalculateYAxis();
        CalculateZAxis();
    }

}
