#include "CannonSmokeParticleSystem.h"




namespace HHR_Particles
{
    CannonSmokeParticleSystem::CannonSmokeParticleSystem()
    {

    }
    CannonSmokeParticleSystem::CannonSmokeParticleSystem(const char *texturesFiles[], unsigned int numTextures, const Vector3 &location,  unsigned int EmittionVolume, unsigned int EmitionRate , int SetDuration)
    {
        SetUpEngine(texturesFiles,numTextures,location, EmittionVolume, EmitionRate,SetDuration);
    }

    bool CannonSmokeParticleSystem::SetUpEngine(const char *texturesFiles[], unsigned int numTextures, const Vector3 &location, unsigned int EmittionVolume, unsigned int EmitionRate , int SetDuration)
    {
        srand (time(NULL));

        if(ParticleEngine::SetUpEngine(texturesFiles,numTextures,location,EmittionVolume, EmitionRate) == true)
        {
            return true;
        }

        duration = SetDuration;
        durationCountDown = 0;
        //emmitionBurstCount = 10;

        return false;
    }

    void CannonSmokeParticleSystem::SetDuration(int NewDur)
    {
        duration = NewDur;
    }


    void CannonSmokeParticleSystem::StartCannonSmoke(const HorizontalDirection newDirection, const Vector3 &newPosition, const Vector3 &currentEmitterSpeed)
    {


        emitterSpeed = currentEmitterSpeed;
        emetterLocation = newPosition;
        smokeDirection = newDirection;
        durationCountDown = duration;
        SetActive(true);
    }

    void CannonSmokeParticleSystem::OnLoop()
    {

        durationCountDown -= 1;
        if (durationCountDown > 0)
        {
            Active = true;
            ActiveEmmitting = true;
        }
        else
        {
            Active = false;
        }

        ParticleEngine::OnLoop();
    }

    void CannonSmokeParticleSystem::ResetParticle(Particle *particleToUpdate)
    {
        Vector3 particleVelocity;
        if(smokeDirection == Left)
        {
            particleVelocity = Vector3((-5.0f - emitterSpeed.x), (RandomReal(1.0f,1.5f) + (emitterSpeed.y/2.0f)),0.0f);
        }
        else if (smokeDirection == Right)
        {
            particleVelocity = Vector3((5.0f + emitterSpeed.x), (RandomReal(1.0f,1.5f) + (emitterSpeed.y/2.0f)),0.0f);
        }

        particleToUpdate->SetPosition(emetterLocation);
        particleToUpdate->SetVelocity(particleVelocity);
        particleToUpdate->ParticleReset();
    }

    void CannonSmokeParticleSystem::OnRender(MainRender &theRenderer)
    {
        ParticleEngine::OnRender(theRenderer);
    }

    void CannonSmokeParticleSystem::OnCleanup()
    {
        ParticleEngine::OnCleanup();
    }

    CannonSmokeParticleSystem::~CannonSmokeParticleSystem()
    {
        ParticleEngine::OnCleanup();
    }

    Particle *CannonSmokeParticleSystem::GenerateNewParticle()
    {
        SDL_Color particleColor= {255,255,255};
        Vector3 particleVelocity;

        if(smokeDirection == Left)
        {
            particleVelocity = Vector3((-5.0f + emitterSpeed.x), (RandomReal(1.0f,2.0f) + (emitterSpeed.y/2.0f)),0.0f);
        }
        else if (smokeDirection == Right)
        {
            particleVelocity = Vector3((5.0f + emitterSpeed.x), (RandomReal(1.0f,2.0f) + (emitterSpeed.y/2.0f)),0.0f);
        }

        int RandomTextureIndex = rand() % (textureCount);

        return (new Particle (textures[RandomTextureIndex],
                              emetterLocation,
                              particleVelocity,//Vector3(1.0f * (float)(rand()*2.0f-1.0f),1.0f * (float)(rand()*2.0f-1.0f),0.0f),
                              0.0f,
                              RandomReal(1.0f,2.0f),
                              particleColor,
                              RandomReal(0.25f,0.5f),
                              (rand()%40+1),
                              45
                              ));


    }




}
