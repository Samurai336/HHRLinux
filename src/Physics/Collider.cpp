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

    bool Collider::Check(const BoundingBox &A, const Sphere &B)
    {
        /*
        real *
        */
    }


}
