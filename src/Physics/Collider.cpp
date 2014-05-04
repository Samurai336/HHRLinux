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
#include "../MainApp.h"

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

        real dmin = 0.0;

        if(SP.position.x < BB.Mininmum(X))
        {
            dmin += ((SP.position.x - BB.Mininmum(X))*(SP.position.x - BB.Mininmum(X))) ;
        }
        else if (SP.position.x > BB.Mininmum(X))
        {
            dmin += ((SP.position.x - BB.Mininmum(X))*(SP.position.x - BB.Maximum(X))) ;
        }

        if(SP.position.x < BB.Mininmum(X))
        {
            dmin += ((SP.position.x - BB.Mininmum(X))*(SP.position.x - BB.Mininmum(X))) ;
        }
        else if (SP.position.x > BB.Mininmum(X))
        {
            dmin += ((SP.position.x - BB.Mininmum(X))*(SP.position.x - BB.Maximum(X))) ;
        }

        if(SP.position.y < BB.Mininmum(Y))
        {
            dmin += ((SP.position.y - BB.Mininmum(Y))*(SP.position.y - BB.Mininmum(Y))) ;
        }
        else if (SP.position.y > BB.Mininmum(Y))
        {
            dmin += ((SP.position.y - BB.Mininmum(Y))*(SP.position.y - BB.Maximum(Y))) ;
        }

        if(SP.position.z < BB.Mininmum(Z))
        {
            dmin += ((SP.position.z - BB.Mininmum(Z))*(SP.position.z - BB.Mininmum(Z))) ;
        }
        else if (SP.position.z > BB.Mininmum(Z))
        {
            dmin += ((SP.position.z - BB.Mininmum(Z))*(SP.position.z - BB.Maximum(Z))) ;
        }


          return dmin <= (SP.radious*SP.radious);

    }

    bool Collider::Check(const Sphere &SP, const BoundingBox &BB)
    {
        return Check(BB,SP);
    }

    bool Collider::Check(const OrientedBoundingBox &A, const OrientedBoundingBox &B)
    {
       real ra, rb;

       Matrix33 R, AbsR;


       for(int i= 0; i<3; ++i)
       {
            for(int j= 0; j<3; ++j)
            {
                R[i][j] = (A.u[i] * B.u[j]);
            }
       }

       Vector3 t = B.position - A.position;

       t = Vector3((t * A.u[0]),(t * A.u[1]),(t * A.u[2]));

       for(int i= 0; i<3; ++i)
       {
            for(int j= 0; j<3; ++j)
            {
                AbsR[i][j] = real_abs(R[i][j]) + REAL_EPSILON;
            }
       }

       for (int i = 0; i < 3; i++)
       {
           ra = A.extension[i];
           rb = B.extension[0] * AbsR[i][0] + B.extension[1] * AbsR[i][1] + B.extension[2]* AbsR[i][2];

           if(real_abs(t[i]) > ra + rb)
           {
               return false;
           }
       }

       for (int i = 0; i < 3; i++)
       {
           ra = A.extension[0] * AbsR[0][i] +  A.extension[1] * AbsR[1][i] +  A.extension[2] * AbsR[2][i]  ;
           rb = B.extension[i];

           if(real_abs(t[0]*R[0][i]+t[1]*R[1][i]+t[2]*R[2][i]) > ra + rb)
           {
               return false;
           }
       }


       ra = A.extension[1] * AbsR[2][0] + A.extension[2] * AbsR[1][0];
       rb = B.extension[1] * AbsR[0][2] + B.extension[2] * AbsR[0][1];
       if(real_abs(t[2] * R[1][0] - t[1] * R[2][0]) > ra + rb)
       {
           return false;
       }

       ra = A.extension[1] * AbsR[2][1] + A.extension[2] * AbsR[1][1];
       rb = B.extension[0] * AbsR[0][2] + B.extension[2] * AbsR[0][0];
       if(real_abs(t[2] * R[1][1] - t[1] * R[2][1]) > ra + rb)
       {
           return false;
       }

       ra = A.extension[1] * AbsR[2][2] + A.extension[2] * AbsR[1][2];
       rb = B.extension[0] * AbsR[0][1] + B.extension[1] * AbsR[0][0];
       if(real_abs(t[2] * R[1][2] - t[1] * R[2][2]) > ra + rb)
       {
           return false;
       }

       ra = A.extension[0] * AbsR[2][0] + A.extension[2] * AbsR[0][0];
       rb = B.extension[1] * AbsR[1][2] + B.extension[2] * AbsR[1][1];
       if (real_abs(t[0] * R[2][0] - t[2] * R[0][0]) > ra + rb)
       {
           return false;
       }

       ra = A.extension[0] * AbsR[2][1] + A.extension[2] * AbsR[0][1];
       rb = B.extension[0] * AbsR[1][2] + B.extension[2] * AbsR[1][0];
       if(real_abs(t[0] * R[2][1] - t[2] * R[0][1]) > ra + rb)
       {
           return false;
       }


       ra = A.extension[0] * AbsR[2][2] + A.extension[2] * AbsR[0][2];
       rb = B.extension[0] * AbsR[1][1] + B.extension[1] * AbsR[1][0];
       if(real_abs(t[0] * R[2][2] - t[2] * R[0][2]) > ra + rb)
       {
           return false;
       }

       ra = A.extension[0] * AbsR[1][0] + A.extension[1] * AbsR[0][0];
       rb = B.extension[1] * AbsR[2][2] + B.extension[2] * AbsR[2][1];
       if (real_abs(t[1] * R[0][0] - t[0] * R[1][0]) > ra + rb)
       {
           return false;
       }

       ra = A.extension[0] * AbsR[1][1] + A.extension[1] * AbsR[0][1];
       rb = B.extension[0] * AbsR[2][2] + B.extension[2] * AbsR[2][0];
       if(real_abs(t[1] * R[0][1] - t[0] * R[1][1]) > ra + rb)
       {
           return false;
       }


       ra = A.extension[0] * AbsR[1][2] + A.extension[1] * AbsR[0][2];
       rb = B.extension[0] * AbsR[2][1] + B.extension[1] * AbsR[2][0];
       if(real_abs(t[1] * R[0][2] - t[0] * R[1][2]) > ra + rb)
       {
           return false;
       }

       return true;

    }

    bool Collider::Check(const OrientedBoundingBox2D &A, const OrientedBoundingBox2D &B)
    {
        real distence =  Vector3::Distence(A.GetPositon(), B.GetPositon()) / 2.0f ;

        if(distence > (B.GetWidth()) || distence > (B.GetHeight()) || distence > A.GetWidth()|| distence > A.GetHeight())
        {
            return false;
        }

        return Oriented2DBBCheck(A,B) && Oriented2DBBCheck(B,A);

    }

    bool Collider::Check(const OrientedBoundingBox2D &OBB2D, const BoundingBox &BB)
    {

        real distence =  Vector3::Distence(OBB2D.GetPositon(), BB.position) / 2.0f;

        if(distence > (BB.extension.x*4) || distence > (BB.extension.y*4) || distence > OBB2D.GetWidth()*2|| distence > OBB2D.GetHeight()*2)
        {
            return false;
        }


        OrientedBoundingBox2D tempBB(BB.position, BB.extension.x*2,BB.extension.y*2, 0.0f);

        return Oriented2DBBCheck((OBB2D),(tempBB)) && Oriented2DBBCheck((tempBB),(OBB2D)) ;
    }

    bool Collider::Check(const BoundingBox &BB, const OrientedBoundingBox2D &OBB2D)
    {
        return Check(OBB2D,BB);
    }


    bool Collider::Check(const OrientedBoundingBox2D &OBB2D, const Sphere &SP)
    {

        Vector3 pt = OBB2D.ClosestPoint(SP.position);

        Vector3 v = pt - SP.position;


        return v.DotProduct(v) <= SP.radious*SP.radious;
    }

    bool Collider::Check(const Sphere &SP, const OrientedBoundingBox2D &OBB2D)
    {
        return Check(OBB2D, SP);
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
