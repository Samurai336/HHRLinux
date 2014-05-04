#include "ChimneySmoke.h"

namespace HHR_Particles
{


    ChimneySmoke::ChimneySmoke()
    {
    }

    ChimneySmoke::ChimneySmoke(const char *texturesFiles[], unsigned int textureCount, const Vector3 &location, unsigned int ParticleCap)
    {
        SetUpEngine(texturesFiles,textureCount,location,ParticleCap);
        //emmitionBurstCount = 120;
        //Rate = 500;
    }


    void ChimneySmoke::ResetParticle(Particle *particleToUpdate)
    {
        particleToUpdate->SetPosition(emetterLocation);
        particleToUpdate->ParticleReset();
    }

    void ChimneySmoke::SetPositon(const Vector3 &newEmitterPosition)
    {
        emetterLocation = newEmitterPosition;
    }


    ChimneySmoke::~ChimneySmoke()
    {
        ParticleEngine::OnCleanup();
    }

    Particle *ChimneySmoke::GenerateNewParticle()
    {
         SDL_Color particleColor= {255,255,255};

         int RandomTextureIndex = rand() % (textureCount);

         return (new Particle (textures[RandomTextureIndex],
                               emetterLocation,
                               Vector3(RandomReal(1.0f,2.0f),-2.0f,0.0f),//Vector3(1.0f * (float)(rand()*2.0f-1.0f),1.0f * (float)(rand()*2.0f-1.0f),0.0f),
                               0.0f,
                               RandomReal(1.0f,2.0f),
                               particleColor,
                               0.25,
                               60
                               ));



        //return NULL;
    }


}
