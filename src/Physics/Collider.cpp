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

#include "Collider.h"


namespace HHR_Physics
{
    Collider::Collider()
    {
        //ctor
    }

    bool Collider::Check(const BoundingBox &A, const BoundingBox &B)
    {
        const Vector3 T = B.position - A.position;

        return(
                real_abs(T.x) <= (A.extension.x + B.extension.x)
                &&
                real_abs(T.y) <= (A.extension.y + B.extension.y)
                &&
                real_abs(T.y) <= (A.extension.z + B.extension.z)
              );


    }

    bool Collider::Check(const Sphere &A, const Sphere &B)
    {
        Vector3 reletivePosition = A.position - B.position;
        real minDistance = A.radious + B.radious;
        return  (0  > ((reletivePosition.x * reletivePosition.x  + reletivePosition.y * reletivePosition.y + reletivePosition.z*reletivePosition.z) - (minDistance*minDistance)));


    }

    bool Collider::Check(const BoundingBox &BB,  const Sphere &SP)
    {
        real s,d = 0;
        real *CollisionAsArray = SP.position.GetXYZAsArray();

        for(int i=0; i < 3; ++i)
        {

            if(CollisionAsArray[i] < BB.Mininmum(XYZ(i)))
            {
                s = CollisionAsArray[i] - BB.Mininmum(XYZ(i));
                d += s*s ;
            }
            else if(CollisionAsArray[i] < BB.Mininmum(XYZ(i)))
            {

                s = CollisionAsArray[i] - BB.Maximum(XYZ(i));
                d += s*s ;

            }
        }

        return (d <= SP.radious);

    }

    bool Collider::Check(const OrientedBoundingBox &A, const OrientedBoundingBox &B)
    {

       return true;

    }

    bool Collider::Check(const OrientedBoundingBox2D &A, const OrientedBoundingBox2D &B)
    {

           return Oriented2DBBCheck(A,B) && Oriented2DBBCheck(B,A);

    }

    bool Collider::Oriented2DBBCheck(const OrientedBoundingBox2D &A, const OrientedBoundingBox2D &B)
    {
        for(int a = 0; a<2; ++a)
        {
            real t = A.corner[a].DotProduct(B.axis[a]);

            real tMin = t;
            real tMax = t;

            for (int c = 1; c <4; ++c)
            {
                t = A.corner[c].DotProduct(B.axis[a]);

                if (t< tMin)
                {
                    tMin = t;
                }
                else if(t> tMax)
                {
                    tMax = t;
                }

            }

            if((tMin > 1 + B.origin[a]) ||(tMax< B.origin[a]))
            {
                return false;
            }
        }

        return true;
    }


}
