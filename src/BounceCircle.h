#ifndef BOUNCECIRCLE_H
#define BOUNCECIRCLE_H

#include "BounceSquare.h"

class BounceCircle : public BounceSquare
{
    public:
        BounceCircle();

        bool Load(char* File);

        void OnLoop();

        HHR_Physics::Sphere GetCollisionObject();

        void setRotationSpeed(float newSpeed);

    protected:
        virtual void UpdateCollisionObj();


    private:
        HHR_Physics::Sphere CollisionSphere;

        float rotationSpeed;

};

#endif // BOUNCECIRCLE_H
