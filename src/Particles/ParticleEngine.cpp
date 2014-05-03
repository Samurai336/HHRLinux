#include "ParticleEngine.h"



namespace HHR_Particles
{
    ParticleEngine::ParticleEngine()
    {
        Active = false;
        ActiveEmmitting =false;
    }

    ParticleEngine::ParticleEngine(const char *texturesFiles[], const unsigned int numTextures, const Vector3 &location)
    {
        srand (time(NULL));
        SetUpEngine(texturesFiles,numTextures,location);
    }

    bool ParticleEngine::SetUpEngine(const char *texturesFiles[], const unsigned int numTextures, const Vector3 &location)
    {
        emetterLocation = location;

        textures = new SDL_Texture* [numTextures];

        for(unsigned int i = 0; i < numTextures; ++i)
        {
             if((textures[i] =  MainApp::Instance()->GetMainRenderTarget()->LoadTexture(texturesFiles[i])) == NULL);
             {
                 return true;
             }
        }
        Active = false;
        ActiveEmmitting =false;

        return false;
    }

    void ParticleEngine::OnLoop()
    {
        if(ActiveEmmitting)
        {

            unsigned int totalDead = 0;

            if(particles.size() < totalParticleCap)
            {
                int total = 10;
                for(int i =0; i < total; i++)
                {
                    particles.push_back(GenerateNewParticle());
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
                        (*itor)->ParticleReset(emetterLocation);
                    }
                }
            }

            if(particles.size() == totalDead)
            {
                ActiveEmmitting = false ;
            }
        }

    }

    void ParticleEngine::OnRender(MainRender &theRenderer)
    {
        if(ActiveEmmitting)
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
        for(unsigned int i = 0; i < numTextures; ++i)
        {
            SDL_DestroyTexture(textures[i]);
        }

        delete [] textures ;

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

        return (new Particle (textures[rand()%(numTextures-1)],
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
