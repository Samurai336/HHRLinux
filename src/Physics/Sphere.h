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

#ifndef SPHERE_H
#define SPHERE_H

#include "Vector3.h"
#include "collisionobject.h"
#include "../Renderer/MainRender.h"


namespace HHR_Physics
{
    class Sphere: public CollisionObject
    {
        public:
            Vector3 position;
            real radious;

        public:
            Sphere(){}
            Sphere(Vector3 &pos, real rad):
                position(pos), radious(rad){}


            void SetSphere(Vector3 &pos, real rad);

            void MoveTo(const Vector3 &center);

            void OnRender(MainRender	&theRenderer, bool isColliding = false);

            ~Sphere();
        protected:
        private:
    };
}
#endif // SPHERE_H
