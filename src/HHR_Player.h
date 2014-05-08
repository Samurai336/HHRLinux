#ifndef HHR_PLAYER_H
#define HHR_PLAYER_H

#include "HHRUnit.h"
#include "BaseClasses/Events.h"


struct ActiveKeys
{
   bool W;
   bool A;
   bool S;
   bool D;
   bool Left;
   bool Right;

};

class HHR_Player: public HHRUnit, public Events
{
    public:
        HHR_Player();

        HHR_Player(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop, const unsigned intMaxHealth = 100);

        bool SetUpHHRPlayer(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop,
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

        void AccumulatePoints(const unsigned int newPoints);

        unsigned int CurrentPointCount() const;

        void SetMaxVelocity(const HHR_Physics::Vector3 &newMaxVelocity);

        HHR_Physics::Vector3 GetMaxVelocity() const;

        void SetAccelerationRate(const int NewAcceleration);

        int GetCurrentAcclerationRate() const;

        void SetVelocityDecay(const int newDecay);

        int GetCurrentVelocityDecay() const;

        void SetMaxRotation(const int newRotationMax);

        int GetMaxRotation() const;

        void SetRotationRate(const int newRotationRate);

        int GetRotationRate() const;

        ~HHR_Player();

   private:
        void UpdateVelocityDecay();
        void CheckCurrentVelocityCap();
        void UpdateRotation(int Direction);
        void HandleActiveKeys(); 
        unsigned int Points;
        int AccerlerationRate;
        int VelocityDecay;
        int MaxRotation;
        int rotationRate;
        bool recivedInput;
        ActiveKeys KeysActive;

        
        HHR_Physics::Vector3 MaxVelocity;


};

#endif // HHR_PLAYER_H
