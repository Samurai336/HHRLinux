#ifndef CANNONSMOKEPARTICLESYSTEM_H
#define CANNONSMOKEPARTICLESYSTEM_H


#include "ParticleEngine.h"



namespace HHR_Particles
{

    enum HorizontalDirection
    {
        Left = 0,
        Right,
        enumTypeEnd
    };

    class CannonSmokeParticleSystem : public ParticleEngine
    {
        public:
            CannonSmokeParticleSystem();
            //(List<Texture2D> textures, Vector2 location, GraphicsDeviceManager graphics, Game1 game): base(textures, location, graphics)
            CannonSmokeParticleSystem(const char* texturesFiles[], unsigned int textureCount, const Vector3 &location,  unsigned int EmittionVolume, unsigned int EmitionRate , int SetDuration = 0 );
            bool SetUpEngine(const char* texturesFiles[], unsigned int textureCount, const Vector3 &location,  unsigned int EmittionVolume, unsigned int EmitionRate ,  int SetDuration = 0);
            void SetDuration(int NewDur);

            void StartCannonSmoke(const HorizontalDirection newDirection, const Vector3 &newPosition, const Vector3 &currentEmitterSpeed);

            virtual void OnLoop();
            virtual void ResetParticle(Particle* particleToUpdate);
            virtual void OnRender(MainRender &theRenderer);
            virtual void OnCleanup();


            ~CannonSmokeParticleSystem();


        private:
            virtual Particle* GenerateNewParticle();
            Vector3 emitterSpeed;
            HorizontalDirection smokeDirection;
            int duration;
            int durationCountDown;

    };
}
#endif // CANNONSMOKEPARTICLESYSTEM_H
