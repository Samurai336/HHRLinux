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

#ifndef COLLIDER_H
#define COLLIDER_H


#include "CollisionObjects.h"



namespace HHR_Physics
{

    class OrientedBoundingBox2D;

    class Collider
    {
        public:
            Collider();
            static bool Check(const BoundingBox &A, const BoundingBox &B) ;
            static bool Check(const Sphere &A, const Sphere &B);            
            static bool Check(const OrientedBoundingBox &A, const OrientedBoundingBox &B) ;
            static bool Check(const OrientedBoundingBox2D &A, const OrientedBoundingBox2D &B) ;

            static bool Check(const OrientedBoundingBox2D &OBB2D, const BoundingBox &BB) ;
            static bool Check(const BoundingBox &BB,const OrientedBoundingBox2D &OBB2D) ;

            static bool Check(const BoundingBox &BB, const Sphere &SP);
            static bool Check(const Sphere &SP, const BoundingBox &BB);

            static bool Check(const OrientedBoundingBox2D &OBB2D, const Sphere &SP) ;
            static bool Check(const Sphere &SP, const OrientedBoundingBox2D &OBB2D) ;


        private:
            static bool Oriented2DBBCheck(const OrientedBoundingBox2D &A, const OrientedBoundingBox2D &B) ;

    };


}

#endif // COLLIDER_H
