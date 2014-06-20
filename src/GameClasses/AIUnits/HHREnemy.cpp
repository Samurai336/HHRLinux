#include "HHREnemy.h"

HHREnemy::HHREnemy():HHRUnit()
{

    Velocity = HHR_Physics::Vector3(0.0f,0.0f,0.0f);

    Position = HHR_Physics::Vector3(50.0f,50.0f,2.0f);

    HHR_Physics::Vector3 size(30.0f,45.0f,0.0f);
    CollisionBox.SetSize( size);

    RunDeathSequence= false;
}

HHREnemy::HHREnemy(HHREnemy &CopyClass):HHRUnit(CopyClass)
{

    RunDeathSequence = CopyClass.RunDeathSequence;
    BoxOffest = CopyClass.BoxOffest;
    CollisionBox = HHR_Physics::BoundingBox(CopyClass.CollisionBox);
    explodeSfx = CopyClass.explodeSfx;
}

HHREnemy::HHREnemy(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth)
{
    SetUpHHREnemy(File,Columns,Rows,rate,Loop,MaxHealth);

}

bool HHREnemy::SetUpHHREnemy(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth)
{
    HHRUnit(File,Columns,Rows,rate,Loop,MaxHealth);
    HHREnemy();

    if(CreateAnimatedSprite(File, Columns, Rows,rate,Loop))
    {
#ifdef DEBUG_MODE
        printf("Error In loading Enemy Animation!\n");
#endif
        return true;
    }

    explodeSfx.Load("Assets/Audio/sfx/51427_smcameron_synthetic_bomb.wav");

    return false;
}

void HHREnemy::OnLoop()
{
    if(health<=0)
    {
        if(Living)
        {
            if(RunDeathSequence == false)
            {
                RunDeathSequence = true;
                explodeSfx.Play();
                StartAnimating();
            }
            else if(AnimationIsPlaying() == false)
            {
                RunDeathSequence = false;
                Kill();
            }

        }
    }
    else
    {
        UpdateCollisionObj();
    }

    HHRUnit::OnLoop();

}

void HHREnemy::Kill()
{
    HHRUnit::Kill();
}

void HHREnemy::Reset()
{
    SetColumnPosition(1);

    HHRUnit::Reset();

}

void HHREnemy::OnRender(MainRender &theRenderer)
{


#ifdef PHYSICS_DEBUG
    CollisionBox.OnRender(theRenderer);
#endif

    HHRUnit::OnRender(theRenderer);
}

HHR_Physics::BoundingBox HHREnemy::GetCollisionObject()
{
    return CollisionBox;
}

void HHREnemy::OnCleanup()
{
    explodeSfx.OnCleanup();
}

HHREnemy::~HHREnemy()
{

}

void HHREnemy::UpdateCollisionObj()
{
    BoxOffest = GetAnimationCenter();

    BoxOffest.x -= (CollisionBox.GetWidth()*0.5f)-2;

    BoxOffest.y -= ((CollisionBox.GetHeight())*0.5f) - 7 ;

    CollisionBox.setPostion(BoxOffest);
}
