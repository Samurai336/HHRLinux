#ifndef HENRYHUDSON_H
#define HENRYHUDSON_H


#include "../BaseGameClasses/HHR_Player.h"
#include "../../Particles/CannonSmokeParticleSystem.h"
#include "../../Physics/CollisionObjects.h"


class HenryHudson : public HHR_Player
{
    public:
        HenryHudson();
        HenryHudson(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned int MaxHealth = 100);

        virtual bool SetUpHHRPlayer(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop,
                            const unsigned int MaxHealth = 100,
                            const HHR_Physics::Vector3 &newMaxVelocity = HHR_Physics::Vector3(2.0f,2.0f,0.0f),
                            const int newAcclerationRate=1,
                            const int newVelocityDecay = 1,
                            const int newRotationRate = 2,
                            const int newMaxRotation  = 30);

        virtual void OnLoop();

        virtual void OnRender(MainRender &theRenderer);

        virtual void OnKeyDown(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode);

        virtual void OnKeyUp(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode);

        virtual void OnCleanup();

        virtual HHR_Physics::OrientedBoundingBox2D GetCollisionObject() ;

   private:
         virtual void UpdateCollisionObj();
         HHR_Particles::CannonSmokeParticleSystem Smoke;
         HHR_Physics::OrientedBoundingBox2D HitBox;
         HHR_Physics::Vector3 BoxOffest;



};


#endif // HENRYHUDSON_H
