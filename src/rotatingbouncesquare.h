#ifndef ROTATINGBOUNCESQUARE_H
#define ROTATINGBOUNCESQUARE_H


#include "BounceSquare.h"
#include "Physics/CollisionObjects.h"

class RotatingBounceSquare : public BounceSquare
{
    public:
        RotatingBounceSquare();

        bool Load(char* File);

        void OnLoop();

        HHR_Physics::OrientedBoundingBox2D GetCollisionObject();

        void setRotationSpeed(float newSpeed);



    protected:
        virtual void UpdateCollisionObj();


    private:
        HHR_Physics::OrientedBoundingBox2D orientedCollisionBox;

        float rotationSpeed;
};

#endif // ROTATINGBOUNCESQUARE_H
