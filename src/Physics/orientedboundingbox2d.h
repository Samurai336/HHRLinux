#ifndef ORIENTEDBOUNDINGBOX2D_H
#define ORIENTEDBOUNDINGBOX2D_H



#include "Vector3.h"
#include "Collider.h"
#include "collisionobject.h"
#include "../Renderer/MainRender.h"


namespace HHR_Physics
{

    class OrientedBoundingBox2D:public CollisionObject
    {
        friend class Collider;

        public:
            OrientedBoundingBox2D(const Vector3& center, const real w, const real h, real angle);
            OrientedBoundingBox2D(){}

            void SetUpBox(const Vector3& center, const real w, const real h, real angle);

            void moveTo(const Vector3 &center,real angle);

            Vector3 GetPositon() const;
            real GetWidth() const;
            real GetHeight() const;

            void OnRender(MainRender	&theRenderer, bool isColliding = false);

            Vector3 ClosestPoint(const Vector3 &point) const;
            
       private:
            Vector3 corner[4]; 
            Vector3 axis[2];             
            real    origin[2]; 

            Vector3 Positon;
            


            void computeAxes();

            real width,height;
    };

}

#endif // ORIENTEDBOUNDINGBOX2D_H
