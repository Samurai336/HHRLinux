#ifndef HHRUNIT_H
#define HHRUNIT_H

#include "BaseClasses/SpriteAnimation.h"

class HHRUnit : public SpriteAnimation
{
    public:
        HHRUnit();

        HHRUnit(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop);

        virtual void OnLoop();

        virtual void OnRender(MainRender &theRenderer);

        int GetHealth() const;

        void ModifyHealth(const int ChangeHealthBy) ;


    protected:
        int health;
        bool Living;
        HHR_Physics::Vector3 Velocity;


};



#endif // HHRUNIT_H
