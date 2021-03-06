#ifndef HHRENEMY_H
#define HHRENEMY_H

#include "../BaseGameClasses/HHRUnit.h"
#include "../../Audio/BaseSound.h"

class HHREnemy : public HHRUnit
{
    public:
        HHREnemy();
        HHREnemy(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth = 100);
        bool SetUpHHREnemy(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth = 100);

        virtual void OnLoop();

        virtual void Kill();

        virtual void Reset();

        virtual void OnRender(MainRender &theRenderer);

        virtual HHR_Physics::BoundingBox GetCollisionObject() ;

        virtual void OnCleanup();

        ~HHREnemy();

     protected:
        bool RunDeathSequence;
        HHR_Physics::Vector3 BoxOffest;
        HHR_Physics::BoundingBox CollisionBox;
        BaseSound  explodeSfx;


        virtual void UpdateCollisionObj();


};

#endif // HHRENEMY_H
