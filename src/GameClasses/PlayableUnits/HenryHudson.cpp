#include "HenryHudson.h"

HenryHudson::HenryHudson():HHR_Player()
{
    FireRestTime = 1000;
    CoolDownLeft = CoolDownRight = 0;


}

HenryHudson::HenryHudson(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth):
    HHR_Player(File,Columns,Rows,rate,Loop,MaxHealth)

{
    HenryHudson();

}

void HenryHudson::SetCoolDownTime(uint32_t newCoolTime)
{
    FireRestTime = newCoolTime;
}

uint32_t HenryHudson::GetCoolDownTime()
{
    return FireRestTime;
}

bool HenryHudson::SetUpHHRPlayer(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth, const HHR_Physics::Vector3 &newMaxVelocity, const int newAcclerationRate, const int newVelocityDecay, const int newRotationRate, const int newMaxRotation)
{
     if(HHR_Player::SetUpHHRPlayer(File, Columns, Rows, rate, Loop, MaxHealth,  newMaxVelocity,  newAcclerationRate,  newVelocityDecay,  newRotationRate,newMaxRotation))
     {
         return true;
     }

     const char *ParticleAsset[] ={"Assets/cannonSmoke.png"} ;

     SmokeLeft.SetUpEngine(ParticleAsset,1,GetAnimationCenter(),10, 15, 5);
     SmokeRight.SetUpEngine(ParticleAsset,1,GetAnimationCenter(),10, 15, 5);
      CannonFire.FireLeft = false;
      CannonFire.FireRight = false;






     //HitBox.SetSize(size);
     //HitBox.setPostion(Position);
     HitBox.SetUpBox(Position,18,39,rotation);


     cannonSfx.Load("Assets/Audio/sfx/33380__DJ_Chronos__Boom.wav");


    return false;
}



void HenryHudson::OnLoop()
{    
    SmokeRight.OnLoop();
    SmokeLeft.OnLoop();
    UpdateCollisionObj();
    UpdateCannons();

    HHR_Player::OnLoop();
}

void HenryHudson::OnRender(MainRender &theRenderer)
{
    //Smoke.OnRender(theRenderer);
    SmokeRight.OnRender(theRenderer);
    SmokeLeft.OnRender(theRenderer);

#ifdef PHYSICS_DEBUG
    HitBox.OnRender(theRenderer);
#endif

    HHR_Player::OnRender(theRenderer);
}

void HenryHudson::OnKeyDown(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode)
{
    if(sym == SDLK_LEFT)
    {
        CannonFire.FireLeft = true;
    }

    if(sym == SDLK_RIGHT)
    {
        CannonFire.FireRight = true;
    }

    HHR_Player::OnKeyDown(sym,mod,unicode);
}

void HenryHudson::OnKeyUp(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode)
{
    if(sym == SDLK_LEFT)
    {
        CannonFire.FireLeft = false;
    }

    if(sym == SDLK_RIGHT)
    {
        CannonFire.FireRight = false;
    }

    HHR_Player::OnKeyUp(sym,mod,unicode);
}

void HenryHudson::OnCleanup()
{    
    SmokeRight.OnCleanup();
    SmokeLeft.OnCleanup();

    HHR_Player::OnCleanup();
}


HHR_Physics::OrientedBoundingBox2D HenryHudson::GetCollisionObject()
{
    return HitBox;
}

void HenryHudson::UpdateCannons()
{
    uint32_t ticks = SDL_GetTicks();

    if(CannonFire.FireLeft == true)
    {
        if(CoolDownLeft< ticks)
        {
#ifdef DEBUG_MODE
            //printf("HenryLocation X:%f, Y:%f\n", GetAnimationCenter().x, GetAnimationCenter().y);
#endif
            cannonSfx.Play();
            CoolDownLeft = (SDL_GetTicks() + FireRestTime);
            SmokeLeft.StartCannonSmoke(HHR_Particles::Left, GetAnimationCenter(),Velocity);


        }
    }

    if(CannonFire.FireRight == true)
    {
        if(CoolDownRight< ticks)
        {
#ifdef DEBUG_MODE
            //printf("HenryLocation X:%f, Y:%f\n", GetAnimationCenter().x, GetAnimationCenter().y);
#endif
            cannonSfx.Play();
            CoolDownRight = (SDL_GetTicks() + FireRestTime);
            SmokeRight.StartCannonSmoke(HHR_Particles::Right, GetAnimationCenter(),Velocity);

        }
    }

}

//This should be optimized
void HenryHudson::UpdateCollisionObj()
{
    BoxOffest = GetAnimationCenter();
    BoxOffest.x -= (HitBox.GetWidth()*0.5)-0.5 ;
    BoxOffest.y -= (HitBox.GetHeight()*0.5) - 3 ;

    HitBox.moveTo(BoxOffest, rotation);
    //HitBox.setPostion(Position);
}
