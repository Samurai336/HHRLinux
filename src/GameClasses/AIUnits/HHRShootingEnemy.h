#ifndef HHRSHOOTINGENEMY_H
#define HHRSHOOTINGENEMY_H

#include "HHREnemy.h"

class HHRShootingEnemy : public HHREnemy
{
    public:
        HHRShootingEnemy();
        HHRShootingEnemy(HHRShootingEnemy &CopyClass);
        HHRShootingEnemy(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth = 100);
        bool SetHHRShootingEnemy(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth = 100);

        virtual void OnLoop();

        virtual void Kill();

        virtual void Reset();

        virtual void OnCleanup();

        ~HHRShootingEnemy();

     private:
        virtual void UpdateCollisionObj();

        void UpdateAnimationToHealth();

        void FireGun();

        BaseSound  GunSfx, bigBoomSfx;


};

#endif // HHRSHOOTINGENEMY_H
