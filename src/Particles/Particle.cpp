#include "Particle.h"


namespace HHR_Particles
{
    Particle::Particle()
    {
    }

    Particle::Particle(SDL_Texture *ParticleTexture, Vector3 positon, Vector3 velocity, real angle, real AngularVelocity, SDL_Color color, real size, int ttl)
    {
        SetParticle(ParticleTexture,positon,velocity,angle,AngularVelocity,color,size,ttl);
    }

    void Particle::SetParticle(SDL_Texture *ParticleTexture, Vector3 positon, Vector3 velocity, real angle, real AngularVelocity, SDL_Color color, real size, int ttl)
    {
        unitTexture = ParticleTexture;
        Position = positon;
        this->Velocity = velocity;
        rotation = angle;
        AngularVelocity = AngularVelocity;
        LColor = color;
        Size = size;
        duration = ttl;
        orginalY = positon.y;
        AlphaChange = 256/ttl;
        Alpha = 256;


        SDL_QueryTexture(unitTexture, NULL, NULL, &width, &height);
    }

    void Particle::OnLoop()
    {
        duration--;
        Position += Velocity;
        rotation += AngularVelocity;
        Alpha -= AlphaChange;
    }

    void Particle::OnRender(MainRender &theRenderer)
    {
        SDL_SetTextureAlphaMod(unitTexture, Alpha);

        BaseUnit::OnRender(theRenderer);
    }

    void Particle::OnCleanup()
    {
        BaseUnit::OnCleanup();
    }
}
