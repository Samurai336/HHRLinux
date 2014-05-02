#ifndef PARTICLE_H
#define PARTICLE_H

#include "../BaseClasses/BaseUnit.h"

namespace HHR_Particles
{
    using namespace HHR_Physics;

    class Particle:public BaseUnit
    {
        public:
            Particle(void);
            // public Particle(Texture2D texture, Vector2 position, Vector2 velocity, float angle, float angularVelocity, Color color, float size, int ttl, GraphicsDeviceManager graphics)
            Particle(SDL_Texture* ParticleTexture, Vector3 positon, Vector3 velocity, real angle, real AngularVelocity, SDL_Color color, real size, int ttl);
            void SetParticle(SDL_Texture* ParticleTexture, Vector3 positon, Vector3 velocity, real angle, real AngularVelocity, SDL_Color color, real size, int ttl);

            virtual void OnLoop();

            virtual void OnRender(MainRender &theRenderer);

            virtual void OnCleanup();

        private:
            Vector3 Velocity;
            real AngularVelocity;
            SDL_Color LColor;
            real Size;
            unsigned int duration;
            real orginalY;
            unsigned int AlphaChange;
            unsigned int Alpha;










    };

}

#endif // PARTICLE_H
