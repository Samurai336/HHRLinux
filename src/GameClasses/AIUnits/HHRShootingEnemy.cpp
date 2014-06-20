#include "HHRShootingEnemy.h"

HHRShootingEnemy::HHRShootingEnemy()
{
    Velocity = HHR_Physics::Vector3(0.0f,0.0f,0.0f);

    Position = HHR_Physics::Vector3(50.0f,350.0f,2.0f);


    HHR_Physics::Vector3 size(56.0f,115.0f,0.0f);
    CollisionBox.SetSize(size);

    RunDeathSequence= false;
}

HHRShootingEnemy::HHRShootingEnemy(HHRShootingEnemy &CopyClass):HHREnemy(CopyClass)
{

     GunSfx = CopyClass.GunSfx;
     bigBoomSfx = CopyClass.bigBoomSfx;
}

HHRShootingEnemy::HHRShootingEnemy(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth)
{
    SetHHRShootingEnemy(File,Columns,Rows,rate,Loop,MaxHealth);
}

bool HHRShootingEnemy::SetHHRShootingEnemy(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth)
{
    HHRShootingEnemy();
    HHRUnit(File,Columns,Rows,rate,Loop,MaxHealth);

    if(CreateAnimatedSprite(File, Columns, Rows,rate,Loop))
    {
#ifdef DEBUG_MODE
        printf("Error In loading Shooting Enemy Animation!\n");
#endif
        return true;
    }


    explodeSfx.Load("Assets/Audio/sfx/51429__smcameron__volcano_eruption.wav");
    GunSfx.Load("Assets/Audio/sfx/51465_smcameron_flak_gun_sound.wav");
}

void HHRShootingEnemy::OnLoop()
{
    if(health<=0)
    {
        if(Living)
        {
            if(RunDeathSequence == false)
            {
                RunDeathSequence = true;
                explodeSfx.Play();
                StopAnimating();
                SetColumnPosition(1);
                SetRowPosition(3);
                StartAnimating();
                SetLoop(false);

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
        UpdateAnimationToHealth();

    }

    HHRUnit::OnLoop();

}

void HHRShootingEnemy::Kill()
{
    StopAnimating();
    HHREnemy::Kill();
}

void HHRShootingEnemy::Reset()
{
    HHRUnit::Reset();

    SetColumnPosition(1);
    SetRowPosition(2);
    SetLoop(true);
    StartAnimating();

}

void HHRShootingEnemy::OnCleanup()
{
    HHREnemy::OnCleanup();
    GunSfx.OnCleanup();
}

void HHRShootingEnemy::UpdateCollisionObj()
{
    BoxOffest = GetAnimationCenter();

    BoxOffest.x -= (CollisionBox.GetWidth()*0.5f)-17;

    BoxOffest.y -= ((CollisionBox.GetHeight())*0.5f)-23;

    CollisionBox.setPostion(BoxOffest);
}

void HHRShootingEnemy::UpdateAnimationToHealth()
{
    if(health > ((int)MaxHealth/2))
    {
        SetRowPosition(1);
    }
    else if (health < ((int)MaxHealth/2))
    {
        SetRowPosition(2);
    }
}

HHRShootingEnemy::~HHRShootingEnemy()
{

}

void HHRShootingEnemy::FireGun()
{
    GunSfx.Play();
}
