#include "MusicSound.h"

MusicSound::MusicSound()
{
    MusicAudio= NULL;
    looping = false;
}

MusicSound::MusicSound(char *File)
{
    MusicAudio= NULL;
    Load(File);
}

bool MusicSound::Load(char *File)
{

    if((MusicAudio=Mix_LoadMUS(File)) == NULL)
    {
#ifdef DEBUG_MODE
        printf("Mix_LoadMUS Error(%s): %s\n", File,Mix_GetError());
#endif
        return true;
    }

    return false;
}

void MusicSound::Play(int loopCount)
{

    if(Mix_PausedMusic())
    {
        Mix_ResumeMusic();
    }
    else
    {
        if(Mix_PlayMusic(MusicAudio, loopCount)==-1)
        {
    #ifdef DEBUG_MODE
                printf("Mix_LoadPlay Error: %s\n", Mix_GetError());
    #endif
        }

        if(loopCount == -1)
        {
            looping = true;
        }
    }
}

void MusicSound::Stop()
{
    Mix_HaltMusic();
    looping = false;
}

void MusicSound::Pause()
{
    Mix_PauseMusic();
}

bool MusicSound::IsLooping()
{
    return looping;
}


void MusicSound::OnCleanup()
{
    Mix_FreeMusic(MusicAudio);
    MusicAudio = NULL;

}

MusicSound::~MusicSound()
{
    OnCleanup();
}
