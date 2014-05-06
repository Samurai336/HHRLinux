#include "BaseSound.h"
/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of SDL2_Pong.                                    			**
**  																			**
**  SDL2_Pong is free software: you can redistribute it and/or modify			**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  SDL2_Pong is distributed in the hope that it will be useful,			    **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with SDL2_Pong.  If not, see <http://www.gnu.org/licenses/>.			**
**  																			**
**********************************************************************************/


//Set our varables to default or Null
BaseSound::BaseSound()
{
    SoundFile = NULL;
    loop = false;
    loopCount = 0;
    //ctor
}

//consrtuctor for loading a sound file
BaseSound::BaseSound(char* File)
{
    SoundFile = NULL;

    Load(File);
    //ctor
}


//Load a sound file.
bool BaseSound::Load(char* File)
{
    //Return false since the load failed
	
    (SoundFile = Mix_LoadWAV(File));
    if(!SoundFile)
    {
#ifdef DEBUG_MODE
        printf("Mix_Load_WAV Error(%s): %s\n", File,Mix_GetError());
#endif
        return true;
    }


    loop = false;
    loopCount = 0;
    return false;

}

//remove sound file when we are done
void BaseSound::OnCleanup()
{
    Mix_FreeChunk(SoundFile);
}

// use channel
void BaseSound::Play()
{
    //-1 means use any channel
    //sound file to play
    //loop 0 times (-1 means forever);


    if(loop)
    {
        if(Mix_PlayChannel(-1, SoundFile, loopCount))
        {
#ifdef DEBUG_MODE
            printf("Mix_PlayChannel: %s\n",Mix_GetError());
            // may be critical error, or maybe just no channels were free.
            // you could allocated another channel in that case...
#endif
        }
        ;
    }
    else
    {

        if(Mix_PlayChannel(-1, SoundFile, loopCount))
        {
#ifdef DEBUG_MODE
            printf("Mix_PlayChannel: %s\n",Mix_GetError());
            // may be critical error, or maybe just no channels were free.
            // you could allocated another channel in that case...
#endif
        }
    }

}

void BaseSound::SetLoop(bool shouldLoop,  int newLoopCount)
{
    loop = shouldLoop;
    loopCount = newLoopCount;
}



BaseSound::~BaseSound()
{
    //dtor
}
