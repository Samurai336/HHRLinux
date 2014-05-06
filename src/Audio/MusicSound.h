#ifndef MUSICSOUND_H
#define MUSICSOUND_H

#ifdef APPLE
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

#include "../Define.h"
//Base class as a simple wraper
//for the SDL mixer


class MusicSound
{
public:
    MusicSound();
    MusicSound(char* File);
    virtual bool Load(char* File);
    void Play(int loopCount = -1);
    void Stop();
    void Pause();

    virtual void OnCleanup();
    virtual ~MusicSound();

    bool IsLooping();
protected:
    Mix_Music *MusicAudio;
private:
    bool looping;

};

#endif // MUSICSOUND_H
