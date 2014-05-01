#include "rotatingbouncesquare.h"

RotatingBounceSquare::RotatingBounceSquare()
{
    BounceSquare();

    rotation = 0.0f;
    rotationSpeed = 0.0f;


}

bool RotatingBounceSquare::Load(char *File)
{
      bool loadStatus = BaseUnit::Load(File);


      HHR_Physics::Vector3 extenshion(width,height,10.0f);
      //HHR_Physics::Vector3 vRotation(0.0f, 0.0f, rotation);
      orientedCollisionBox.SetUpBox(Position, width, height,  rotation);

      return loadStatus;
}

void RotatingBounceSquare::OnLoop()
{

    rotation += rotationSpeed;
    BounceSquare::OnLoop();


}

HHR_Physics::OrientedBoundingBox2D RotatingBounceSquare::GetCollisionObject()
{
    return orientedCollisionBox;
}

void RotatingBounceSquare::UpdateCollisionObj()
{
    //HHR_Physics::Vector3 vRotation(0.0f ,0.0, rotation);
    orientedCollisionBox.moveTo(Position,rotation);
}

void RotatingBounceSquare::setRotationSpeed(float newSpeed)
{
    rotationSpeed = newSpeed;
}

