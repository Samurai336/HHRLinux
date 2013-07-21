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


#ifndef VECTOR3_H
#define VECTOR3_H

#include "precision.h"


namespace HHR_Physics
{

    class Vector3
    {
        public:

            real x;

            real y;

            real z;


        private:
            real pad;

        public:
            Vector3():x(0),y(0), z(0){}

            Vector3(const real x, const real y, const real z):
             x(x), y(y), z(z) {}

            void invert();

            real Magnatude() const;

            real SquareMagnatude() const;

            real* GetXYZAsArray();

            void Normalize();

            Vector3 AddScaledVector(const Vector3 &vec, real scale);

            Vector3 ComponentProduct(const Vector3 &vec) const;

            void ComponentProductUpdate(const Vector3 &vec);

            real ScalerProduct(const Vector3 &vec) const ;

            Vector3 VectorProduct(const Vector3 &vec) const;

            void MakeOthonormalBasis(Vector3 *a, Vector3 *b, Vector3 *c);

            void operator%=(const Vector3 &vec);

            Vector3 operator%(const Vector3 &vec)const;

            void operator*=(const real value);

            Vector3 operator*(const real value);

            void operator+=(const Vector3 &v);

            Vector3 operator+(const Vector3 &v);

            void operator-=(const Vector3 &v);

            Vector3 operator-(const Vector3 &v) const;

            real operator*(const Vector3 &vec) const ;

            ~Vector3();


    };
}
#endif // VECTOR3_H
