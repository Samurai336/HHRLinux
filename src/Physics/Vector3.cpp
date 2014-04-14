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



#include "Vector3.h"


namespace HHR_Physics
{

    void Vector3::invert()
    {

        x = -x;
        y = -y;
        z = -z;

    }

    real Vector3::Magnatude() const
    {
        return real_sqrt(x*x+y*y+z*z);
    }

    real Vector3::SquareMagnatude() const
    {
        return (x*x + y*y + z*z);
    }

    void Vector3::Normalize()
    {

        real l = Magnatude();

        if(l>0)
        {
            (*this) *= ((real)l)/l;
        }

    }

    void Vector3::operator*=(const real value)
    {
        x *= value;
        y *= value;
        z *= value;
    }

    Vector3 Vector3::operator*(const real value)
    {

        return Vector3(x*value, y*value, z*value);

    }

    Vector3 Vector3::operator/(const real value)
    {
        return Vector3(x/value, y/value, z/value);
    }

    Vector3 Vector3::operator/=(const real value)
    {
        x /= value;
        y /= value;
        z /= value;
    }

    void Vector3::operator+=(const Vector3 &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;

    }

    Vector3 Vector3::operator+(const Vector3 &v)const
    {
        return (Vector3(x+v.x,y+v.y, z+v.z));
    }

    void Vector3::operator-=(const Vector3 &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;

    }

    Vector3 Vector3::operator-(const Vector3 &v) const
    {
        return (Vector3(x-v.x,y-v.y,z-v.z));
    }

    void Vector3::AddScaledVector(const Vector3 &vec, real scale)
    {
        x += vec.x * scale;
        y += vec.y * scale;
        z += vec.z * scale;
    }

    Vector3 Vector3::ComponentProduct(const Vector3 &vec) const
    {

        return Vector3(x * vec.x, y * vec.y, z* vec.z);
    }

    void Vector3::ComponentProductUpdate(const Vector3 &vec)
    {
        x *= vec.x;
        y *= vec.y;
        z *= vec.z;

    }


    real Vector3::ScalerProduct(const Vector3 &vec) const
    {
        return x*vec.x + y*vec.y + z*vec.z;

    }

    real Vector3::DotProduct(const Vector3 &vec) const
    {
        return ScalerProduct(vec);
    }

    real Vector3::operator*(const Vector3 &vec) const
    {
        return x*vec.x + y*vec.y + z*vec.z;

    }

    Vector3 Vector3::VectorProduct(const Vector3 &vec) const
    {
        return Vector3(y*vec.z - z * vec.y,
                       z*vec.x - x * vec.z,
                       x*vec.x - y * vec.x);

    }

    void Vector3::operator%=(const Vector3 &vec)
    {
        *this = VectorProduct(vec);
    }

    Vector3 Vector3::operator%(const Vector3 &vec)const
    {
        return Vector3(y*vec.z - z * vec.y,
                       z*vec.x - x * vec.z,
                       x*vec.x - y * vec.x);

    }

     Vector3 Vector3::operator=(const Vector3 &vec)
    {         
         x = vec.x;
         y = vec.y;
         z = vec.z;

        return Vector3(x,y,z);

     }

     real Vector3::Distence(const Vector3 &vec1, const Vector3 &vec2)
     {
         return real_sqrt( ((vec1.x - vec2.x )*(vec1.x - vec2.x )) + ((vec1.y - vec2.y)*(vec1.y - vec2.y))+((vec1.z - vec2.z)*(vec1.z - vec2.z)));
     }

    void Vector3::MakeOthonormalBasis(Vector3 *a, Vector3 *b, Vector3 *c)
    {
        a->Normalize();
        (*c) = (*a) % (*b);

        if(c->SquareMagnatude() == 0.0 )
        {
            return;
        }

        c->Normalize();

        (*b) = (*c) % (*a);

    }

    real* Vector3::GetXYZAsArray() const
    {
         static real xyzAsArray[3];

         xyzAsArray[0] = x;
         xyzAsArray[1] = y;
         xyzAsArray[2] = z;

         return xyzAsArray;
    }

    Vector3::~Vector3()
    {
        //dtor
    }

}
