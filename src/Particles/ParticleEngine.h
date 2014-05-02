#ifndef PARTICLEENGINE_H
#define PARTICLEENGINE_H

#include "Particle.h"
#include "../MainApp.h"
#include <time.h>
#include <list>

namespace HHR_Particles
{
    using namespace HHR_Physics;

    class ParticleEngine
    {
        public:
            ParticleEngine();
            //ParticleEngine(List<Texture2D> textures, Vector2 location, GraphicsDeviceManager graphics)
            ParticleEngine(const char* texturesFiles[], unsigned int numTextures, const Vector3 &location );
            bool SetUpEngine(const char* texturesFiles[], unsigned int numTextures, const Vector3 &location);
            void OnLoop();
            void OnRender(MainRender &theRenderer);
            void OnCleanup();
            ~ParticleEngine();



        private:
            Particle* GenerateNewParticle();
            Vector3 emetterLocation;
            unsigned int numTextures;
            int totalParticles;
            std::list <Particle*> particles;
            SDL_Texture** textures;
            static bool deleteAll( Particle * theElement ) { delete theElement; return true; }



    };
}

#endif // PARTICLEENGINE_H
