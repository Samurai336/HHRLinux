#ifndef PARTICLE_H
#define PARTICLE_H

#include "../BaseClasses/BaseUnit.h"

namespace HHR_Particles
{
    using namespace HHR_Physics;

    class Particle:public BaseUnit
    {
        friend class ParticleEngine;

        public:
            Particle(void);
            // public Particle(Texture2D texture, Vector2 position, Vector2 velocity, float angle, float angularVelocity, Color color, float size, int ttl, GraphicsDeviceManager graphics)
            Particle(SDL_Texture* ParticleTexture, const Vector3 &positon, const Vector3 &velocity, real angle, real AngularVelocity, SDL_Color color, real size, int ttl);
            void SetParticle(SDL_Texture* ParticleTexture, const Vector3 &positon, const Vector3 &velocity, real angle, real AngularVelocity, SDL_Color color, real size, int ttl);          

            int GetCurrentLifeDuration();

            void SetPositon(const Vector3 &newPositon);

            void SetVelocity(const Vector3 &newVelcity);

            virtual void OnLoop();

            virtual void ParticleReset();

            virtual void OnRender(MainRender &theRenderer);

            virtual void OnCleanup();

        private:

            Vector3 Velocity;
            real AngularVelocity;
            SDL_Color LColor;            
            int duration;
            unsigned int totalDuration;
            real orginalY;
            int AlphaChange;
            int Alpha;










    };

}

#endif // PARTICLE_H
