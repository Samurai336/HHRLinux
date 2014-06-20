#include "HHRUnit.h"
#include "../../MainApp.h"

HHRUnit::HHRUnit()
{
    health = MaxHealth = 100;
    Living = true;
}

HHRUnit::HHRUnit(HHRUnit &copyClass):SpriteAnimation(copyClass)
{

   MaxHealth = copyClass.MaxHealth;

    health = copyClass.health;
    Living = copyClass.Living;
    Velocity = copyClass.Velocity;
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
        Position += (Velocity*MainApp::Instance()->GetMainRenderTarget()->FrameRateControl.GetGameSpeed()) ;
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

bool HHRUnit::IsLiving()
{
    return Living;
}

void HHRUnit::SetMaxHealth(unsigned int newMaxHealth)
{
    MaxHealth= newMaxHealth;
}

void HHRUnit::ModifyHealth(const int ChangeHealthBy)
{
    health += ChangeHealthBy;

    if(health > (int)MaxHealth)
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
