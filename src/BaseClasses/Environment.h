#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <SDL2/SDL.h> 


class Environment
{
    public:
        Environment();
        ~Environment();

        float X;
        float Y;

        int Width;
        int Height;

		virtual bool LoadEnvirement(char *File, SDL_Renderer* targetRenderer) {return true;}; 

		virtual void UpDate(){};

		virtual void Render(){};

		virtual void Cleanup(){};

		virtual void CheckCollision(){};


    protected:
        SDL_Texture* BackGroundImage;

    private:
};

#endif // ENVIRONMENT_H
