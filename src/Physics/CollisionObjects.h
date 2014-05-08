#ifndef COLLISIONOBJECTS_H
#define COLLISIONOBJECTS_H


#include "Vector3.h"
#include "../Renderer/MainRender.h"

namespace HHR_Physics
{

    class CollisionObject
    {
    public:
        CollisionObject(void);
    };

    class BoundingBox: public CollisionObject
    {

        friend class Collider;

        public:
            BoundingBox(){}
            BoundingBox(Vector3 Pos, Vector3 Ext):
            position(Pos), extension(Ext) {}

            void SetUpBB(Vector3 &Pos, Vector3 &Ext);

            void SetSize(Vector3 &newSize);

            real Mininmum(const XYZ i) const;

            real Maximum(const XYZ i) const;

            void setPostion(Vector3 &NewPositon);

            void OnRender(MainRender	&theRenderer, bool isColliding = false);



            ~BoundingBox();


        protected:
            Vector3 position;
            Vector3 extension;
        private:
    };

    class OrientedBoundingBox : public BoundingBox
    {
        friend class Collider;

    public:
        OrientedBoundingBox(){}


            OrientedBoundingBox(Vector3 &Pos, Vector3 &Ext, Vector3 &Orent);

            void SetUpOBB(Vector3 &Pos, Vector3 &Ext, Vector3 &Orent);

            Vector3 GetOrientation() const;

            void setPostion(Vector3 &NewPositon, Vector3 &newOrientation);

            void OnRender(MainRender	&theRenderer, bool isColliding = false);


            ~OrientedBoundingBox(){}

        private:
            void CalculateXAxis();
            void CalculateYAxis();
            void CalculateZAxis();
            void UpDateAxis();

        protected:
            Vector3 Orientation;
            Vector3 u[3];
    };



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

            Vector3 ClosestPoint(const Vector3 &point)const;

       private:
            Vector3 corner[4];
            Vector3 axis[2];
            Vector3 localAxis[2];
            real    origin[2];
            real    extends[2];


            Vector3 Positon;



            void computeAxes();

            real width,height;
    };


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




#endif // COLLISIONOBJECTS_H



