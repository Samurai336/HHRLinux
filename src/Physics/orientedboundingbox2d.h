#ifndef ORIENTEDBOUNDINGBOX2D_H
#define ORIENTEDBOUNDINGBOX2D_H



#include "Vector3.h"

namespace HHR_Physics
{

    class OrientedBoundingBox2D
    {
        public:
            OrientedBoundingBox2D(const Vector3& center, const real w, const real h, real angle);

            void moveTo(const Vector3& center);

            bool overlaps(const OrientedBoundingBox2D &other) const;
            
       private:
            Vector3 corner[4]; 
            Vector3 axis[2]; 
            
            real    origin[2]; 
            
            bool overlaps1Way(const OrientedBoundingBox2D& other) const;

            void computeAxes();
    };

}

#endif // ORIENTEDBOUNDINGBOX2D_H
