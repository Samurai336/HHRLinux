#ifndef BOUNCECIRCLE_H
#define BOUNCECIRCLE_H

#include "BounceSquare.h"
#include "Particles/CannonSmokeParticleSystem.h"

class BounceCircle : public BounceSquare
{
    public:
        BounceCircle();

        bool Load(char* File);

        void OnLoop();

        void OnRender(MainRender &theRenderer);

        void OnCleanup();

        HHR_Physics::Sphere GetCollisionObject();

        void setRotationSpeed(float newSpeed);

    protected:
        virtual void UpdateCollisionObj();


    private:
        HHR_Physics::Sphere CollisionSphere;
        HHR_Particles::CannonSmokeParticleSystem Smoke;

        float rotationSpeed;

};

#endif // BOUNCECIRCLE_H
