#include "ParticleEngine.h"


#include "../MainApp.h"



namespace HHR_Particles
{
    ParticleEngine::ParticleEngine()
    {
        Active = false;
        ActiveEmmitting =false;
        CapHit= false;
    }

    ParticleEngine::ParticleEngine(const char *texturesFiles[], const unsigned int numTextures, const Vector3 &location, unsigned int EmittionVolume, unsigned int EmitionRate)
    {        
        srand (time(NULL));
        SetUpEngine(texturesFiles,numTextures,location, EmittionVolume, EmitionRate);
    }

    bool ParticleEngine::SetUpEngine(const char *texturesFiles[], const unsigned int numTextures, const Vector3 &location, unsigned int EmittionVolume, unsigned int EmitionRate )
    {
        emetterLocation = location;

        textures = new SDL_Texture* [numTextures];

        for(unsigned int i = 0; i < numTextures; ++i)
        {

             if((textures[i]= MainApp::Instance()->GetMainRenderTarget()->LoadTexture(texturesFiles[i])) == NULL)
             {
#ifdef DEBUG_MODE
                 printf("IMG_Load Error: Particle Asset(%s): %s\n",texturesFiles[i], IMG_GetError());
#endif
                 return true;
             }
        }
        Active = false;
        ActiveEmmitting =false;
        textureCount = numTextures;
        emmitionVolume= EmittionVolume;
        Rate= EmitionRate;
        CapHit= false;


        return false;
    }

    void ParticleEngine::OnLoop()
    {
        if(ActiveEmmitting || Active)
        {

            unsigned int totalDead = 0;

            if(!CapHit)
            {
                if(SDL_GetTicks() > (LastUpDate + Rate))
                {
                    LastUpDate = SDL_GetTicks();
                    for(int i =0; i < emmitionVolume; i++)
                    {
                        particles.push_back(GenerateNewParticle());
                    }
                }
            }

            std::list<Particle*>::iterator itor = particles.begin();
            for(; itor != particles.end(); ++itor)
            {
                (*itor)->OnLoop();

                if((*itor)->duration <= 0)
                {
                    ++totalDead;
                    if(Active == true)
                    {
                       CapHit= true;
                       ResetParticle((*itor));
                    }
                }
            }

            if(particles.size() == totalDead)
            {
                ActiveEmmitting = false ;
            }
        }

    }

    void ParticleEngine::ResetParticle(Particle *particleToUpdate)
    {
        particleToUpdate->Position = emetterLocation;
    }


    void ParticleEngine::OnRender(MainRender &theRenderer)
    {
        if(ActiveEmmitting || Active)
        {
            std::list<Particle*>::iterator itor = particles.begin();

            for(; itor != particles.end(); ++itor)
            {
                (*itor)->OnRender(theRenderer);
            }
        }
    }

    void ParticleEngine::OnCleanup()
    {
        particles.remove_if(deleteAll);
        for(unsigned int i = 0; i < textureCount; ++i)
        {
            SDL_DestroyTexture(textures[i]);
        }

        //Is this a memory leak?
        //Barfs when I leave it in.
        //delete [] textures ;


    }

    void ParticleEngine::SetRate(Uint32 newEmmitionRate)
    {
        Rate = newEmmitionRate;

    }

    bool ParticleEngine::GetActiveStatus() const
    {
        return Active;
    }

    void ParticleEngine::SetActive(const bool activeStatus)
    {
        if(activeStatus ==true)
        {
            ActiveEmmitting = Active = activeStatus;

        }
        else
        {
            Active = false;
        }
    }

    ParticleEngine::~ParticleEngine()
    {
        OnCleanup();
    }

    Particle *ParticleEngine::GenerateNewParticle()
    {
        SDL_Color particleColor= {rand()%255+1,rand()%255+1,rand()%255+1};

        return (new Particle (textures[rand()%(textureCount)],
                              emetterLocation,
                              Vector3(1.0f * (float)(rand()*2.0f-1.0f),1.0f * (float)(rand()*2.0f-1.0f),0.0f),
                              0.0f,
                              (1.0f * (float)(rand()*2-1)),
                              particleColor,
                              rand(),
                              (unsigned int)(rand()%40+1)
                              ));
    }

}
