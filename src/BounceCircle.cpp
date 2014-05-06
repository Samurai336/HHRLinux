#include "BounceCircle.h"
#include "MainApp.h"

BounceCircle::BounceCircle()
{
    BounceSquare();

    rotation = 0.0f;
    rotationSpeed = 0.0f;
    Scale = 0.5f;
}

bool BounceCircle::Load(char *File)
{
     bool loadStatus = BaseUnit::Load(File);

     CollisionSphere.SetSphere(Position,width/2);

     const char *ParticleAsset[] ={"Assets/cannonSmoke.png"} ;

     if(!loadStatus)
     {
         loadStatus = Smoke.SetUpEngine(ParticleAsset,1,HHR_Physics::Vector3(0.0f,0.0f,1.0f),10, 100, 500);
     }

     Smoke.SetActive(true);

     return loadStatus;
}

void BounceCircle::OnLoop()
{
    rotation += rotationSpeed;


    if(speedX < 0)
    {
        Smoke.StartCannonSmoke(HHR_Particles::Right, Position, HHR_Physics::Vector3(speedX, speedY, 0.0f));
    }
    else
    {
        Smoke.StartCannonSmoke(HHR_Particles::Left, Position, HHR_Physics::Vector3(speedX, speedY, 0.0f));
    }


    //Smoke.SetPositon(Position);

    Smoke.OnLoop();

    BounceSquare::OnLoop();
}

void BounceCircle::OnRender(MainRender &theRenderer)
{

    BounceSquare::OnRender(theRenderer);
    Smoke.OnRender(theRenderer);
}

void BounceCircle::OnCleanup()
{
    Smoke.OnCleanup();
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


