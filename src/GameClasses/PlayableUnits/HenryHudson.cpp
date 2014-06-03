#include "HenryHudson.h"

HenryHudson::HenryHudson():HHR_Player()
{


}

HenryHudson::HenryHudson(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth):
    HHR_Player(File,Columns,Rows,rate,Loop,MaxHealth)

{


}

bool HenryHudson::SetUpHHRPlayer(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth, const HHR_Physics::Vector3 &newMaxVelocity, const int newAcclerationRate, const int newVelocityDecay, const int newRotationRate, const int newMaxRotation)
{
     if(HHR_Player::SetUpHHRPlayer(File, Columns, Rows, rate, Loop, MaxHealth,  newMaxVelocity,  newAcclerationRate,  newVelocityDecay,  newRotationRate,newMaxRotation))
     {
         return true;
     }


     //HitBox.SetSize(size);
     //HitBox.setPostion(Position);
       HitBox.SetUpBox(Position,18,39,rotation);

    return false;
}



void HenryHudson::OnLoop()
{
    UpdateCollisionObj();
    Smoke.OnLoop();

    HHR_Player::OnLoop();
}

void HenryHudson::OnRender(MainRender &theRenderer)
{
    Smoke.OnRender(theRenderer);

#ifdef PHYSICS_DEBUG
    HitBox.OnRender(theRenderer);
#endif

    HHR_Player::OnRender(theRenderer);
}

void HenryHudson::OnKeyDown(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode)
{

    HHR_Player::OnKeyDown(sym,mod,unicode);
}

void HenryHudson::OnKeyUp(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode)
{

    HHR_Player::OnKeyUp(sym,mod,unicode);
}

void HenryHudson::OnCleanup()
{

    Smoke.OnCleanup();

    HHR_Player::OnCleanup();
}


HHR_Physics::OrientedBoundingBox2D HenryHudson::GetCollisionObject()
{
    return HitBox;
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
