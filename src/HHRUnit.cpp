#include "HHRUnit.h"

HHRUnit::HHRUnit()
{
    health = 100;
    Living = true;
}

HHRUnit::HHRUnit(char *File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop)
{
    CreateAnimatedSprite(File, Columns, Rows,rate,Loop);
    health = 100;
    Living = true;
}

void HHRUnit::OnLoop()
{
    if(Living)
    {
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

int HHRUnit::GetHealth() const
{
    return health;
}

void HHRUnit::ModifyHealth(const int ChangeHealthBy)
{
    health += ChangeHealthBy;
}
