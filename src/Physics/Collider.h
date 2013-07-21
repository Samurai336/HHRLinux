#ifndef COLLIDER_H
#define COLLIDER_H


#include "BoundingBox.h"
#include "Sphere.h"

namespace HHR_Physics
{

    class Collider
    {
        public:
            Collider();
            static bool Check(const BoundingBox &A, const BoundingBox &B) ;
            static bool Check(const Sphere &A, const Sphere &B);
            static bool Check(const BoundingBox &A, const Sphere &B);


        private:
    };


}

#endif // COLLIDER_H
