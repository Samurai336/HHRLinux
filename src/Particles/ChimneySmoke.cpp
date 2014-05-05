#include "ChimneySmoke.h"

namespace HHR_Particles
{


    ChimneySmoke::ChimneySmoke()
    {
    }

    ChimneySmoke::ChimneySmoke(const char *texturesFiles[], unsigned int textureCount, const Vector3 &location,  unsigned int EmittionVolume, unsigned int EmitionRate )
    {
        SetUpEngine(texturesFiles,textureCount,location,EmittionVolume, EmitionRate);
    }

    void ChimneySmoke::OnLoop()
    {
        ParticleEngine::OnLoop();
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
                               Vector3(RandomReal(-0.15f,0.15f),-0.75f,0.0f),//Vector3(1.0f * (float)(rand()*2.0f-1.0f),1.0f * (float)(rand()*2.0f-1.0f),0.0f),
                               0.0f,
                               RandomReal(1.0f,2.0f),
                               particleColor,
                               0.25,
                               65
                               ));



        //return NULL;
    }


}
