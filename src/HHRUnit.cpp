#include "HHRUnit.h"

HHRUnit::HHRUnit()
{
    health = 100;
    Living = true;
}

HHRUnit::HHRUnit(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int newMaxHealth)
{
    CreateAnimatedSprite(File, Columns, Rows,rate,Loop);
    health = 100;
    Living = true;
    MaxHealth = newMaxHealth;
}

void HHRUnit::OnLoop()
{
    if(Living)
    {
        Position += Velocity;
        SpriteAnimation::OnLoop();
    }
}

void HHRUnit::OnRender(MainRender &theRenderer)
{
    if(Living)
    {
        SpriteAnimation::OnRender(theRenderer);
    }
}

int HHRUnit::GetCurrentHealth() const
{
    return health;
}

int HHRUnit::GetMaxHealth() const
{
    return MaxHealth;
}

void HHRUnit::SetMaxHealth(unsigned int newMaxHealth)
{
    MaxHealth= newMaxHealth;
}

void HHRUnit::ModifyHealth(const int ChangeHealthBy)
{
    health += ChangeHealthBy;

    if(MaxHealth < health)
    {
        health = MaxHealth;
    }
}

void HHRUnit::Kill()
{
    health = 0;
    Living = false;
}

void HHRUnit::Reset()
{
    health = MaxHealth;
    Living = true;
}
