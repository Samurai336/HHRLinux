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
            ParticleEngine(const char* texturesFiles[], unsigned int textureCount, const Vector3 &location, unsigned int EmittionVolume, unsigned int EmitionRate );
            bool SetUpEngine(const char* texturesFiles[], unsigned int textureCount, const Vector3 &location, unsigned int EmittionVolume, unsigned int EmitionRate);
            virtual void OnLoop();
            virtual void ResetParticle(Particle* particleToUpdate);
            virtual void OnRender(MainRender &theRenderer);
            virtual void OnCleanup();
             void SetRate(Uint32);
            bool GetActiveStatus() const;
            void SetActive(const bool activeStatus);
            void setRenderOrder(int newRenderOrder) { renderOrder = newRenderOrder; }

            ~ParticleEngine();



        protected:
            bool Active;
            bool ActiveEmmitting;
            bool CapHit;
            int renderOrder;
            uint32_t LastUpDate;
            uint32_t Rate;
            int emmitionVolume;
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
