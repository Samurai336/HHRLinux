#ifndef CHIMNEYSMOKE_H
#define CHIMNEYSMOKE_H

#include "ParticleEngine.h"


namespace HHR_Particles
{
    using namespace HHR_Physics;

    class ChimneySmoke : public ParticleEngine
    {
        public:
            ChimneySmoke();
            ChimneySmoke(const char* texturesFiles[], unsigned int textureCount, const Vector3 &location, unsigned int EmittionVolume, unsigned int EmitionRate  );
            virtual void OnLoop();
            virtual void ResetParticle(Particle* particleToUpdate);
            void SetPositon(const Vector3 &newEmitterPosition);
            ~ChimneySmoke();

        private:
           virtual Particle* GenerateNewParticle();


    };
}

#endif // CHIMNEYSMOKE_H
