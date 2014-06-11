#include "HHR_Player.h"

HHR_Player::HHR_Player():HHRUnit()
{
    AccerlerationRate = 2;
    VelocityDecay = 2;
    MaxRotation = 45;
    rotationRate = 2;
    recivedInput = false;
    MaxVelocity = HHR_Physics::Vector3(10.0f,10.0f,0.0f);
}

bool HHR_Player::SetUpHHRPlayer(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth, const HHR_Physics::Vector3 &newMaxVelocity, const int newAcclerationRate, const int newVelocityDecay, const int newRotationRate, const int newMaxRotation)
{
    HHRUnit(File,Columns,Rows,rate,Loop,MaxHealth);
    HHR_Player();


    if(CreateAnimatedSprite(File, Columns, Rows,rate,Loop))
    {
        return true;
    }

    MaxVelocity = newMaxVelocity;
    AccerlerationRate = newAcclerationRate;
    VelocityDecay = newVelocityDecay;
    MaxRotation = newMaxRotation;
    rotationRate = newRotationRate;

    return false;
}

HHR_Player::HHR_Player(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop,const unsigned int MaxHealth):
    HHRUnit(File,Columns,Rows,rate,Loop,MaxHealth)
{
    HHR_Player();

}

void HHR_Player::OnLoop()
{

    UpdateVelocityDecay();

    recivedInput = false;

    HandleActiveKeys();

    HHRUnit::OnLoop();
}

void HHR_Player::OnRender(MainRender &theRenderer)
{

    HHRUnit::OnRender(theRenderer);
}

void HHR_Player::OnKeyDown(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode)
{
    if(sym == SDLK_w)
    {
        KeysActive.MoveForward = true;
    }
    if(sym == SDLK_s)
    {
        KeysActive.MoveBack = true;
    }

    if(sym == SDLK_a)
    {
        KeysActive.MoveLeft =true;
    }
    if(sym == SDLK_d)
    {
        KeysActive.MoveRight =true;
    }

    recivedInput = true;
}

void HHR_Player::OnKeyUp(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode)
{
    if(sym == SDLK_w)
    {
        KeysActive.MoveForward = false;
    }
    if(sym == SDLK_s)
    {
        KeysActive.MoveBack = false;
    }

    if(sym == SDLK_a)
    {
        KeysActive.MoveLeft =false;
    }
    if(sym == SDLK_d)
    {
        KeysActive.MoveRight =false;
    }

    recivedInput = false;
}

void HHR_Player::AccumulatePoints(const unsigned int newPoints)
{
    Points += newPoints;
}

unsigned int HHR_Player::CurrentPointCount() const
{
    return Points;
}

void HHR_Player::SetMaxVelocity(const HHR_Physics::Vector3 &newMaxVelocity)
{
    MaxVelocity = newMaxVelocity;
}

HHR_Physics::Vector3 HHR_Player::GetMaxVelocity() const
{
    return MaxVelocity;
}

void HHR_Player::SetAccelerationRate(const int NewAcceleration)
{
    AccerlerationRate = NewAcceleration;
}

int HHR_Player::GetCurrentAcclerationRate() const
{
    return AccerlerationRate;
}

void HHR_Player::SetVelocityDecay(const int newDecay)
{
    VelocityDecay = newDecay;
}

int HHR_Player::GetCurrentVelocityDecay() const
{
    return VelocityDecay;
}

void HHR_Player::SetMaxRotation(const int newRotationMax)
{
    MaxRotation = newRotationMax;
}

int HHR_Player::GetMaxRotation() const
{
    return MaxRotation;
}

void HHR_Player::SetRotationRate(const int newRotationRate)
{
    rotationRate =  newRotationRate;
}

int HHR_Player::GetRotationRate() const
{
    return rotationRate;
}

HHR_Player::~HHR_Player()
{

}

void HHR_Player::UpdateVelocityDecay()
{
    if(!KeysActive.MoveLeft && !KeysActive.MoveRight)
    {
        if(Velocity.x > 0 )
        {
            Velocity.x -= VelocityDecay;
        }
        else if(Velocity.x < 0 )
        {
            Velocity.x += VelocityDecay;
        }
        if(rotation != 0)
        {
            if(rotation> 0)
            {
                rotation -= rotationRate;
            }
            else
            {
                rotation += rotationRate;
            }
        }
    }

    if(!KeysActive.MoveBack && !KeysActive.MoveForward)
    {
        if(Velocity.y > 0 )
        {
            Velocity.y -= VelocityDecay;
        }
        else if(Velocity.y < 0 )
        {
            Velocity.y += VelocityDecay;
        }


    }


}

void HHR_Player::CheckCurrentVelocityCap()
{

    if(Velocity.x > MaxVelocity.x)
    {
        Velocity.x = MaxVelocity.x;
    }
    else if (Velocity.x < -MaxVelocity.x)
    {
        Velocity.x = -MaxVelocity.x;
    }

    if(Velocity.y > MaxVelocity.y)
    {
        Velocity.y = MaxVelocity.y;
    }
    else if (Velocity.y < -MaxVelocity.y)
    {
        Velocity.y = -MaxVelocity.y;
    }
}

void HHR_Player::UpdateRotation(int Direction)
{
    rotation += (Direction);

    if(rotation >= MaxRotation)
    {
        rotation = MaxRotation;
    }
    else if (rotation <= -MaxRotation)
    {
        rotation = -MaxRotation;
    }

    
}

void HHR_Player::HandleActiveKeys()
{
        if(KeysActive.MoveForward)
        {
            Velocity.y -= AccerlerationRate;
        }
        else if(KeysActive.MoveBack)
        {
            Velocity.y += AccerlerationRate;
        }

        if(KeysActive.MoveLeft)
        {
            Velocity.x -= 2;
            UpdateRotation(-rotationRate);

        }
        else if(KeysActive.MoveRight)
        {
            Velocity.x += 2;
            UpdateRotation(rotationRate);

        }



        CheckCurrentVelocityCap();
    
}

