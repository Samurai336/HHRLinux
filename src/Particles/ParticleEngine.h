#ifndef PARTICLEENGINE_H
#define PARTICLEENGINE_H

#include <SDL2/SDL.h>
#include "../Renderer/MainRender.h"
#include "Particle.h"
#include <list>


class MainRender;

namespace HHR_Particles
{
    using namespace HHR_Physics;


    class ParticleEngine
    {
        public:
            ParticleEngine();
            //ParticleEngine(List<Texture2D> textures, Vector2 location, GraphicsDeviceManager graphics)
            ParticleEngine(const char* texturesFiles[], unsigned int textureCount, const Vector3 &location, unsigned int ParticleCap );
            bool SetUpEngine(const char* texturesFiles[], unsigned int textureCount, const Vector3 &location, unsigned int ParticleCap );
            virtual void OnLoop();
            virtual void ResetParticle(Particle* particleToUpdate);
            virtual void OnRender(MainRender &theRenderer);
            virtual void OnCleanup();
            bool GetActiveStatus() const;
            void SetActive(const bool activeStatus);

            ~ParticleEngine();



        protected:
            bool Active;
            bool ActiveEmmitting;
            virtual Particle* GenerateNewParticle();
            Vector3 emetterLocation;
            unsigned int textureCount;
            unsigned int totalParticleCap;
            std::list <Particle*> particles;
            SDL_Texture** textures;
            static bool deleteAll( Particle * theElement ) { delete theElement; return true; }



    };
}

#endif // PARTICLEENGINE_H
