#include "Particle.h"


namespace HHR_Particles
{
    Particle::Particle()
    {

    }

    Particle::Particle(SDL_Texture* ParticleTexture, const Vector3 &positon, const Vector3 &velocity, real angle, real AngularVelocity, SDL_Color color, real size, int ttl, int setRenderOrder)
    {
        SetParticle(ParticleTexture,positon,velocity,angle,AngularVelocity,color,size,ttl);
    }

    void Particle::SetParticle(SDL_Texture* ParticleTexture, const Vector3 &positon, const Vector3 &velocity, real angle, real AngularVelocity, SDL_Color color, real size, int ttl, int setRenderOrder)
    {
        unitTexture = ParticleTexture;
        Position = positon;
        this->Velocity = velocity;
        rotation = angle;
        AngularVelocity = AngularVelocity;
        LColor = color;
        Scale = size;
        duration = totalDuration = ttl;
        orginalY = positon.y;
        AlphaChange = 254/ttl;
        Alpha = 254;

        renderOrder = setRenderOrder;

        SDL_QueryTexture(unitTexture, NULL, NULL, &width, &height);

        Position.x += (width/2);
        Position.y += (height/2);
    }

    void Particle::ParticleReset()
    {
         duration = totalDuration;
         Alpha = 254;

#ifdef DEBUG_MODE
            printf("ParticlePostion X:%f, Y:%f\n", Position.x, Position.y);
#endif
    }

    int Particle::GetCurrentLifeDuration()
    {
        return duration;
    }

    void Particle::SetPositon(const Vector3 &newPositon)
    {
        Position = newPositon;
        Position.x -= (width/2);
        Position.y -= (height/2);
    }

    void Particle::SetVelocity(const Vector3 &newVelcity)
    {
        Velocity = newVelcity;
    }

    void Particle::OnLoop()
    {
        duration--;
        Position += Velocity;
        rotation += AngularVelocity;
        Alpha -= AlphaChange;

        if(Alpha <0)
        {
            Alpha = 0;
        }
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
