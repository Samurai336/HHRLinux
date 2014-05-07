#ifndef HHRUNIT_H
#define HHRUNIT_H

#include "BaseClasses/SpriteAnimation.h"

class HHRUnit : public SpriteAnimation
{
    public:
        HHRUnit();

        HHRUnit(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int newMaxHealth);

        virtual void OnLoop();

        virtual void OnRender(MainRender &theRenderer);

        int GetCurrentHealth() const;

        int GetMaxHealth() const;

        void SetMaxHealth(unsigned int newMaxHealth);

        void ModifyHealth(const int ChangeHealthBy) ;

        virtual void Kill();

        virtual void Reset();

    protected:
        unsigned int MaxHealth;
        int health;
        bool Living;
        HHR_Physics::Vector3 Velocity;


};



#endif // HHRUNIT_H
