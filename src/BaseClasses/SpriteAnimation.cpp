/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of Henry Hudson's Revenge. A Cross Platform project,      **
**  also Known as HHR_X and referd to as such thoughout.						**
**  																			**
**  HHR_X is free software: you can redistribute it and/or modify			  	**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  HHR_X is distributed in the hope that it will be useful,					**
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with HHR_X.  If not, see <http://www.gnu.org/licenses/>.			  	**
**  																			**
**********************************************************************************/






#include "SpriteAnimation.h"





SpriteAnimation::SpriteAnimation(void)
{
    BaseUnit();

    numberOfColumns = 0;
    numberOfRows = 0;
    Rate = 0;
    currrentRow = 1;
    currentColumn = 1;
    loop = false;
    AnimationPlaying= false;


    Sprite_Rect.x = Sprite_Rect.y = Sprite_Rect.h = Sprite_Rect.w = 0;

    //ctor
}

SpriteAnimation::SpriteAnimation(SpriteAnimation &copyClass):BaseUnit(copyClass)
{


    Sprite_Rect = copyClass.Sprite_Rect;
    numberOfColumns = copyClass.numberOfColumns;
    numberOfRows = copyClass.numberOfRows;
    LastUpDate = copyClass.LastUpDate;
    Rate = copyClass.Rate;
    currrentRow = copyClass.currrentRow;
    currentColumn = copyClass.currentColumn;
    loop = copyClass.loop;
    AnimationPlaying = copyClass.AnimationPlaying;
    AnimationCenter = copyClass.AnimationCenter;



}


SpriteAnimation::SpriteAnimation(char* File, unsigned int Columns, unsigned int Rows, Uint32 rate, bool Loop):
    numberOfColumns(Columns), numberOfRows(Rows), Rate(rate)
{
    BaseUnit();

    BaseUnit::Load(File);


    currrentRow = 0;
    currentColumn = 0;
    loop = Loop;

    CalculateSpriteSize();
}

bool SpriteAnimation::CreateAnimatedSprite(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop)
{

    bool loadStatus = BaseUnit::Load(File);
    if(loadStatus);
    {

        numberOfColumns = Columns;
        numberOfRows = Rows;
        Rate = rate;
        currrentRow = 1;
        currentColumn = 1;
        loop = Loop;

        CalculateSpriteSize();

        LastUpDate = SDL_GetTicks();

        return loadStatus;
    }



    return loadStatus;



}

void SpriteAnimation::SetRate(Uint32 newRate)
{
    Rate = newRate;
}

void SpriteAnimation::SetLoop(bool Loop)
{
    this->loop = Loop;
}

void SpriteAnimation::SetNumberRow(unsigned int rowNumber)
{
    numberOfRows = rowNumber;
    CalculateSpriteSize();
}

void SpriteAnimation::SetNumberColumn(unsigned int columnNumber)
{
    numberOfColumns = columnNumber;

    CalculateSpriteSize();
}

void SpriteAnimation::CalculateSpriteSize()
{
    Sprite_Rect.x = Sprite_Rect.y = Sprite_Rect.h = Sprite_Rect.w = 0;

    Sprite_Rect.w = width/numberOfColumns;
    Sprite_Rect.h = height/ numberOfRows;

}

void SpriteAnimation::OnLoop()
{


    if(AnimationPlaying)
    {
        if(SDL_GetTicks() > (LastUpDate + Rate))
        {
            LastUpDate = SDL_GetTicks();

            Sprite_Rect.x = (currentColumn-1) * Sprite_Rect.w;
            Sprite_Rect.y = (currrentRow-1) * Sprite_Rect.h;

            if(loop)
            {
                if(currentColumn >= numberOfColumns)
                {
                    currentColumn = 1;

                }
                else
                {
                    currentColumn++;


                }
            }
            else
            {
                if(currentColumn != numberOfColumns)
                {
                    currentColumn++;
                }
                else
                {
                    AnimationPlaying = false;
                }
            }
        }
    }


}

void SpriteAnimation::SetPosition(float MoveX, float MoveY)
{
    Position.x  = MoveX - (Sprite_Rect.w/2);
    Position.y  = MoveY - (Sprite_Rect.h/2);
}

void SpriteAnimation::SetPosition(const HHR_Physics::Vector3 newPosition)
{
    Position.x  = newPosition.x - (Sprite_Rect.w/2);
    Position.y  = newPosition.y - (Sprite_Rect.h/2);
}



void SpriteAnimation::OnRender(MainRender	&theRenderer)
{
    theRenderer.Draw(this->unitTexture, Position.x , Position.y , Sprite_Rect,rotation,Scale,renderOrder);
}



void SpriteAnimation::OnCleanup()
{

    BaseUnit::OnCleanup();

}

void SpriteAnimation::StartAnimating()
{
    AnimationPlaying = true;
}

void SpriteAnimation::StopAnimating()
{
    AnimationPlaying = false;
}



SpriteAnimation::~SpriteAnimation()
{
    //dtor
}

void SpriteAnimation::SetColumnPosition(unsigned int Position)
{
    currentColumn = Position;
    Sprite_Rect.x = (currentColumn-1) * Sprite_Rect.w;
}

void SpriteAnimation::SetRowPosition(unsigned int Position)
{
    currrentRow = Position;
    Sprite_Rect.y = (currrentRow-1) * Sprite_Rect.h;

}

HHR_Physics::Vector3 SpriteAnimation::GetAnimationCenter()
{
    //X+((W * scale)/2);
    //Y+((H * scale)/2);

    AnimationCenter = Position;
    AnimationCenter.x = (Position.x + ((Sprite_Rect.w * Scale)));
    AnimationCenter.y = (Position.y + ((Sprite_Rect.h * Scale)));

    return AnimationCenter;
}

bool SpriteAnimation::AnimationIsPlaying() const
{
    return AnimationPlaying;
}

