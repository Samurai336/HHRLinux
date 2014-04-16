#include "BounceCircle.h"

BounceCircle::BounceCircle()
{
    BounceSquare();

    rotation = 0.0f;
    rotationSpeed = 0.0f;
}

bool BounceCircle::Load(char *File)
{
     bool loadStatus = BaseUnit::Load(File);

     CollisionSphere.SetSphere(Position,width/2);

     return loadStatus;
}

void BounceCircle::OnLoop()
{
    rotation += rotationSpeed;
    BounceSquare::OnLoop();
}

HHR_Physics::Sphere BounceCircle::GetCollisionObject()
{
    return CollisionSphere;
}

void BounceCircle::setRotationSpeed(float newSpeed)
{
    rotationSpeed = newSpeed;
}

void BounceCircle::UpdateCollisionObj()
{
    CollisionSphere.MoveTo(Position);
}


